#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 9527
#define MAX 100

int main()
{
  int sockfd,newsockfd,is_connect[MAX],fd;
  struct sockaddr_in addr;
  int addr_len=sizeof(struct sockaddr_in);
  fd_set myreadfds;
  char msgbuffer[200];
  char msg[]="This is the message from server.Connected.\n";
  if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0 )
  {                           
    perror("socket");
    exit(1);
  }
  else
  {
    printf("socket created .\n");
    printf("socket id : %d",sockfd);
  }

  bzero(&addr,sizeof(addr));
  
  addr.sin_family=AF_INET;
  addr.sin_port=htons(PORT);
  addr.sin_addr.s_addr=htonl(INADDR_ANY);

  if(bind(sockfd,&addr,sizeof(addr)) < 0)
  {
    perror("connect.\n");
    exit(1);
  }
  else
  {
    printf("connected.\n");
    printf("bind port is %d\n",PORT);
  }

  if(listen(sockfd,3) < 0)
  {
    perror("listen");
    exit(1);
  }
  else
  {
    printf("Listenning port %d\n",PORT);
  }

  return 0;
}
