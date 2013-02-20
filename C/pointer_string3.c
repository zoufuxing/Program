#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*const size_t BUFFER_LEN = 128;
const size_t NUM_P = 100; */
#define BUFFER_LEN 128
#define NUM_P 100

int main(void)
{
  char buffer[BUFFER_LEN];  /* Input buffer */
  char *pS[NUM_P] = { NULL }; /* Array of string pointers */
  char *pbuffer = buffer;   /* Pointer to buffer */
  int i = 0;                /* Loop counter */

  printf("\nYou can enter up to %u messages each up to %u characters.",NUM_P,BUFFER_LEN);

  for(i = 0;i < NUM_P;i++)
  {
     pbuffer = buffer;
     printf("\nEnter %s message,or press Enter to end\n",i > 0 ? "another" : "a");

     /* Read a string of up to BUFFER_LEN characters */
     while((pbuffer - buffer < BUFFER_LEN - 1) && ((*pbuffer++ = getchar()) != '\n'));

     /* check for empty line indicating end of input */
     if((pbuffer - buffer) < 2)
       break;

     /* check for string too long */
    if((pbuffer - buffer) == BUFFER_LEN && *(pbuffer - 1) != '\n')
    {
      printf("String too long - maximum %d characters allowed.",BUFFER_LEN);
      i--;
      continue;
    }

     *(pbuffer - 1) = '\0'; /* Add terminator */

    pS[i] = (char*)malloc(pbuffer - buffer);

    if(pS[i] == NULL)
    {
       printf("\nOut of memory - ending program.");
       return 1;
    }

    /* Copy string from buffer to new memory */
    strcpy(pS[i],buffer);
  }
  
    printf("In reverse order,the strings you entered are:\n");

    while(--i >= 0)
   {
     printf("%s\n",pS[i]);
     free(pS[i]);
     pS[i] = NULL;
   }

  return 0;
}
