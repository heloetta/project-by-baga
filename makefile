main.o:main.cpp Record.h add.h
	g++ -c $<

add.o:add.cpp add.h Record.h
	g++ -c $<

linked_list.o:linked_list.cpp Record.h linked_list.h 
	g++ -c $<

view.o:view.cpp Record.h linked_list.h view.h 
	g++ -c $<

main:main.o add.o linked_list.o view.o
	g++ $^ -o $@


