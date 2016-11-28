CC_FLAGS= -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CC_C = arm-linux-gnueabihf-gcc
CC = gcc
PUBDIR = $(HOME)/cmpt433/public/myApps
SRC = Terrarium.c
TARGET = terrarium
LINKER = -lpthread -lm

help:
	echo "Targets are: all, app, clean"

all: app

app: TerrariumServer.o
	$(CC_C) $(CC_FLAGS) TerrariumServer.o $(SRC) -o $(TARGET) $(LINKER)
	cp $(TARGET) $(PUBDIR)/$(TARGET)

TerrariumServer.o: TerrariumServer.c
	$(CC_C) $(CC_FLAGS) -c TerrariumServer.c

clean: 
	rm -f *o $(PUBDIR)/$(TARGET)
