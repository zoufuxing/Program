#include <stdio.h>
#include <stdlib.h>

#define incr(v,low,high) \
 for ((v) = (low);(v) <= (high);(v)++)
int main()
{
  int j;
  incr(j,1,20);
  printf("%2d %6d\n",j,j*j*j); 
  return 0;
}
