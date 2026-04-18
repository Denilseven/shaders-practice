COMPILER = gcc
SOURCES = $(shell find src -name '*.c')
OUTPUT = game.out
FLAGS = -Iinclude -Llib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

default: build

build:
	$(COMPILER) $(SOURCES) -o $(OUTPUT) $(FLAGS)

run: build
	./$(OUTPUT)

clean:
	rm -f $(OUTPUT)
