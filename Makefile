TOOLCHAIN?=~/toolchains/android-x86
CC=$(TOOLCHAIN)/bin/i686-linux-android-gcc --sysroot $(TOOLCHAIN)/sysroot/ -I $(TOOLCHAIN)/include/
FLAGS=-Wall -Werror

libloadme.so: libloadme.o
	$(CC) -m32 -shared -o libloadme.so libloadme.o -static 

libloadme.o: loadme.c
	$(CC) -m32 -c $(FLAGS) -fpic -static loadme.c -o libloadme.o

load.elf: load.c
	$(CC) -m32 load.c -o load.elf $(FLAGS) -ldl

clean:
	rm -rf *.so *.o *.elf
