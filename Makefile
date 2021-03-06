MAINFILENAME=main
MCU=atmega328
OPTIMIZE=-Og -g
XTAL=16000000
CFLAGS=-c $(OPTIMIZE) -fanalyzer -Wno-write-strings -Wcast-align -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wduplicated-branches -Wduplicated-cond -Wextra-semi -Wfloat-equal -Wlogical-op -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Werror -IInclude -Wall -Wextra -Wpedantic -std=gnu++17 -pedantic-errors -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -fno-devirtualize -fno-use-cxa-atexit -mmcu=$(MCU) -DF_CPU=$(XTAL)
LFLAGS=$(OPTIMIZE) -fanalyzer -Wno-write-strings -Wcast-align -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wduplicated-branches -Wduplicated-cond -Wextra-semi -Wfloat-equal -Wlogical-op -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Wall -Wextra -Wpedantic -pedantic-errors -flto -fuse-linker-plugin -ffunction-sections -fdata-sections -Wl,--gc-sections -mmcu=$(MCU) -lm

all: size

Build/main: lib
	@avr-g++ $(CFLAGS) "Src/$(MAINFILENAME).cpp" -o "Build/$(MAINFILENAME).o"
	@echo 'CC main'

Build/core.a: _lib
	@avr-gcc-ar rcs Build/core.a Build/DigitalRegisters.o
	@avr-gcc-ar rcs Build/core.a Build/CustomFuncs.o
	@avr-gcc-ar rcs Build/core.a Build/StringFuncs.o
	@avr-gcc-ar rcs Build/core.a Build/Usart.o
	@avr-gcc-ar rcs Build/core.a Build/Timers.o
	@avr-gcc-ar rcs Build/core.a Build/ADC.o
	@avr-gcc-ar rcs Build/core.a Build/WatchdogTimer.o
	@avr-gcc-ar rcs Build/core.a Build/TWI.o
	@avr-gcc-ar rcs Build/core.a Build/NumFuncs.o
	@echo -e '\033[0;32mLibrary compilation done\033[0m'

link: Build/main Build/core.a lib
	@avr-gcc $(LFLAGS) Build/main.o Build/core.a -o Build/main.elf
	@echo 'LL ELF'

objcopy: link
	@avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  "Build/$(MAINFILENAME).elf" "Build/$(MAINFILENAME).eep"
	@avr-objcopy -O ihex -R .eeprom  "Build/$(MAINFILENAME).elf" "Build/$(MAINFILENAME).hex"
	@echo 'OBJ'

lib: _lib Build/core.a
_lib: Build/Usart.o Build/Timers.o Build/ADC.o Build/DigitalRegisters.o Build/StringFuncs.o Build/WatchdogTimer.o Build/CustomFuncs.o Build/TWI.o Build/NumFuncs.o


Build/Usart.o: Build
	@avr-g++ $(CFLAGS) "Src/USART.cpp" -o "Build/Usart.o"
	@echo 'CC Usart'

Build/Timers.o: Build
	@avr-g++ $(CFLAGS) "Src/Timers.cpp" -o "Build/Timers.o"
	@echo 'CC Timers'

Build/ADC.o: Build
	@avr-g++ $(CFLAGS) "Src/ADC.cpp" -o "Build/ADC.o"
	@echo 'CC ADC'

Build/StringFuncs.o: Build
	@avr-g++ $(CFLAGS) "Src/stringFuncs.cpp" -o "Build/StringFuncs.o"
	@echo 'CC StringFuncs'

Build/WatchdogTimer.o: Build
	@avr-g++ $(CFLAGS) "Src/watchdog.cpp" -o "Build/WatchdogTimer.o"
	@echo 'CC WatchdogTimer'

Build/DigitalRegisters.o: Build
	@avr-g++ $(CFLAGS) "Src/digitalRegisters.cpp" -o "Build/DigitalRegisters.o"
	@echo 'CC DigitalRegisters'

Build/CustomFuncs.o: Build
	@avr-g++ $(CFLAGS) "Src/customFuncAddr.cpp" -o "Build/CustomFuncs.o"
	@echo 'CC CustomFuncs'

Build/TWI.o: Build
	@avr-g++ $(CFLAGS) "Src/TWI.cpp" -o "Build/TWI.o"
	@echo 'CC TWI'

Build/NumFuncs.o: Build
	@avr-g++ $(CFLAGS) "Src/numFuncs.cpp" -o "Build/NumFuncs.o"
	@echo 'CC NumFuncs'

clean:
	@rm -rf Build/*
	@echo -e '\033[0;31mCleaned\033[0m'

size: objcopy
	@echo -e '\033[0;36m'
	@avr-size Build/$(MAINFILENAME).elf -C --mcu=$(MCU)
	@echo -e '\033[0m'


Build:
	@mkdir -p Build
	@echo 'mkdir Build'
