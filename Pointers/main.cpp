#include <stdio.h>

int main () {

   int  var1;
   char var2[10] = "Caqueta";
   char *p1;
   
   p1 = var2;

   printf("Address of var1 variable: %x\n", &var1  );
   printf("Address of var2 variable: %x\n", var2  );
   printf("Address of var2 variable: %x\n", &var2  );

   return 0;
}