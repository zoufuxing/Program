#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
   FILE *fp1;
   FILE *fp2;
   FILE *fp3;

   int t1,t2;
 
   if(argc != 4)
   {
     printf("The number of arguments not correct!\n");
     exit(1);
   }

   if((fp1=fopen(argv[1],"r")) == NULL)
   {
     printf("%s is't open\n",argv[1]);
     exit(1);
   }

   if((fp2=fopen(argv[2],"r")) == NULL)
   {
     printf("%s is't open\n",argv[2]);
     exit(1);
   }

   if((fp3=fopen(argv[3],"w")) == NULL)
   {
     printf("%s is't write\n",argv[3]);
     exit(1);
   }

   fread(&t1,sizeof(int),1,fp1);
   fread(&t2,sizeof(int),1,fp2);


   while(!feof(fp1) && !feof(fp2))
   {
     if(t1<t2)
     {
      fwrite(&t1,sizeof(int),1,fp3);
      fread(&t1,sizeof(int),1,fp2);
     }else
     {
      fwrite(&t2,sizeof(int),1,fp3);
      fread(&t2,sizeof(int),1,fp2);
     }
   }


   while(!feof(fp1))
   {
     fwrite(&t1,sizeof(int),1,fp3);
     fread(&t1,sizeof(int),1,fp1);
   }


   while(!feof(fp2))
   {
     fwrite(&t2,sizeof(int),1,fp3);
     fread(&t2,sizeof(int),1,fp2);
   }

  fclose(fp1);
  fclose(fp2);
  fclose(fp3);

  return 0;

}
