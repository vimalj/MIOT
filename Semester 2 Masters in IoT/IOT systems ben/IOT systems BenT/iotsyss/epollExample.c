#include <stdio.h>
#include <fcntl.h>
#include <sys/epoll.h>

int main(void) {
	int retval;
	
	printf("Don't forget to config-pin!\n");
	printf("You'll have to set the edge file correctly too...\n");
	printf("You could do both of these in the code... :o)\n");

	//Doing a low-level file open to get the File Descriptor (fd)
	//Need this fd for low level commands like epoll
	int fd = open("/sys/class/gpio/gpio60/value", O_RDONLY | O_NONBLOCK);
	if(fd == -1)
	{
		perror("Can't open GPIO file");
		return -1;
	}

	int epollfd;
	struct epoll_event ev;
	epollfd = epoll_create(1);	
	//1 is the size - ignored... just has to be non-zero

	if(epollfd == -1)
	{
		perror("epoll create failed");
		return -1;	
	}

	//ev.events = read operation | edge triggered | urgent data
	ev.events = EPOLLIN | EPOLLET | EPOLLPRI;
	ev.data.fd = fd;  // attach the file file descriptor
	
	//Register the file descriptor on the epoll instance, see: man epoll_ctl
	if (epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev) == -1) {
		perror("GPIO: Failed to add control interface");
		return -1;
	}

	printf("Waiting for button press...\n");

	int epollRet = epoll_wait(epollfd, &ev, 1, -1);
	//Ignore first return - really should do a read() first.

	//This will block...
	epollRet = epoll_wait(epollfd, &ev, 1, -1);

	if (epollRet == -1){
		perror("GPIO: Poll Wait fail");
	}

	printf("Thank you!\n");

	return 0;
}

