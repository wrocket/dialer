CC=gcc
OPTS=-O2
FILES=dialer.c connect.c disconnect.c senddata.c
BIN=dialer

all:
	$(CC) $(FILES) $(OPTS) -o $(BIN)

