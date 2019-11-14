

main: client server
	@echo "Compiled"

client: structure
	g++ Client/client.cpp -o bin/client

server: structure
	g++ Server/server.cpp -o bin/server

clean:
	@rm -rf bin

structure:
	@mkdir -p bin