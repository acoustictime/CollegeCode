Game: Game.o Card.o Deck.o Player.o Random.o
	g++ -o Game Game.o Card.o Deck.o Player.o Random.o

Card.o: Card.cpp Card.h
	g++ -c Card.cpp

Deck.o: Deck.cpp Deck.h Card.h Random.h
	g++ -c Deck.cpp

Player.o: Player.cpp Player.h Card.h Deck.h Random.h
	g++ -c Player.cpp

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

war.o: war3.cpp Card.h Deck.h Player.h HumanPlayer.h
	g++ -c war3.cpp -o war.o


