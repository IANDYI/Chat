# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Targets
all: server client

server: server.c
	$(CC) $(CFLAGS) -o server server.c

client: client.c
	$(CC) $(CFLAGS) -o client client.c

clean:
	rm -f server client
