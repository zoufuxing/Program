#include <stdio.h>

int main()
{
  int day;
  
  for(day = 1;day <= 7;day++)
  {
    if(day == 3)
    {
    printf("continue\n");
    continue;
    }
    printf("day = %d\n",day);
  }

  return 0;
}
