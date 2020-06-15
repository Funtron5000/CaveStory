CXX = g++
INCLUDE = 

cavestory: main.o input.o game.o graphics.o
	CXX main.o input.o game.o graphics.o -o cavestory.exe

main.o: main.cpp
	CXX -c main.cpp

input.o: input.cpp
	CXX -c input.cpp

game.o: game.cpp
	CXX -c game.cpp

graphics.o: graphics.cpp
	CXX -c graphics.cpp

clean:
	del *.o