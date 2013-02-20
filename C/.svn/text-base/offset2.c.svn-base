#include <stdio.h>

int main(void)
{
 unsigned int original = 0xABC;
 unsigned int result=0;
 unsigned int mask=0xF;

 printf("\n original = %X",original);
 printf("\n shijinzhi  original = %d",original);

 result |= original&mask;
 printf("frist offset result = %X",result);

 original >>= 4;
 printf("\n frist offset original = %X",original);
 result <<= 4;
 printf("\n result = %d",result);
 result |= original&mask;
 printf("original&mask = %X\n",original&mask);
 printf("after offset result = %d\n",result);

 original >>= 4;
 result <<= 4;
 result |= original&mask;

 printf("\t result = %X\n",result);
 return 0;
}
