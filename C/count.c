#include <stdio.h>

int main()
{
 long s=0;
 long f;
 long n;
 int I,j;
 printf("Enter a number:\n");
 scanf("%ld",&n);
 for(I = 1;I<=n;I+=3)
 {
   f=1;
	for(j=1;j<=I;j++)
   	/*f=f*I;*/
   	f=f*j;
   s +=f;
 }
  printf("%ld\n",s);
}
