powergrid.out : PowerGridDriver.o Player.o PowerPlant.o City.o SummaryCard.o
	g++ -o powergrid.out PowerGridDriver.o Player.o PowerPlant.o City.o

PowerGridDriver.o : PowerGridDriver.cpp powergrid.h
	g++ -c PowerGridDriver.cpp

Player.o : Player.cpp powergrid.h
	g++ -c Player.cpp

City.o : City.cpp powergrid.h
	g++ -c City.cpp

PowerPlant.o : PowerPlant.cpp powergrid.h
	g++ -c PowerPlant.cpp

SummaryCard.o : SummaryCard.cpp powergrid.h
	g++ -c SummaryCard.cpp

clean :
	rm powergrid.out PowerGridDriver.o Player.o City.o PowerPlant.o SummaryCard.o
