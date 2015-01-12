SOURCES := \
  $(wildcard src/dsp/*.s) \
  $(wildcard src/wrap/*.c) \
  $(wildcard src/usb/*.c) \
  $(wildcard src/*.c) \

OBJECTS := \
  $(patsubst %.s,%.o,$(wildcard src/dsp/*.s)) \
  $(patsubst %.c,%.o,$(wildcard src/wrap/*.c)) \
  $(patsubst %.c,%.o,$(wildcard src/usb/*.c)) \
  $(patsubst %.c,%.o,$(wildcard src/*.c)) \

DEPS := \
  $(patsubst %.s,%.d,$(wildcard src/dsp/*.s)) \
  $(patsubst %.c,%.d,$(wildcard src/wrap/*.c)) \
  $(patsubst %.c,%.d,$(wildcard src/usb/*.c)) \
  $(patsubst %.c,%.d,$(wildcard src/*.c)) \

C_SRCS := $(SOURCES)
OBJS := $(OBJECTS)
C_DEPS := $(DEPS) 
LIBS := -lDriversLPC17xxgnu -lcr_dsplibFFT_cm3 -lgcc -lc

COMPILO_PATH := robovero/x-tools/arm-bare_newlib_cortex_m3_nommu-eabi

src/wrap/%.o: src/wrap/%.c
src/usb/%.o: src/usb/%.c
src/%.o: src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	arm-bare_newlib_cortex_m3_nommu-eabi-gcc -DARM_MATH_CM3 -D__BUILD_WITH_EXAMPLE__=1 -D__RAM_MODE__=0 -D__thumb2__=1 -I"include" -I"include/core" -I"include/drivers" -I"include/dsp" -I"include/usb" -I"include/wrap" -I${HOME}/$(COMPILO_PATH)/arm-bare_newlib_cortex_m3_nommu-eabi/include -I${HOME}/$(COMPILO_PATH)/lib/gcc/arm-bare_newlib_cortex_m3_nommu-eabi/4.4.1/include -O0 -g -Wall -mthumb -mcpu=cortex-m3 -c -ffunction-sections -fdata-sections -MD -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/dsp/%.o: src/dsp/%.s
	@echo 'Building file $<'
	@echo 'Invoking: GCC C Compiler'
	arm-bare_newlib_cortex_m3_nommu-eabi-gcc -c -x assembler-with-cpp -DDEBUG -mcpu=cortex-m3  -I"include" -I"include/core" -I"include/drivers" -I"include/dsp" -I"include/usb" -I"include/wrap" -I${HOME}/$(COMPILO_PATH)/arm-bare_newlib_cortex_m3_nommu-eabi/include -I${HOME}/$(COMPILO_PATH)/lib/gcc/arm-bare_newlib_cortex_m3_nommu-eabi/4.4.1/include -ffunction-sections -O0 -g -Wall -fdata-sections -MD -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mthumb -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

# All Target
all: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	arm-bare_newlib_cortex_m3_nommu-eabi-ld -nostdlib -L"lib" -Map=firmware.map -T "script.ld"  --gc-sections -o"firmware" $(OBJS) $(USER_OBJS) $(LIBS)
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
	
flash: all
	-./flash.py
