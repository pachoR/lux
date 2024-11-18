CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -g


SRC = $(wildcard *.c)
TARGET = lux


$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS)


clean:
	rm -f $(TARGET)

.PHONY: all clean
