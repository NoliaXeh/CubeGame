CXX = g++
CXXFLAGS = -Wall -Wextra -Weffc++ -pedantic -std=c++17

CXX_SDL = -lSDL `sld-config --clfags --libs`
CXX_OPENGL = -lGL -lGLU

OBJS = src/cube.o							    \
	src/vector3.o							    \
	src/game.o							    \
	src/block.o							    \
	src/map.o							    \
	src/graphics.o							    \

all: game

game: ${OBJS}
	${CXX} ${CXXFLAGS} $^ -o $@ ${CXX_SDL} ${CXX_OPENGL}
