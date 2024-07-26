PROG := base_defense.exe
CC := g++

LDFLAGS :=  -L$(SFML)/lib -lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS := -Iinclude -I$(SFML)/include

SRC_DIR := ./src
OBJ_DIR := ./bin

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

SFML :=

default: build

build: $(OBJS)
	$(CXX) $(LDFLAGS) -o $(PROG) $^

run:
	./$(PROG)

clean:
	rm -f $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c $< -o $@