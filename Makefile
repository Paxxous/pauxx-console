default:
	g++ -Wall src/*cpp -I src -o bin/main -lncurses -lcurl
	./bin/main
