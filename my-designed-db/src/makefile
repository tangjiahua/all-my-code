CC = g++

all: main

main: main.cpp Exception.h BPlusTree.h API.o interpreter.o sqlcommand.o RecordManager.o IndexManager.o CatalogManager.o BufferManager.o
	$(CC) main.cpp API.o interpreter.o sqlcommand.o RecordManager.o IndexManager.o CatalogManager.o BufferManager.o -o main -std=c++11

API.o: API.h API.cpp
	$(CC) -c API.cpp -std=c++11

interpreter.o: interpreter.h interpreter.cpp
	$(CC) -c interpreter.cpp -std=c++11

sqlcommand.o: sqlcommand.h sqlcommand.cpp
	$(CC) -c sqlcommand.cpp -std=c++11

RecordManager.o: RecordManager.h RecordManager.cpp
	$(CC) -c RecordManager.cpp -std=c++11

IndexManager.o: IndexManager.h IndexManager.cpp
	$(CC) -c IndexManager.cpp -std=c++11

CatalogManager.o: CatalogManager.h CatalogManager.cpp
	$(CC) -c CatalogManager.cpp -std=c++11

BufferManager.o: BufferManager.h BufferManager.cpp
	$(CC) -c BufferManager.cpp -std=c++11

clean:
	rm main *.o
