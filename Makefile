CC=gcc

default: all

all: ruby_shim

ruby_shim: ruby_shim.o

clean:
	rm -f ruby_shim *.o
