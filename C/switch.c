#include <stdio.h>
#include <math.h>
#define MATH #include <math.h>
#define BACKSLASH #define ASTERISK *

int main()
{
  char answer=0;
/*  int a = -23;
  int b; 
  float c;
  

  b = abs(a);
  c = log(b);
  printf("b = %d\n",b);
  printf("c = %f\n",c);
*/  
//  printf("__STDC__HOSTED__ = %d\n",__STDC__HOSTED__);
  printf(__TIME__);
  printf("\n");
  int a =  __STDC__;
  printf("a = %d\n",a);

  printf("Enter Y or N: ");
  scanf(" %c",&answer);

  switch(answer)
  {
   case 'y':case 'Y':
   printf("You input yes\n");
   break;

   case 'n':case 'N':
   printf("You input no\n");
   break;

   default:
   printf("You choose default\n");
   break;
  }
}
