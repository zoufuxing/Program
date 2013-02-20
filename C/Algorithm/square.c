#include <stdio.h>
#include <math.h>

int main()
{
  int i,j,m,n,a[30][30];
  printf("Please input a odd number(n).\n");
  scanf("%d",&n);
  
  while(n % 2 == 0)
  {
   printf("You should input a add number.\n");
   printf("Input a odd number\n"); 
   scanf("%d",&n);
  }

  m = (n + 1) / 2;
  
  for(i = 0;i <= n;i++){
   for(j = 0;j <= n;j++){
    if(i+j <= n + 1 && i <= j || i+j >= n+1 && i >= j)
      a[i][j] = m - abs(m - j);
   
    if(i+j < n+1 && i > j || i+j > n+1 && i < j)
      a[i][j] = m - abs(m - i);
    }
  }

  printf("%d square is :\n",n);
 
  for(i = 1;i <= n; i++)
  {
   for(j = 1;j <= n; j++)
    printf("%3d ",a[i][j]);
   
   printf("\n");
  } 

  return 0;

}
