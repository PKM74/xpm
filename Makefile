CC=gcc
CC++=g++
LIB_DIR=lib
CFLAGS=
BUILD_DIR=build
SRC_DIR=src

SRC=$(wildcard $(SRC_DIR)/*.c)
.PHONY: all always clean example_package test

all: main always

main: always
	$(CC) -o $(BUILD_DIR)/xpm $(SRC) $(CFLAGS)
	chmod +x $(BUILD_DIR)/xpm
always:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
	rm example-package.tar

example_package:
	tar -cf example-package.tar example-package/

test: example_package main
	$(BUILD_DIR)/xpm --debug --install example-package.tar