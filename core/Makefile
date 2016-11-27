CC_FLAGS= -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CC_C = arm-linux-gnueabihf-gcc
CC = gcc
PUBDIR = $(HOME)/cmpt433/public/myApps
SRC = Terrarium.c
TARGET = terrarium
LINKER = -lpthread -lm

help:
	echo "Targets are: all, app, wav, node"

all: app

app:
	$(CC_C) $(CC_FLAGS) $(SRC) -o $(TARGET)
	cp $(TARGET) $(PUBDIR)/$(TARGET)

clean: 
	rm -f *o $(PUBDIR)/$(TARGET)
