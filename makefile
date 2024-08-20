PROG := base_defense.exe
CC := g++

SFML :=

LDFLAGS := -L$(SFML)/lib -lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS := -Iinclude -I$(SFML)/include

SRC_DIR := ./src
OBJ_DIR := ./bin

SRCFILES := $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCFILES))

default: build

build: $(OBJS)
	$(CC) -o $(PROG) $^ $(LDFLAGS)

run:
	./$(PROG)

clean:
	rm -f $(OBJ_DIR)/*.o $(PROG)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp include/Constants.hpp
	@mkdir -p $(dir $@)
	$(CC) $(CXXFLAGS) -c $< -o $@

