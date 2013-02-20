#include <stdio.h>

int main()
{
  int c,j,m,n,f[10];
  long d,k,g1,g2,s1,s2,t;
  printf("Please input m,n:\n");
  scanf("%d,%d",&m,&n);
  
  t = 1;

  for(k = 1;k <= n-1;k++)
    t = t * 10;

  printf("t = %d\n",t);

  g1 = 0;s1 = 0;
  g2 = 0;s2 = 0;

  for(k = t;k <= 10*t -1;k++)
  {
    d = k;
    printf("d = %d\n",d);
    for(j = 0;j <=9;j++ )
       f[j] = 0;

    for(j = 1;j <= n;j++)
    {
	c = d % 10;
  	printf("c = %d\n",c);
    	f[c]+= 1;
  	printf("f[%d] = %d\n",c,f[c]);
	d = d /10;
	printf("d = %d\n",d);
	sleep(1);
    }

   if(f[m] > 0 && k%m > 0)
    {g1++;s1+=k;}
  
   if(f[m] == 2 && k%m > 0)
    {g2++;s2+=k;}
  }

  printf("m = %d,n = %d,g1 = %d\n",m,n,g1);
  printf("s1 = %d\n",s1);

  printf("g2 = %d,s2 = %d\n",g2,s2);

  return 0;
}
