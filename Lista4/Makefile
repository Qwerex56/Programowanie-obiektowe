# g++ -c ../Lista1i2/plansza.cpp cellularAutomata.cpp cellularAutomataMain.cpp
# g++ -o caMain plansza.o cellularAutomata.o cellularAutomataMain.o

cellular_automata: cellularAutomataMain.o cellularAutomata.o plansza.o
	g++ cellularAutomataMain.o cellularAutomata.o plansza.o -o cellular_automata

cellularAutomataMain.o:cellularAutomataMain.cpp
	g++ -c cellularAutomataMain.cpp

cellularAutomata.o:cellularAutomata.cpp cellularAutomata.h
	g++ -c cellularAutomata.cpp

plansza.o:../Lista1i2/plansza.cpp ../Lista1i2/plansza.h
	g++ -c ../Lista1i2/plansza.cpp

clean:
	rm *.o cellular_automata