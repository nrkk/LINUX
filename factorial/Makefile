all: hello
	
hello: main.o story.o factorial.o 
	g++ main.o story.o factorial.o -o hello

main.o:main.o
	g++ -c main.cpp
factorial.o:factorial.cpp
	g++ -c factorial.cpp
story.o:story.cpp
	g++ -c story.cpp
clean:
	rm -rf *o hello

