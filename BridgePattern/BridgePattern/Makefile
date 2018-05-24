bridgePattern : main.o
	g++ -o bridgePattern main.o

main.o : bridgePattern.h main.cpp
	g++ -c main.cpp

.PHONY : clean
clean :
	rm *.o bridgePattern