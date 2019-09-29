
PREFIX=arm-none-eabi

GCC=$(PREFIX)-gcc
OBJCOPY=$(PREFIX)-objcopy
OBJDUMP=$(PREFIX)-objdump
SIZE=$(PREFIX)-size
NM=$(PREFIX)-nm
DEMANGLE=$(PREFIX)-c++filt

CFLAGS=-mcpu=cortex-m3 -mthumb --specs=nosys.specs -nostdlib -g
NMFLAGS=--numeric-sort --print-size
APP=blink

SRCDIR=src
OBJDIR=obj
BINDIR=bin

Q=

.PHONY: all clean upload

all: $(BINDIR)/$(APP).bin

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo Compiling $<
	$(Q)mkdir -p $(OBJDIR)
	$(Q)$(GCC) -c $< -o $@ $(CFLAGS)

$(BINDIR)/$(APP).elf: $(OBJDIR)/main.o $(OBJDIR)/startup.o
	@echo Linking $<
	$(Q)mkdir -p $(BINDIR)
	$(Q)$(GCC) $? -o $@ $(CFLAGS) -Tflash.ld -Wl,-Map,$(BINDIR)/$(APP).map -nostartfiles

$(BINDIR)/$(APP).bin: $(BINDIR)/$(APP).elf
	@echo objcopy $<
	$(OBJCOPY) -O binary $< $@

info: $(BINDIR)/$(APP).elf
	$(SIZE) -A -t $(BINDIR)/$(APP).elf > $(BINDIR)/$(APP)_size.txt
	$(NM) $(NMFLAGS) $(BINDIR)/$(APP).elf > $(BINDIR)/$(APP)_nm.txt
	$(OBJDUMP) -h -S $< > $(BINDIR)/$(APP)_lst.txt

clean:
	$(RM) -r $(OBJDIR)
	$(RM) -r $(BINDIR)

upload: $(BINDIR)/$(APP).bin
	bossac -p /dev/ttyACM0 -e -i -w -v -b $< -R
