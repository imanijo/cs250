//Imani Johnson
//citations: https://www.youtube.com/watch?v=FRm9nk9ooC8&feature=youtu.be&list=PLLfyYMQQoe3vIm2LVHVxh5AYU_Z2cYGLw
//citations: https://www.youtube.com/watch?v=V6CohFrRNTo
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

void error(char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{

	char input[256];
	char output[256];
	int sockfd,portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[256];
	
	if(argc < 3)
	{ 
		fprintf(stderr,"usage %s hostname port\n", argv[0]);
		exit(0);
	}
	
	portno = atoi(argv[2]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	if(sockfd < 0)
	{
			error("ERROR opening socket");
	}
	
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(portno);
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	
	if(connect(sockfd,(SA *)serv_addr, &serv_addr.sin_addr))< 0)
	{
				error("ERROR connecting to server");
	}
	
	while(1){
	
	printf("Please enter message: ");
	fgets(input,256, stdin);
	send(sock,input, strlen(input), 0);
	
	len = recv(sock,output, 256, 0);
	output[len] = '\0';
	printf("%s\n", output);
	
}
	close(sockfd);	
	return 0;
}
