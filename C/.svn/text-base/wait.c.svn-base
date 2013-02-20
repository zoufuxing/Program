#include <stdio.h>
#include <unistd.h>

int main()
{
  char sharp[4]={'|','\\','-','/'};
  int i=0;

  do{
    sleep(1);
    printf("%c\n",sharp[i]);
    fflush(stdout);
    ++i;
    i=( (i>3) ? 0 : i );
  }while(1);
  
  return 0;
}
