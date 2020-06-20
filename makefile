CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o being.o player.o monster.o space.o empty.o item.o key.o door.o goal.o sphinx.o sMenu.o sResponse.o weapon.o map.o menu.o programStart.o

SRCS = main.cpp being.cpp player.cpp monster.cpp space.cpp empty.cpp item.cpp key.cpp door.cpp goal.cpp sphinx.cpp sMenu.cpp sResponse.cpp weapon.cpp map.cpp menu.cpp programStart.cpp

HEADERS = being.hpp player.hpp monster.hpp space.hpp empty.hpp item.hpp key.hpp door.hpp goal.hpp sphinx.hpp sMenu.hpp sResponse.hpp weapon.hpp map.hpp menu.hpp programStart.hpp

dungeon: main.o being.o player.o monster.o space.o empty.o item.o key.o door.o goal.o sphinx.o sMenu.o sResponse.o weapon.o map.o menu.o programStart.o
	${CXX} ${OBJS} -o dungeon

${OBJ}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o dungeon
