/*
   This robovero sample program is licensed under the simplified BSD license:

   Copyright 2012, Andrew Gottemoller
   All rights reserved.

   Redistribution and use in source and binary forms, with or without modification,
   are permitted provided that the following conditions are met:

   Redistributions of source code must retain the above copyright notice, this list of
   conditions and the following disclaimer:

   Redistributions in binary form must reproduce the above copyright notice, this list
   of conditions and the following disclaimer in the documentation and/or other materials
   provided with the distribution.

   Neither the name Andrew Gottemoller nor the names of its contributors may be used to
   endorse or promote products derived from this software without specific prior written
   permission.
*/

/*
   This is a simple program to connect to a robovero and read from the sensors 60 times
   before disconnecting and exiting.  A sleep for 2 seconds is added after each sensor
   read so the data is readable in real time.

   If compiling for BSD, use:
       gcc -std=c99 robocomm.c -o robocomm

   If compiling for Linux, use:
       gcc -std=c99 -D_XOPEN_SOURCE=700 -D_BSD_SOURCE robocomm.c -o robocomm

   Run with (note device name may not be the same): ./robocomm /dev/ttyACM0

   This code assumes the robovero sensor patch has been applied to the robovero firmware,
   which can be found here: http://www.agottem.com/robovero_sensors
 */

#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <time.h>
#include <poll.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


/*
   I don't like this function.  Sometimes the robovero will 'drop' commands
   if you transmit them too fast.  I suspect the serial buffer on the
   robovero is overflowing and dropping data.  The 'fix' is to sleep after
   each command transmission.

   A 1 millisecond sleep feels about right.  Feel free to try and tweak it
   though.

   If you find a better solution, please let me know!
 */
static inline void WaitForRobovero (void)
{
    struct timespec timeout;

    timeout.tv_sec  = 0;
    timeout.tv_nsec = 1000000;

    nanosleep(&timeout, NULL);
}

/*
   If a command results in data being sent back to the host, we can approximate
   the amount of time it'll take.  The serial link communicates at 115200bps.

   So, the following equation approximates the wait time:

   wait time = (bytes to receive) * (bits per byte) * (nanoseconds per second / 115200)
 */
static inline void WaitForReception (size_t bytes)
{
    struct timespec timeout;
    long            ns_timeout;

    ns_timeout = bytes*8*(1000000000/115200);

    timeout.tv_sec  = ns_timeout/1000000000;
    timeout.tv_nsec = ns_timeout%1000000000;

    nanosleep(&timeout, NULL);
}

/*
   Used to transmit a command to the robovero.  Note the WaitForRobovero at
   the end of this function.  This waits for the robovero to process the
   command prior to sending the next one.  If you find a better solution
   please let me know :-)
 */
static inline void TransmitCommand (char* command, int serial_if)
{
    size_t command_length;

    command_length = strlen(command);
    while(command_length > 0)
    {
        int data_written;

        data_written = write(serial_if, command, command_length);
        if(data_written == -1)
        {
            if(errno == EAGAIN)
                tcdrain(serial_if);
            else
            {
                printf("Write failure\n");

                exit(-1);
            }

            continue;
        }

        command        += data_written;
        command_length -= data_written;
    }

    WaitForRobovero();
}

/*
   Receive an integer value from the robovero.  The integer value can be up
   to 4 bytes in length, so an unsigned long is the appropriate type.

   The data format expected is:
       XXXXXXXX\r\n

   The \r is actually ignored, so it's optional, but the serial port was
   opened with out any new-line translation and untranslated robovero
   responses will always have a \r before the \n.

   Where X is a hex digit.  Any number of digits prior to the new line is
   valid.
 */
static inline unsigned long ReceiveULong (int serial_if)
{
    struct pollfd poll_data;
    unsigned long received_value;
    int           signaled_count;

    poll_data.fd     = serial_if;
    poll_data.events = POLLIN;

    signaled_count = poll(&poll_data, 1, 1000);
    if(signaled_count == 0)
    {
        printf("It has taken an unreasonable amount of time to receive data\n");

        exit(-1);
    }

    received_value = 0;

    while(1)
    {
        int  read_size;
        char read_value;

        read_size = read(serial_if, &read_value, 1);
        if(read_size == -1)
        {
            printf("Error reading from serial port\n");

            exit(-1);
        }
        else if(read_size == 0)
        {
            WaitForReception(1);

            continue;
        }

        if(read_value >= '0' && read_value <= '9')
            received_value = received_value*16+(read_value-'0');
        else if(read_value >= 'a' && read_value <= 'f')
            received_value = received_value*16+(read_value-'a'+10);
        else if(read_value >= 'A' && read_value <= 'F')
            received_value = received_value*16+(read_value-'A'+10);
        else if(read_value == '\n')
            break;
        else if(read_value != '\r')
        {
            printf("Unexpected data received\n");

            exit(-1);
        }
    }

    return received_value;
}


int main (int argc, char* argv[])
{
    struct termios if_mode;
    char*          robovero_dev;
    int            serial_if;
    int            error;

    if(argc < 2)
    {
        printf(
               "Syntax is: robocomm [device file]\n"
               "Example: robocomm /dev/ttyACM0\n"
              );

        return -1;
    }


    robovero_dev = argv[1];

    serial_if = open(robovero_dev, O_RDWR|O_NOCTTY|O_NDELAY);
    if(serial_if == -1)
    {
        printf("Couldn't open device file: %s\n", robovero_dev);

        return -1;
    }

    /*
       Configure the serial device to something suitable for the robovero
     */
    tcgetattr(serial_if, &if_mode);

    if_mode.c_cflag     = CS8|CREAD;
    if_mode.c_iflag     = 0;
    if_mode.c_lflag     = 0;
    if_mode.c_oflag     = 0;
    if_mode.c_cc[VMIN]  = 0;
    if_mode.c_cc[VTIME] = 0;

    cfsetispeed(&if_mode, B115200);
    cfsetospeed(&if_mode, B115200);

    error = tcsetattr(serial_if, TCSANOW, &if_mode);
    if(error != 0)
    {
        printf("Error setting serial attributes\n");

        return -1;
    }

    /*
       The first command sent to the robovero must be a newline character.
       This let's the robovero know what sort of line ending to expect
       (\n, or \r\n, etc.)
     */
    TransmitCommand("\n", serial_if);

    /*
       promptOff prevents the robovero from sending the [:)] or [:(] after
       each command.
     */
    TransmitCommand("promptOff\n", serial_if);

    /*
       resetConfig disables all peripherals on the robovero.
     */
    TransmitCommand("resetConfig\n", serial_if);

    /*
       roboveroConfig sets the default robovero configuration.
     */
    TransmitCommand("roboveroConfig\n", serial_if);

    /*
       When the robovero starts up and as it's configured it'll write
       to the serial port.  We don't care about any of this output, so
       wait a reasonable period of time and flush it.  The time we
       wait is computed based on an approximate number of bytes we
       expect -- 512.
     */
    WaitForReception(512);

    /*
       Flush the input buffer.
     */
    tcflush(serial_if, TCIFLUSH);

    /*
       Configure the sensors -- NOTE all parameters are in hex, NOT decimal
     */
    TransmitCommand("configAccel 1 1 1 1 32 4\n", serial_if);
    TransmitCommand("configMag 1 0 96 19\n", serial_if);
    TransmitCommand("configGyro 1 1 1 1  64 fa\n", serial_if);

    //for(unsigned int data_point_count = 60; data_point_count-- > 0;)
while(1)
    {
        double x_axis;
        double y_axis;
        double z_axis;

        TransmitCommand("readAccel\n", serial_if);

        x_axis = ((double)ReceiveULong(serial_if)-32768.0)/(double)(32768/4);
        y_axis = ((double)ReceiveULong(serial_if)-32768.0)/(double)(32768/4);
        z_axis = ((double)ReceiveULong(serial_if)-32768.0)/(double)(32768/4);

        printf("Accel:\t%.3f\t%.3f\t%.3f\n", x_axis, y_axis, z_axis);

        TransmitCommand("readMag\n", serial_if);

        x_axis = ((double)ReceiveULong(serial_if)-4096)/(double)(4096/0x19);
        y_axis = ((double)ReceiveULong(serial_if)-4096)/(double)(4096/0x19);
        z_axis = ((double)ReceiveULong(serial_if)-4096)/(double)(4096/0x19);

        printf("Mag:\t%.3f\t%.3f\t%.3f\n", x_axis, y_axis, z_axis);

        TransmitCommand("readGyro\n", serial_if);

        x_axis = ((double)ReceiveULong(serial_if)-32768)/(double)(32768/0xFA);
        y_axis = ((double)ReceiveULong(serial_if)-32768)/(double)(32768/0xFA);
        z_axis = ((double)ReceiveULong(serial_if)-32768)/(double)(32768/0xFA);

        printf("Gyro:\t%.3f\t%.3f\t%.3f\n", x_axis, y_axis, z_axis);

        usleep(100000);//100ms
    }

    printf("Test complete\n");

    /*
       Good practice to put the robovero back into its default configuration and flush the
       input buffer prior to closing the interface
     */
    TransmitCommand("resetConfig\n", serial_if);
    TransmitCommand("roboveroConfig\n", serial_if);

    WaitForReception(512);

    tcflush(serial_if, TCIFLUSH);

    close(serial_if);

    return 0;
}
