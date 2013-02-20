#include <stdio.h>

int FindMax(int score[],int n);
int CountFail(int score[],int n);

int main()
{
  int i,score[20],max,count;
  for(i=0;i<20;i++)
  {
    scanf("%d",&score[i]);
  }
  max = FindMax(score,20); 
  printf("array test address is %d\n",score);
  printf("max = %d\n",max);
  count = CountFail(score,20);
  printf("count = %d\n",count);
}

int FindMax(int score[],int n)
{
   int max,i;
   max = score[0];
   for(i=0;i<20;i++)
   {
     if(score[i]>max) max=score[i];
   }
   return max;
}

int CountFail(int score[],int n)
{
   int count,i;
   count = 0;
   for(i=0;i<20;i++)
   {
     if(score[i] < 60) count++;
   }
   return count;
}
