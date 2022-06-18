default:
	g++ src/*cpp -I src -o bin/main -lncurses -lcurl
	./bin/main
