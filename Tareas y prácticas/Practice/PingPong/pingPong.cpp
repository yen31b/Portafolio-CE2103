#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <pthread.h>        

void ping() 
{
  std::cout << "Ping";
}

void pong(int x)
{
	std::cout << "Pong";
}


int main() 
{
	std::thread first (ping);     // spawn new thread that calls ping()
	std::thread second (pong,0);  // spawn new thread that calls pong(0)

	std::cout << "main, ping and pong now execute concurrently...\n";

	// synchronize threads:
	first.join();                // pauses until first finishes
	second.join();               // pauses until second finishes

	std::cout << "ping and pong completed.\n";

	return 0;
}