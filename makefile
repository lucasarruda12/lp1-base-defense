PROG = ./main.exe
CC = g++
CPPFLAGS= -Iinclude -lsfml-graphics -lsfml-window -lsfml-system

default: build

build: main.o
	${CC} main.o ${CPPFLAGS} -o ${PROG}

run:
	${PROG}

main.o:
	${CC} -c ./main.cpp -o main.o
