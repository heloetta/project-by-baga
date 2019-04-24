main.o:main.cpp Record.h add.h
	g++ -c $<

add.o:add.cpp add.h Record.h
	g++ -c $<

main:main.o add.o
	g++ $^ -o $@
