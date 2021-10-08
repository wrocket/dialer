#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>

int senddata(char * data){

	char buffer[256];
	int port = 80;
	int sockfd;
	int n;
	struct sockaddr_in serv_addr;
	struct hostent * server;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		perror("Error opening socket.\n");
		return -1;
	}
	server = gethostbyname("192.168.0.1");
	if(server == NULL){
		perror("Error connecting to host...can't get hostname");
		return -1;
	}
	memset((char *) &serv_addr, '\0', sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, 
	      (char *)&serv_addr.sin_addr.s_addr,
				server->h_length);
	serv_addr.sin_port = htons(port);
	if(connect(sockfd, & serv_addr, sizeof(serv_addr)) < 0){
		perror("Error connecting.\n");
		return -1;
	}
	n = write(sockfd, data, strlen(data));
	if(n < 0){
		perror("Error writing to socket");
		return -1;
	}
	do{
		n = read(sockfd, buffer, 255);
		/* Only if you want verbosity... */
		/* printf("%s", buffer); */
	} while(n > 0);
	return 0;
}
