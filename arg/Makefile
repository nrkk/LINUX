obj-m +=hello.o
KDIR = /usr/src/linux-headers-$(shell uname -r)
PWD = $(shell pwd)
all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order *-
