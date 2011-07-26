SOURCES := \
  $(wildcard src/wrap/*.c) \
  $(wildcard src/usb/*.c) \
  $(wildcard src/*.c) \

OBJECTS := \
  $(patsubst %.c,%.o,$(wildcard src/wrap/*.c)) \
  $(patsubst %.c,%.o,$(wildcard src/usb/*.c)) \
  $(patsubst %.c,%.o,$(wildcard src/*.c)) \

DEPS := \
  $(patsubst %.c,%.d,$(wildcard src/wrap/*.c)) \
  $(patsubst %.c,%.d,$(wildcard src/usb/*.c)) \
  $(patsubst %.c,%.d,$(wildcard src/*.c)) \

C_SRCS := $(SOURCES)
OBJS := $(OBJECTS)
C_DEPS := $(DEPS) 
LIBS := -lDriversLPC17xxgnu -lgcc -lc

src/wrap/%.o: src/wrap/%.c
src/usb/%.o: src/usb/%.c
src/%.o: src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	arm-bare_newlib_cortex_m3_nommu-eabi-gcc -DARM_MATH_CM3 -D__BUILD_WITH_EXAMPLE__=1 -D__RAM_MODE__=0 -D__thumb2__=1 -I"${HOME}/robovero/firmware/include" -I"${HOME}/robovero/firmware/include/core" -I"${HOME}/robovero/firmware/include/drivers" -I"${HOME}/robovero/firmware/include/dsp" -I"${HOME}/robovero/firmware/include/usb" -I"${HOME}/robovero/firmware/include/wrap" -I${HOME}/cortex-m3/arm-bare_newlib_cortex_m3_nommu-eabi/arm-bare_newlib_cortex_m3_nommu-eabi/include -I${HOME}/cortex-m3/arm-bare_newlib_cortex_m3_nommu-eabi/lib/gcc/arm-bare_newlib_cortex_m3_nommu-eabi/4.4.1/include -O0 -g -Wall -mthumb -mcpu=cortex-m3 -c -ffunction-sections -fdata-sections -MD -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

# All Target
all: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	arm-bare_newlib_cortex_m3_nommu-eabi-ld -nostdlib -L"${HOME}/robovero/firmware/lib" -Map=firmware.map -T "${HOME}/robovero/firmware/script.ld"  --gc-sections -o"firmware" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-rm -rf $(OBJS)$(EXECUTABLES)$(C_DEPS) firmware firmware.bin firmware.map
	-@echo ' '

post-build:
	-arm-bare_newlib_cortex_m3_nommu-eabi-objcopy -O binary firmware firmware.bin
	-@echo ' '
	-md5sum firmware > md5sum.txt
	-git log -1 --pretty=oneline > commit-id.txt
	
flash:
	-make
	-./flash.py
