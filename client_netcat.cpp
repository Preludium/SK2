#include <cstdlib>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <error.h>
#include <netdb.h>
#include <sys/epoll.h>
#include <poll.h> 
#include <thread>
#include <signal.h>

int sock;
const int BUFSIZE = 64;

void read_from() {
    char buf[BUFSIZE];
    while(read(sock, buf, BUFSIZE) > 0) {
        write(1, buf, BUFSIZE);
        if(buf == "exit") {
            return;
        }
    }
}

void write_to() {
    char buf[BUFSIZE];
    while(read(1, buf, BUFSIZE) > 0) {
        write(sock, buf, BUFSIZE);
        if(buf == "exit") {
            return;
        }
    }
}

// void ctrl_c(int) {

// }

int main(int argc, char ** argv) {
    if(argc!=3) error(1,0,"Need 2 args");


    // Resolve arguments to IPv4 address with a port number
	addrinfo *resolved, hints={.ai_flags=0, .ai_family=AF_INET, .ai_socktype=SOCK_STREAM};
	int res = getaddrinfo(argv[1], argv[2], &hints, &resolved);
	if(res || !resolved) error(1, 0, "getaddrinfo: %s", gai_strerror(res));
	
	// create socket
	sock = socket(resolved->ai_family, resolved->ai_socktype, 0);
	if(sock == -1) error(1, errno, "socket failed");
	
	// attept to connect
	res = connect(sock, resolved->ai_addr, resolved->ai_addrlen);
	if(res) error(1, errno, "connect failed");
	
	// free memory
	freeaddrinfo(resolved);

    // signal(SIGINT, ctrl_c);

    std::thread write_thread(write_to), read_thread(read_from);

    read_thread.join();
    write_thread.join();
    close(sock);
}