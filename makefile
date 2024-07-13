PROG := base_defense
CC := g++
CPPFLAGS := -Iinclude -lsfml-graphics -lsfml-window -lsfml-system
SRC_DIR := ./src
BUILD_DIR := ./bin

default: build

build: $(BUILD_DIR)/game.o $(BUILD_DIR)/main.o
	$(CC) $(BUILD_DIR)/main.o $(BUILD_DIR)/game.o -o $(PROG) $(CPPFLAGS)

run:
	./$(PROG)

$(BUILD_DIR)/game.o: $(SRC_DIR)/game.cpp
	$(CC) -c $(SRC_DIR)/game.cpp -o $(BUILD_DIR)/game.o $(CPPFLAGS)

$(BUILD_DIR)/main.o: $(SRC_DIR)/game.cpp
	$(CC) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o $(CPPFLAGS)
