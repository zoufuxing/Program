#include <stdio.h>

int main()
{
  int arr[] = {1,2,3,4,5,6,7,8,9,0};

  printf("sizeof(arr[]) = %d\n",sizeof(arr));
  printf("capacity arr[] = %d\n",sizeof(arr)/sizeof(int));

  return 0;
  
}

