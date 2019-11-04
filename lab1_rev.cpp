#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
    int fd;
    char buf[64];
    uint16_t hostport = 13;
    uint16_t networkport = htons(hostport);

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = networkport;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (fd = (socket(AF_INTF, SOCK_STREAM, 0)) == -1){
        perror("socket error\n");
    }

    bind()

    if (connect(fd, (sockaddr*) &addr, sizeof(addr)) == -1){
        perror("connect error\n");
    }

    while (n = rcv(buf, buf, sizeof(buf)), MSG_WAITALL){
        if (n == -1)
            perror("receive error\n");

        write(1, buf, n);
    }

    shutdown(fd, SHUT_RDWR);
    close(fd);
}