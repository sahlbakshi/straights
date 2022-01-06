CXX = g++ -g
CXXFLAGS = -std=c++14 
EXEC = straights
OBJECTS = card.o deck.o table.o player.o human.o computer.o game.o message.o main.o user.o

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
