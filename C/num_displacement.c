#include <stdio.h>

int main()
{
  unsigned a,b,c,d;
  scanf("%o",&a);
  b=a>>4;
  printf("b=%o\n",b);
  c=~(~0<<4);
  d=b&c;
  printf("%o\n%o\n",a,d);
  return 0;
}
