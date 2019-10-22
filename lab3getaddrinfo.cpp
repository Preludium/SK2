    #include <netdb.h>
    #include <cstdio>
    #include <error.h>
     #include <iostream>
#include <fcntl.h>
#include <unistd.h>

    int main(){
        int fd;
        addrinfo hints {};
        hints.ai_family   = AF_INET;         // tylko IPv4 (AF_INET)
        hints.ai_protocol = IPPROTO_TCP;

        addrinfo * resolved;
        // Podpowiedzi, port i nazwa hosta są opcjonalne.
        int res = getaddrinfo("wikipedia.com", "http", &hints, &resolved);
     
        if ((fd = socket(resolved->ai_family, resolved->ai_socktype, resolved->ai_protocol)) == -1)
            perror("socket error\n");

        if(res) error(1,0,"Getaddrinfo failed: %s\n", gai_strerror(res));
        if(!resolved) error(1,0,"Empty result\n");

        if(connect(fd, resolved->ai_addr, resolved->ai_addrlen) == -1)
            perror("connect error\n");

        write(fd, "GET /\r\n", 7);

        char buf [512];
        int cnt = recv(fd, buf, 512, MSG_WAITALL);
        write(1, buf, cnt);
     
        freeaddrinfo(resolved);
     
        return 0;
    }

