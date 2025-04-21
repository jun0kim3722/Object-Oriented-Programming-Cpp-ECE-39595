all: client serverSingle serverMulti

client: client.cpp
	g++ -std=c++17 client.cpp -o client -pthread 

serverSingle: serverSingle.cpp
	g++ -std=c++17 serverSingle.cpp -o serverSingle -pthread 

serverMulti: serverMulti.cpp
	g++ -std=c++17 serverMulti.cpp -o serverMulti -pthread 

clean:
	rm client
	rm serverSingle
	rm serverMulti

