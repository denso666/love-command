CC = g++
CFLAGS = -Wall -std=c++11
OUTPUT_DIR ?= ./output
BIN = $(OUTPUT_DIR)/love_command
SRC = ./src
CLASSES_DIR = $(SRC)/classes

.PHONY: all clean run

all: $(BIN)

$(BIN): $(OUTPUT_DIR)/Player.o $(OUTPUT_DIR)/Engine.o $(SRC)/main.cpp
	$(CC) $^ $(CFLAGS) -o $@

$(OUTPUT_DIR)/Player.o: $(CLASSES_DIR)/Player.cpp
	$(CC) -c $(CFLAGS) $< -o $@

$(OUTPUT_DIR)/Engine.o: $(CLASSES_DIR)/Engine.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf **/**/*.o ./output/*

run:
	chmod +x $(BIN)
	$(BIN)
