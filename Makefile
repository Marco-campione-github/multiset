CXXFLAGS = -std=c++0x

main.exe: main.o
	g++ $(CXXFLAGS) main.o -o main.exe

main.o: main.cpp multiset.h
	g++ $(CXXFLAGS) -c main.cpp -o main.o

# ho messo multiset.h nelle dipendenze perchè contiene codice templato

.PHONY: clean
clean:
	rm *.o *.exe
