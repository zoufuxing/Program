#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5678

int main()
{
  int sockfd,newsockfd,fd;
  struct sockaddr_in addr;
  int addr_len=sizeof(struct sockaddr_in);
  fd_set myreadfds;
  char msgbuffer[256];

  if(sockfd=socket(AF_INET,SOCK_STREAM,0) < 0)
  {
    perror("socket");
    exit(1);
  }else
  {
    printf("socket is created.\n");
    printf("socket id is %d\n",sockfd);
  }

  bzero(&addr,sizeof(addr));
  addr.sin_family=AF_INET;
  addr.sin_port=htons(PORT);
  addr.sin_addr.s_addr=htonl(INADDR_ANY);

  if(bind(sockfd,&addr,sizeof(addr)) < 0)
  {
    perror("connect");
    exit(2);
  }else
  {
    printf("connectd.\n");
    printf("local port:%d\n",PORT);
  }

  if(listen(sockfd,3) < 0)
  {
    perror("listen");
    exit(3);
  }else
  {
    printf("listenning...\n");
  }

  if(newsockfd=accept(sockfd,&addr,&addr_len) < 0)
  {
    perror("accept");
    exit(4);
  }else
  {
    printf("accept a new connect\n");
  }


  return 0;
}
