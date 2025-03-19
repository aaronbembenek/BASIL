# Invoke this Makefile from the BASIL root directory with the command
#
# 	make -f [MAKEFILE_DIR]/Makefile

BASE_NAME=81
ROOT_DIR:=$(shell dirname $(firstword $(MAKEFILE_LIST)))
NAME=$(ROOT_DIR)/$(BASE_NAME)
SOURCES=$(shell find src/)
BASIL_OPTS=--analyse --memory-regions dsa --simplify
COMPILER_OPTS=-O0 -fno-stack-protector -fno-plt -fno-pic -march=armv8.1-a

all: $(NAME).relf $(NAME).gts $(NAME).bpl

$(NAME).bpl: $(NAME).gts $(NAME).spec $(NAME).relf $(SOURCES)
	mill run --input $(NAME).gts --relf $(NAME).relf --spec $(NAME).spec --output $@ $(BASIL_OPTS)

%.gts: %.gtirb
	gtirb-semantics $< $@

%.gtirb: %.out
	ddisasm $< --ir $@

%.relf: %.out
	greadelf -r -s -W $< > $@

%.out: %.c
	podman run --platform linux/amd64 --rm -v./:/host -w /host ghcr.io/uq-pac/basil-dev:latest aarch64-linux-gnu-gcc $(COMPILER_OPTS) $< -o $@

clean:
	rm -f $(NAME).relf $(NAME).gts $(NAME).bpl

.PHONY: clean
