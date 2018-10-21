Lab2: main.o Executive.o movie.o
	g++ -std=c++11 -g -Wall main.o Executive.o movie.o -o Lab2

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

movie.o: movie.cpp movie.h
	g++ -std=c++11 -g -Wall -c movie.cpp

clean:
	rm *.o Lab2
