#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("sizeof(255.255.255.255)= %d\n",sizeof("255.255.255.255"));
  printf("sizeof(size_t)= %d\n",sizeof("size_t"));
  return 0;
} 
