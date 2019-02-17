#include <stdio.h>
#include <stdlib.h>

int main(){

   char str2[] = "practice\0";
   char str3[] = {'p','r','a','c','t','i','c','e','\0'};

   for (char *ch = str2; *ch != '\0'; ch++){
       printf("%s\n", ch);
   }

   for(char *ch = str3; *ch!='\0'; ch++){
       printf("%s\n",ch);
   }

   char *ch2 = str3;
   printf("%c\n", *ch2);

   char ch = 'c';
   char *ptr = &ch;
   char *ptr2 = *ch;


   return 0;
}