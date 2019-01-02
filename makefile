CC := g++ -Wall -Wextra -O -Wdeprecated

main : main.cpp SearchEngine.cpp SearchEngine.h
	$(CC) main.cpp SearchEngine.cpp SearchEngine.h

main.o: main.cpp SearchEngine.h
	$(CC) main.cpp SearchEngine.cpp SearchEngine.h

SearchEngine.o: SearchEngine.cpp SearchEngine.h
	$(CC) main.cpp SearchEngine.cpp SearchEngine.h

SearchEngine.o: SearchEngine.h
	$(CC) main.cpp SearchEngine.cpp SearchEngine.h
