#include <stdio.h>

int main()
{
  int i,a[] = {1,2,3,4,5,6},b[] = {7,8,9};
  int q = 50;
  //int *const pa = a;
  //int const *pa = &q;
  const int *pa = &q;
  printf("Before *pa = %d\n",*pa);
  //const int *pa = a;
  q = 80;
  //*pa = 90;
  printf("After *pa = %d\n",*pa);
  /*for(i = 0;i < (sizeof(a)/sizeof(int));i++)
  {
   printf("a[%d] = %d\n",i,a[i]);
   printf("pa[%d] = %d\n",i,pa[i]);
   pa++;
   //printf("*pa = %d in the for loop\n",*pa);
  } */
  //printf("*pa = %d\n",*pa); 

  //const int j = 40;
  /*int const j = 40;
  int k = 80;

  //int *pa = &j;
  int *pa = NULL;
  pa = &j;
  printf("*pa = %d\n",*pa);
  
  *pa = 50; 
  printf("j = %d\n",j);
  
  pa = &k;
  printf("*pa = %d\n",*pa);

 // int *z = MAX;
  //printf("*z = %d\n",*z);
  */
}
