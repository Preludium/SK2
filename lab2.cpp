#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

int main(int argc, char **argv) {
    int fd;
    int SO_MAXCONN = 13;
    // uint16_t hostEndianessPort = 13;

    sockaddr_in sa{AF_INET, htons(8080), INADDR_ANY};

    if((fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
    {
        if (errno == ENOENT)
            perror("brak dostepu do pliku");
        else
            perror("przy otwieranie pliku");
        return 0;
    }

    const int one = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));

    if (bind(fd, (sockaddr*) &sa, sizeof(sa)) == -1)
        perror("Bind error\n");

    listen(fd, SO_MAXCONN);
    socklen_t sl = sizeof(sa);
    int fd1;

    for(int i = 0; i < 8; ++i){
        fd1 = accept(fd, (sockaddr*) &sa, &sl);
        write(fd1, "Hello\n", 6);
        printf("adres: %s, port: %d\n", inet_ntoa(sa.sin_addr), ntohs(sa.sin_port));
        shutdown(fd1, SHUT_RDWR);
        close(fd1);
    }

    shutdown(fd, SHUT_RDWR);
    close(fd);

    return 0;
}