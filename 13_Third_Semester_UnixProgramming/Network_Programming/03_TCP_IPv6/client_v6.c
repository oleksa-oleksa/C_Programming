#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <netdb.h>
#include <arpa/inet.h>
#define PORT 4030

int main(int argc, char *argv[])
{
	
	int sockfd, n, fd_max;
	//static const uint8_t serv__addr[16] = {"::1"};	
	struct sockaddr_in6 serv_addr;
	char buffer[1500];
	fd_set rfds, rfds_copy; // set of socket descriptors for read and write

	FD_ZERO(&rfds);
	FD_ZERO(&rfds_copy);
	bzero(buffer, 1500);

	//creating a socket	
	sockfd = socket(AF_INET6, SOCK_STREAM, 0);
	if(sockfd < 0){
	printf("Error opening socket\n");
	}

	memset(&serv_addr, 0, sizeof(struct sockaddr_in));

	serv_addr.sin6_family = AF_INET6;
	serv_addr.sin6_port = htons(PORT);
	inet_pton(AF_INET6, "::1", serv_addr.sin6_addr.s6_addr);

	//add descriptor to the socket
	FD_SET(sockfd, &rfds);
	FD_SET(0, &rfds);

	//connect to the server
	if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
		printf("Error connecting\n");
		exit(1);
	}
	fd_max = sockfd;
	
	//was successfuly connected
	printf("Client started:\n");

	while(1){
		rfds_copy = rfds;

		// waiting for the incoming message or user input
		n = select(fd_max + 1, &rfds_copy, 0, NULL, NULL);
		if (n < 0){
			printf("Client-select() error\n");
		}
	

		// monitoring user input
		if (FD_ISSET(0, &rfds_copy)){

			bzero(buffer, 1500);
			fgets(buffer, 1500, stdin);

			n = write(sockfd, buffer, strlen(buffer));

			if(n < 0){
			printf("Error sending to socket\n");
			}
		}
		
		// monitoring server's message
		if (FD_ISSET(sockfd, &rfds_copy)){
			bzero(buffer, 1500);
			n = read(sockfd, buffer, 1500);
			
			if(n < 0){
			printf("Error getting message from server");
			}

			printf("%s", buffer);
			bzero(buffer, 1500);
		}
				
	}
	return 0;
}
