#include <stdio.h>

int main()
{
 int i=0; 
 int j=0;
 int arr[4][2]={0};
 int (*p)[2]={NULL};
 
 p=arr;

 arr[0][0]=1;
 p[0][1]=2;
// printf("arr[0][1]=%d\n",p[0][1]);
 //printf("arr[0][1]=%d\n",arr[0][1]);
 //(*(arr+1)[0])=3;
 (*(p+1)[0])=3;
 printf("arr[1][0]=%d\n",arr[1][0]);
 printf("arr[2]=%p\n",arr[2]);
 
  return 0; 
}
