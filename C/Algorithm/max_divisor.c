#include <stdio.h>


int main()
{
 int k,n;
 long a,b,c,r,m[100];
 printf("Please input the number of integer --> n: ");
 scanf("%d",&n); 

 printf("Please enter the number --> k: ");
 for(k = 0;k <= n-1;k++)
 {
   printf("Please input the %dth interger\n",k+1);
   scanf("%ld",&m[k]);
 }
 

 b = m[0];

 for(k = 0;k <= n-1;k++)
 {
   a = m[k];
   if(a<b)
    {c = a;a = b;b = c;}

   r = a%b;
   while(r != 0) 
   {
     a = b;b = r;
     r = a%b;
   }

 }

 printf("The max divisor is %ld\n",m[0]);
 
  return 0;
}
