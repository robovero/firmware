#!/usr/bin/env python

import os, subprocess, sys, time, os, platform, json

arch = platform.machine()
debug = open("debug.log", "w")
ESC = chr(27)

try:
	config_file = open("flashconfig")
except:
	exit("\n"
	"ERROR: flashconfig not found. try:\n"
	"  $ cp flashconfig.sample flashconfig\n"
	"  set OPENOCD_PATH and GDB_PATH in flashconfig and retry.\n")

try:
	config = json.load(config_file)
except:
	exit("\n"
	"ERROR: invalid flashconfig")


print "getting sudo password"
sudo_cmd = "sudo echo".split()
if subprocess.call(sudo_cmd):
	raw_input("error: wrong password")
	exit(1)


print "starting openocd:",
openocd_cmd = ("sudo %sopenocd -f interface/ftdi/openocd-usb.cfg -f target/lpc1769.cfg" % config["OPENOCD_PATH"]).split()
openocd = subprocess.Popen(openocd_cmd, stdout=debug, stderr=debug)
time.sleep(1)
openocd.poll()
while openocd.returncode == 1:
	print "jtag not detected. retrying"
	openocd = subprocess.Popen(openocd_cmd, stdout=debug, stderr=debug)
	time.sleep(1)
	openocd.poll()
print "jtag chain detected"


print "gdb runtime: 0s",
sys.stdout.flush()
gdb_cmd = ("%sarm-bare_newlib_cortex_m3_nommu-eabi-gdb -x .gdbflash firmware" % config["GDB_PATH"]).split()
gdb = subprocess.Popen(gdb_cmd, stdout=debug, stderr=debug)
elapsed = 0
while gdb.returncode == None:
	gdb.poll()
	if elapsed > 120:
		sys.stdout.write("\r" + ESC + "[2K")
		sys.stdout.write("gdb runtime: timeout")
		sys.stdout.flush()
		gdb.terminate()
		gdb.returncode = 1
		break
	time.sleep(1)
	elapsed += 1
	sys.stdout.write("\r" + ESC + "[2K")
	sys.stdout.write("gdb runtime: %ds" % elapsed)
	sys.stdout.flush()
print ""

"closing openocd. flash", 
kill_openocd_cmd = ("sudo kill %d" % openocd.pid).split()
subprocess.call(kill_openocd_cmd)
if gdb.returncode:
	raw_input("failed. please try again")
	exit(1)
else:
	print "succeeded"
		

raw_input("done. ")	
