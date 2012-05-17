CC       = gcc
FLAGS    = -Wall -O1 -g
INCLUDES = `pkg-config --cflags --libs webkitgtk-3.0`

all: minibrowser

minibrowser:
	$(CC) -o minibrowser main.c $(INCLUDES) $(FLAGS)

clean:
	rm minibrowser

