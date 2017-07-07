#include <sys/types.h>
#include <sys/select.h>
#include <sys/time.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <sys/select.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#define PORT 4030
#define MAX_LISTEN 3

int main(int argc, char *argv[])
{
	
	int sockfd, newsockfd, n, i, j, fd_max;
	socklen_t clilen;
	char buffer[1500];
	fd_set rfds, rfds_copy; //set of socket descriptors

	FD_ZERO(&rfds); //clear an fd_set
	FD_ZERO(&rfds_copy);

	// server and client addresse
	struct sockaddr_in6 serv_addr, cli_addr;
	
	// create socket
	// SOCK_STREAM for TCP/IP	
	sockfd = socket(AF_INET6, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("Error opening socket\n");
	}

	//Reuse socket = enable multiple connections
	if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0){
		printf("setsockopt REUSEADDR failed\n");
	}

	//Erases the data in the n bytes of the memory
	memset(&serv_addr, 0, sizeof(struct sockaddr_in6));

	// set the type of the socket created
	serv_addr.sin6_family = AF_INET6;
	serv_addr.sin6_port = htons(PORT);

	// bind and check if was successful
	if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in6)) < 0){
		printf("Error on binding\n");
	}

	// listen, accept and receive
 	if (listen(sockfd, MAX_LISTEN) < 0){
		printf("Error listen\n");
	}

	//add the socket to the set
	FD_SET(sockfd, &rfds);	
	puts("Waiting for connection...");
	fd_max = sockfd;
	bzero(buffer, 1500);

	while(1)
	{
		
		rfds_copy = rfds; // copy before select()	
		
		//waiting for activity on the socket
		n = select(fd_max + 1, &rfds_copy, NULL, NULL, NULL);
		if (n < 0){
			printf("Server-select() error\n");
		}
		
		if(FD_ISSET(sockfd, &rfds_copy)){
			bzero(buffer, 1500);
			//creating a socket for a new client
			newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	
			if(newsockfd > 0){	
				printf("New connection, sockfd is %d , PORT: %d \n", 
					newsockfd, htons(cli_addr.sin6_port));
			}

			else{
				printf("Error on accept\n");
			}
			//add to master set
			FD_SET(newsockfd, &rfds);
			//change the highest file descriptor number
			if(newsockfd > fd_max){
				fd_max = newsockfd;
			}
		}

		// hande the data from others clients
		else{
			//run through the existing connections
			for (i = sockfd + 1; i <= fd_max; i++){
				bzero(buffer, 1500);
	
				if(FD_ISSET(i, &rfds_copy)){
					// to read from terminal
					n = read(i, buffer, 1499);
				}
				
				//if socket was closed or error
				if (n <=  0){
					close(i); //close the socket
					FD_CLR(i, &rfds); //remove from the master list
			
				}
			
				// if everything is OK = we have got some data from client
				else{
					for (j = 0; j <= fd_max; j++){
						if(FD_ISSET(j, &rfds)){
							
							//send client's information to all 
							//except the client and ourselves
							if(j != sockfd && j != i){
								write(j, buffer, strlen(buffer));
								bzero(buffer, 1500);
								
										
							}	
						
						}
					}
				}
			} // end monitoring operation on others sockets
		
		}
	}
	exit(0);
}

