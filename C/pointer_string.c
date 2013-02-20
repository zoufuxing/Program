#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  char buffer[10];
  char *pbuffer = buffer;
  size_t index = 0;
  size_t i = 0;
  char j = 0;

  ///for(;index < sizeof(buffer);index++)
 /* for(;index < sizeof(buffer);i++)
  {
     if((*(pbuffer+index) = getchar()) == '\n' )
     {
 	*(pbuffer + index++) = '\0';
        break;
     }else
     {
	printf("*(pbuffer + index++) = %c\n",*(pbuffer + index++));
     }
  }

  if( (index == sizeof(buffer)) && ( (*(pbuffer+index-1)) != '0' ) )
  {
   printf("You ran out of space in the buffer.\n"); 
   return 1;
  }
*/


  printf("*(pbuffer) = %c\n",*(pbuffer));
  printf("*(pbuffer+1) = %c\n",*(pbuffer+1));
    
/*  for (i =0 ;i < sizeof(buffer);i++)
     printf("*(pbuffer + %d) = %c\n",i,*(pbuffer + i));
     //printf("buffer[%d] = %c\n",i,buffer[i]);
*/

  return 0;

}
