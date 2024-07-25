PROG := base_defense
CC := g++
CPPFLAGS := -Iinclude -lsfml-graphics -lsfml-window -lsfml-system
SRC_DIR := ./src
BUILD_DIR := ./bin

default: build

build: $(BUILD_DIR)/game.o $(BUILD_DIR)/main.o $(BUILD_DIR)/player.o $(BUILD_DIR)/PhysicalObject.o $(BUILD_DIR)/bullet.o $(BUILD_DIR)/RenderGroup.o
	$(CC) $(BUILD_DIR)/main.o $(BUILD_DIR)/game.o $(BUILD_DIR)/player.o $(BUILD_DIR)/PhysicalObject.o $(BUILD_DIR)/bullet.o -o $(PROG) $(BUILD_DIR)/RenderGroup.o $(CPPFLAGS)
	


run:
	./$(PROG)

$(BUILD_DIR)/game.o: $(SRC_DIR)/game.cpp
	$(CC) -c $(SRC_DIR)/game.cpp -o $(BUILD_DIR)/game.o $(CPPFLAGS)

$(BUILD_DIR)/main.o: $(SRC_DIR)/game.cpp
	$(CC) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o $(CPPFLAGS)

$(BUILD_DIR)/player.o: $(SRC_DIR)/player.cpp
	$(CC) -c $(SRC_DIR)/player.cpp -o $(BUILD_DIR)/player.o $(CPPFLAGS)

$(BUILD_DIR)/bullet.o: $(SRC_DIR)/bullet.cpp
	$(CC) -c $(SRC_DIR)/bullet.cpp -o $(BUILD_DIR)/bullet.o $(CPPFLAGS)

$(BUILD_DIR)/PhysicalObject.o: $(SRC_DIR)/PhysicalObject.cpp
	$(CC) -c $(SRC_DIR)/PhysicalObject.cpp -o $(BUILD_DIR)/PhysicalObject.o $(CPPFLAGS)

$(BUILD_DIR)/RenderGroup.o: $(SRC_DIR)/RenderGroup.cpp
	$(CC) -c $(SRC_DIR)/RenderGroup.cpp -o $(BUILD_DIR)/RenderGroup.o $(CPPFLAGS)
