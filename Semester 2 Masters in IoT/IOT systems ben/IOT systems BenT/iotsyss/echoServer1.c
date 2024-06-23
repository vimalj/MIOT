#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char *argv[])
{
	//File descripters
	int listenfd, connfd;

	//Socket structures
	struct sockaddr_in servaddr, cliaddr;
	socklen_t clilen = sizeof(cliaddr);
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //Just use local addr
	servaddr.sin_port = htons(3000);


	char buf[1000];

	listenfd = socket(PF_INET, SOCK_STREAM, 0);


	bind(listenfd, (struct sockaddr *)&servaddr, sizeof(struct sockaddr_in));

	listen(listenfd, 5);
	
	while(1)
	{
		printf("Waiting for client to connect...\n");
		connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen); 

		//Client has connected
		printf("Connection made... \n");

		recv(connfd, buf, 1000, 0);

		puts(buf);

		send(connfd, buf, strlen(buf), 0);
	}
		

	return 0;

}

