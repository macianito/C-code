#include <stdio.h>
#include <string.h>


#include "./libs/strings.h"
#include "./libs/funcs.h"

int main () {

   char str1[12] = "Hello";
   char str2[12] = "World";
   char str3[12];
   int  len ;
   int  num1 = 30, num2 = 40, maxn = 0;

   /* copy str1 into str3 */
   strcpy(str3, str1);
   printf("strcpy( str3, str1) :  %s\n", str3 );

   /* concatenates str1 and str2 */
   strcat( str1, str2);
   printf("strcat( str1, str2):   %s\n", str1 );

   /* total lenghth of str1 after concatenation */
   len = strlen(str1);
   printf("strlen(str1) :  %d\n", len );
   
   maxn = max(num1, num2);
   printf("Max value is :  %d\n", maxn );
   
   concat_strings(3, "str1 ", "str2 ", "str3 ");
   
   printf("\n");
   
   modify_str(str2);
           
   printf("Modified str2 is :  %s\n", str2);
   
   getchar();

   return 0;
}


