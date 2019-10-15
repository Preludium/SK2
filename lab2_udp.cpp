#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

int main(int argc, char **argv) {
    int fd;
    // uint16_t hostEndianessPort = 13;
    char buf[64];
    sockaddr_in sa{AF_INET, htons(13), INADDR_ANY};
    socklen_t sl = sizeof(sa);

    if((fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        if (errno == ENOENT)
            perror("brak dostepu do pliku");
        else
            perror("przy otwieranie pliku");
        return 0;
    }

    if (-1 == sendto(fd, "GET", 3, 0, (sockaddr*) &sa,  sl))
        perror("SendTo error\n");
    
    int n;
    
    while ((n = recvfrom(fd, buf, sizeof(buf), 0, (sockaddr*) &sa, &sl)) > 0){
        if (n == -1)
            perror("Recv error\n");
        write(1, buf, sizeof(buf));
    }
    


    // const int one = 1;
    // setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));

    // if (bind(fd, (sockaddr*) &sa, sizeof(sa)) == -1)
        // perror("Bind error\n");

    // listen(fd, SO_MAXCONN);
    // int fd1;

    // for(int i = 0; i < 8; ++i){
    //     fd1 = accept(fd, (sockaddr*) &sa, &sl);
    //     write(fd1, "Hello\n", 6);
    //     printf("adres: %s, port: %d\n", inet_ntoa(sa.sin_addr), ntohs(sa.sin_port));
    //     shutdown(fd1, SHUT_RDWR);
    //     close(fd1);
    // }

    shutdown(fd, SHUT_RDWR);
    close(fd);

    return 0;
}