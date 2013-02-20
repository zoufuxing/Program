#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  FILE *pfile;
  pfile=fopen("test.txt","w");
  fwrite("FreeBSD C Program\n",1,strlen("FreeBSD C Program\n")+1,pfile);
  fflush(pfile);
  /*
  fseek(pfile,0,SEEK_SET);
  fwrite("That's a test program\n",1,strlen("That's a test program\n")+1,pfile);

  fflush(pfile);
  */
  return 0;
}
