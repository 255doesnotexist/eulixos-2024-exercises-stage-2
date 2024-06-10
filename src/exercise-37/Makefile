# If KERNELRELEASE is defined, we've been invoked from the kernel build
# system and can use its language.
ifneq ($(KERNELRELEASE),)

# kbuild syntax
obj-m := timer.o

# Otherwise we were called directly from the command line.  Invoke the
# kernel build system.
else

KERNEL_SOURCE := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
OUTPUT_DIR ?= $(PWD)
TARGET = $(OUTPUT_DIR)/exercise-37

$(TARGET): timer.ko
	@cp $(PWD)/timer.ko $(OUTPUT_DIR)/exercise-37

timer.ko: default

default:
	$(MAKE) -C $(KERNEL_SOURCE) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_SOURCE) M=$(PWD) clean

endif
