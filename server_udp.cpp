#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

int main(int argc, char **argv)
{
    int fd;

    if ((fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
        perror("socker error\n");

    sockaddr_in sa {AF_INET, htons(8000),INADDR_ANY};

    if (bind(fd, (sockaddr*) &sa, sizeof(sa)) == -1)
        perror("bind error\n");

    socklen_t sl = sizeof(sa);

    const int one = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));

    int n;
    char buf[64];
    
    if((n = recvfrom(fd, buf, sizeof(buf), 0, (sockaddr*) &sa, &sl)) == -1)
        perror("revfrom error\n");

    write(1, buf, sizeof(buf));

    sendto(fd, "message received", 17, 0, (sockaddr*) &sa, sl);

    close(fd);
}