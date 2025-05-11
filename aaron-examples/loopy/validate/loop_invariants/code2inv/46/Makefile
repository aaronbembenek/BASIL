# Invoke this Makefile from the BASIL root directory with the command
#
# 	make -f [MAKEFILE_DIR]/Makefile
#
#   Optionally, you can set a compiler optimization level using the OPT variable:
#
#   make -f [MAKEFILE_DIR]/Makefile OPT=-O2

OPT ?= -O0
BASE_NAME=46
ROOT_DIR:=$(shell dirname $(firstword $(MAKEFILE_LIST)))
NAME=$(ROOT_DIR)/$(BASE_NAME)
NAMEO=$(NAME).$(OPT)
SOURCES=$(shell find src/)
BASIL_OPTS=--analyse --simplify
COMPILER_OPTS=-fno-stack-protector -fno-plt -fno-pic -march=armv8.1-a $(OPT)

all: $(NAMEO).relf $(NAMEO).gts $(NAMEO).bpl

dsa: $(NAMEO).relf $(NAMEO).gts $(NAMEO)-dsa.bpl

$(NAMEO).bpl: $(NAMEO).gts $(NAME).spec $(NAMEO).relf $(SOURCES)
	mill run --input $(NAMEO).gts --relf $(NAMEO).relf --spec $(NAME).spec --output $@ $(BASIL_OPTS)

$(NAMEO)-dsa.bpl: $(NAMEO).gts $(NAME).spec $(NAMEO).relf $(SOURCES)
	mill run --input $(NAMEO).gts --relf $(NAMEO).relf --spec $(NAME).spec --output $@ $(BASIL_OPTS) --memory-regions dsa

%.gts: %.gtirb
	gtirb-semantics $< $@

%.gtirb: %.out
	ddisasm $< --ir $@

%.relf: %.out
	greadelf -r -s -W $< > $@

%.$(OPT).out: %.c
	podman run --platform linux/amd64 --rm -v./:/host -w /host ghcr.io/uq-pac/basil-dev:latest aarch64-linux-gnu-gcc $(COMPILER_OPTS) $< -o $@

clean:
	rm -f $(ROOT_DIR)/*.relf $(ROOT_DIR)/*.gts $(ROOT_DIR)/*.bpl

.PHONY: clean all dsa
