#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE 1024

int main()
{
  char buf[MAX_LINE];
  FILE *fp;
  int len,count;
  
  if((fp=fopen("/root/skomart.log","r")) == NULL){
    perror("fail to read");
    exit(1);
  }
 
  while(fgets(buf,MAX_LINE,fp) != NULL ){
   len=strlen(buf);
   buf[len - 1]='\0';
   count++;
   printf("%s %d\n",buf,len - 1);
 }
   printf("%d\n",count);
  return 0;
}
