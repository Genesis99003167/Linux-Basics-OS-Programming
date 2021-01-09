all: Server Client

Server: Server.c ClientServer.h
	gcc -o Server.out Server.c -lrt
	
Client: Client.c ClientServer.h
	gcc -o Client.out Client.c -lrt
	


runServer:
	./Server.out
	
runClient:
	./Client.out

clean:
	rm -rf *.out *.o
