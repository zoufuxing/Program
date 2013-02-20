#include <stdio.h>
#include <ctype.h>

#define MAX 20

int main()
{
  char intput_char[MAX]={0};
 // while(1)
 // {
     //scanf(" %c",&intput_char);
     scanf(" %s",&intput_char);
     /*if(islower(intput_char))
     {
     printf("intput_char is a lower char\n");
     }else{
     printf("intpu_char is not a lower char\n");
     }
   char output_char=toupper(intput_char);*/
   char output_char[MAX];
   int i=0;
   int array_max=sizeof(intput_char);
   printf("%d\n",array_max);
   for(i=0;i<sizeof(intput_char);i++)
   {
     printf("Touppper %c\n",intput_char[i]);
     output_char[i] = toupper(intput_char[i]);
     printf("output_char[%d]=%c\n",i,output_char[i]);
   }
   printf("output_char=%s\n",output_char);
   
 // }
  return 0;
}
