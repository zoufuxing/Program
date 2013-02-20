#include <stdio.h>
#include <stdlib.h>

int main()
{
  int chose=0;
  int count=0;
  printf("The value rand is %d\n",RAND_MAX);
  for(;;){
  chose = rand();
  printf("chose=%d\n",chose);
  sleep(1);
  count++;
  if(chose == 123){
   printf("you have loop count=%d\n",count);
   break;
   }
  }
}
