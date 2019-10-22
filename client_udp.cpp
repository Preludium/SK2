#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

int main(int argc, char **argv) {
    int fd;
    char buf[64];

    sockaddr_in sa{AF_INET, htons(8000), inet_addr("127.0.0.1")};

    if((fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        if (errno == ENOENT)
            perror("brak dostepu do pliku");
        else
            perror("przy otwieranie pliku");
        return 0;
    }
    if (bind(fd, (sockaddr*) &sa, sizeof(sa)) == -1)
        perror("bind error\n");

    if (-1 == sendto(fd, "wiadomosc", 10, 0, (sockaddr*) &sa,  sizeof(sa)))
        perror("SendTo error\n");
    
    read(fd, buf, sizeof(buf));

    write(1, buf, sizeof(buf));
    
    // while ((n = recvfrom(fd, buf, sizeof(buf), 0, (sockaddr*) &sa, &sl)) > 0){
    //     if (n == -1)
    //         perror("Recv error\n");
    //     write(1, buf, sizeof(buf));
    // }

    close(fd);

    return 0;
}