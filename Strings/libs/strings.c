#include <stdarg.h>
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// https://www.tutorialspoint.com/cprogramming/c_variable_arguments.htm

//char* concat_strings(int num,...) {
void concat_strings(int num,...) {
   
   va_list valist;
   int i;

   /* initialize valist for num number of arguments */
   va_start(valist, num);

   /* access all the arguments assigned to valist */
   for (i = 0; i < num; i++) {
      printf("%s", va_arg(valist, int));
   }
	
   /* clean memory reserved for valist */
   va_end(valist);
;
}

void modify_str(char *str) { // equivalent char str[]
    
    printf("Inside modify :  %c\n", str[2]);
    
    str[2] = str[0];
    
}

