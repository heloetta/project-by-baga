main.o:main.cpp Record.h add.h
	g++ -c $<

add.o:add.cpp add.h Record.h 
	g++ -c $<

edit.o:edit.cpp edit.h Record.h
	g++ -c $<
	
delete.o:delete.cpp delete.h Record.h
	g++ -c $<
  
linked_list.o:linked_list.cpp linked_list.h Record.h
	g++ -c $<

view.o:view.cpp view.h linked_list.h Record.h
	g++ -c $<

analyse.o:analyse.cpp linked_list.h Record.h analyse.h
	g++ -c $<
	
Alert.o:Alert.cpp Alert.h Record.h
	g++ -c $<
	
main:main.o add.o edit.o delete.o linked_list.o view.o analyse.o Alert.o
	g++ $^ -o $@

clean:
	rm main.o add.o edit.o delete.o linked_list.o view.o analyse.o Alert.o main
