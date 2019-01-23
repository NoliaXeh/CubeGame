CXX = g++
CXXFLAGS = -Wall -Wextra -Weffc++ -pedantic -std=c++17 -g

CXX_SDL = -lSDL
##`sdl-config --clfags --libs`
CXX_OPENGL = -lGL -lGLU

OBJS = src/cube.o							    \
	src/vector3.o							    \
	src/entity.o							    \
	src/block.o							    \
	src/map.o							    \
	src/graphics.o							    \
	src/game.o							    \

all: game

game: ${OBJS}
	${CXX} ${CXXFLAGS} $^ -o $@ ${CXX_SDL} ${CXX_OPENGL}
