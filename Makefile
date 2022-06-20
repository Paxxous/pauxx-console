default:
	g++ -g -Wall src/*cpp -I src -o bin/main -lncurses -lcurl
	./bin/main

release:
	g++ -O3 -Wall src/*cpp -I src -o bin/main -lncurses -lcurl
