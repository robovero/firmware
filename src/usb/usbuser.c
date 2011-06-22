/*----------------------------------------------------------------------------
 *      U S B  -  K e r n e l
 *----------------------------------------------------------------------------
 * Name:    usbuser.c
 * Purpose: USB Custom User Module
 * Version: V1.20
 *----------------------------------------------------------------------------
 *      This software is supplied "AS IS" without any warranties, express,
 *      implied or statutory, including but not limited to the implied
 *      warranties of fitness for purpose, satisfactory quality and
 *      noninfringement. Keil extends you a royalty-free right to reproduce
 *      and distribute executable files created using this software for use
 *      on NXP Semiconductors LPC family microcontroller devices only. Nothing
 *      else gives you the right to use this software.
 *
 * Copyright (c) 2009 Keil - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include "lpc_types.h"

#include "table.h"		    /* to access the function table */
#include "return.h"
#include "ringbuffer.h"		/* to construct usb buffers */


static RingBuffer usb_out = {
	.wrIdx = 0,
	.rdIdx = 0,
};

static RingBuffer usb_in = {
	.wrIdx = 0,
	.rdIdx = 0,
};

static char line_term[3] = "";
static int line_term_len = 0;

const uint8_t robovero[] =
"\r\n"
/*"               ____    __________    ____   ___  __\r\n"
"              /\r\n"
"   __________/_________________________  ____   __ \r\n"
"  /  ) /  ) /  ) /  ) | / /__) /  ) /  )\r\n"
" /____(__/_(__/_(__/__|/_(____/____(__/___ __  _\r\n"*/
"RoboVero Command Line Interface\r\n"
"Copyright (C) 2011 Gumstix Inc.\r\n"
"\r\n"
"\r\n"
"press enter to begin...\r\n";


/*
 *  USB Reset Event Callback
 *   Called automatically on USB Reset Event
 */

void USB_Reset_Event (void) {
  USB_ResetCore();
}


/*
 *  USB Suspend Event Callback
 *   Called automatically on USB Suspend Event
 */

#if USB_SUSPEND_EVENT
void USB_Suspend_Event (void) {
}
#endif


/*
 *  USB Resume Event Callback
 *   Called automatically on USB Resume Event
 */

#if USB_RESUME_EVENT
void USB_Resume_Event (void) {
}
#endif

/*
 *  USB Set Configuration Event Callback
 *   Called automatically on USB Set Configuration Request
 */
void USB_Configure_Event (void) {
	if (USB_Configuration) {                  /* Check if USB is configured */
		writeUSBOutString((uint8_t *) robovero);
	}
}


#define P_EP(n) ((USB_EP_EVENT & (1 << (n))) ? USB_EndPoint##n : NULL)

/* USB Endpoint Events Callback Pointers */
void (* const USB_P_EP[16]) (uint32_t event) = {
  P_EP(0),
  P_EP(1),
  P_EP(2),
  P_EP(3),
  P_EP(4),
  P_EP(5),
  P_EP(6),
  P_EP(7),
  P_EP(8),
  P_EP(9),
  P_EP(10),
  P_EP(11),
  P_EP(12),
  P_EP(13),
  P_EP(14),
  P_EP(15),
};


/*
 *  USB Endpoint 1 Event Callback
 *   Called automatically on USB Endpoint 1 Event
 *    Parameter:       event
 */

void USB_EndPoint1 (uint32_t event) {
  uint16_t temp;
  static uint16_t serialState;

  switch (event) {
    case USB_EVT_IN:
      temp = CDC_GetSerialState();
      if (serialState != temp) {
         serialState = temp;
         CDC_NotificationIn();            /* send SERIAL_STATE notification */
      }
      break;
    default:
    	while(1);
  }
}

/*
 *  USB Endpoint 2 Event Callback
 *   Called automatically on USB Endpoint 2 Event
 *    Parameter:       event
 */

void USB_EndPoint2 (uint32_t event) {
	switch (event) {
		/*
		 * data received from host
		 */
		case USB_EVT_OUT:
			receiveUSB();
			break;

		/*
		 * data was sent to host
		 */
		case USB_EVT_IN:
			/*
			 * is there more data to send?
			 */
			transmitUSB();
			break;

		default:
			while(1);
	}
}

/*
 *  USB Endpoint 3 Event Callback
 *   Called automatically on USB Endpoint 3 Event
 *    Parameter:       event
 */

void USB_EndPoint3 (uint32_t event)
{
//	switch (event)
//	{
//		case USB_EVT_OUT:
//			MSC_BulkOut();
//			break;
//		case USB_EVT_IN:
//			MSC_BulkIn();
//			break;
//	}
}



int writeUSBOutString(uint8_t * str)
{
	int i = 0;

	while (str[i])
	{
		/*
		 * enque fails if buffer is full so transmit data
		 * and try again
		 */
		if (ringBufferEnque(&usb_out, str[i]))
		{
			transmitUSB();
			continue;
		}
		i++;
	}
	/*
	 * transmit everything
	 */
	transmitUSB();
	return i;
}

int writeUSBOut(uint8_t * data, int count)
{
	int i = 0;

	while (i < count)
	{
		if (ringBufferEnque(&usb_out, data[i]))
		{
			transmitUSB();
			continue;
		}
		i++;
	}
	transmitUSB();
	return i;
}

void transmitUSB(void)
{
	int bytesWritten, bytesAvailable;
	uint8_t * read_ptr;

	read_ptr = usb_out.data + usb_out.rdIdx;
	bytesAvailable = ringBufferContigUsed(&usb_out);
	bytesAvailable = (bytesAvailable > USB_CDC_BUFSIZE ?  USB_CDC_BUFSIZE : bytesAvailable);

	if (bytesAvailable)
	{
		bytesWritten = USB_WriteEP(CDC_DEP_IN, read_ptr, bytesAvailable);
		usb_out.rdIdx += bytesWritten;
		usb_out.rdIdx %= BUFFER_SIZE;
	}
}

/*
 * array of possible line termination sequences
 */
const char * line_terms[] = {
	"\r\n",
	"\r",
	"\n"
};

#define KB_BS		127
#define ESC_BS		"\e[D \e[D"

/*
 * copy data from usb into a ring buffer for parsing
 */
void receiveUSB(void)
{
	int numBytesRead, i;
	uint8_t tmp[USB_CDC_BUFSIZE + 1];

	/*
	 * copy the data to a local buffer
	 */
	numBytesRead = USB_ReadEP(CDC_DEP_OUT, tmp);
	//tmp[numBytesRead] = 0;

	/*
	 * determine line termination before starting console
	 */
	if (!line_term_len) {
		for (i = 0; i < 3; i++)
		{
			if (strstr((char *)tmp, line_terms[i]))
			{
				strcpy(line_term, line_terms[i]);
				line_term_len = strlen(line_terms[i]);
				writeUSBOutString((uint8_t *) "\r\n");
				writeUSBOutString((uint8_t *) "[:)] ");
				break;
			}
		}
		return;
	}

	for (i = 0; i < numBytesRead; i++)
	{
		/*
		 * backspace
		 */
		if (tmp[i] == KB_BS)
		{
			if (!ringBufferDeEnque(&usb_in))
				writeUSBOutString((uint8_t *) ESC_BS);
		}

		/*
		 * command
		 * FIXME: this will compare to invalid data
		 */
		else if (!memcmp(&tmp[i], line_term, line_term_len))
		{
			i += line_term_len - 1;

			/*
			 * disallow empty strings
			 */
			if (usb_in.wrIdx == 0)
				continue;

			if (prompt_on)
				writeUSBOutString((uint8_t *) "\r\n");

			/*
			 * null terminate and execute the command
			 */
			ringBufferEnque(&usb_in, 0);
			processCmd(usb_in.data);
			usb_in.wrIdx = 0;

		}

		/*
		 * escape character
		 */
		else if (tmp[i] == '\e')
		{
			if (prompt_on)
				writeUSBOutString((uint8_t *) "esc-");
			ringBufferEnque(&usb_in, 'e');
			ringBufferEnque(&usb_in, 's');
			ringBufferEnque(&usb_in, 'c');
			ringBufferEnque(&usb_in, '-');
		}

		/*
		 * printable characters
		 */
		else if (tmp[i] > 31 && tmp[i] < 127)
		{
			if (prompt_on)
				writeUSBOut(&tmp[i], 1);
			ringBufferEnque(&usb_in, tmp[i]);
		}
	}
}



int notHex(uint8_t x)
{
	if (x < 48)
		return TRUE;
	else if (x < 58)
		return FALSE;
	else if (x < 65)
		return TRUE;
	else if (x < 71)
		return FALSE;
	else if (x < 97)
		return TRUE;
	else if (x < 102)
		return FALSE;
	else
		return TRUE;
}

int findIndex(uint8_t * name)
{
	int i;

	/*
	 * search for an exact match
	 */
	for (i = 1; i < driver_table_len; i++)
	{
		if (strcmp((char *) name, (char *) driver_table[i].fcn_name) == 0)
		{
			return i;
		}
	}
	return 0;
}

void processCmd(uint8_t * cmd)
{
	uint8_t * fcn;
	int (*fcn_ptr)(uint8_t *);
	unsigned long int fcn_index = 0;
	int i;

	/*
	 * get the first argument sent
	 */
	fcn = (uint8_t *) strtok((char *)cmd, " ");

	/*
	 * if there are any non-hex characters
	 * then search function names
	 */
	for (i = 0; i < strlen((char *)fcn); i++)
	{
		if (notHex(fcn[i]))
		{
			fcn_index = findIndex(fcn);
			if (!fcn_index)
			{
				ret = _search(fcn);
				if (prompt_on)
				{
					if (ret)
						writeUSBOutString((uint8_t *) "[:(] ");
					else
						writeUSBOutString((uint8_t *) "[:)] ");
					return;
				}
			}
		}
	}

	/*
	 * convert hex string to integer
	 */
	if (!fcn_index)
		fcn_index = strtoul((char *) fcn, NULL, 16);

	/*
	 * an invalid numerical value was provided
	 */
	if (fcn_index == 0 || fcn_index >= driver_table_len)
	{
		if (prompt_on)
			writeUSBOutString((uint8_t *) "[:(] ");
		return;
	}

	/*
	 * get the function pointer from the table
	 */
	fcn_ptr = driver_table[fcn_index].fcn_ptr;

	/*
	 * call the requested function
	 */
	ret = fcn_ptr(cmd + strlen((char *) cmd) + 1);
	if (prompt_on)
	{
		if (ret)
			writeUSBOutString((uint8_t *) "[:(] ");
		else
			writeUSBOutString((uint8_t *) "[:)] ");
	}
}

