#include <stdarg.h>
#include <stdlib.h>

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

char* concat_strings(int num,...) {
  
   va_list valist;
   int i, len = 0;
   char* argi;
   char* straux;

   /* initialize valist for num number of arguments */
   va_start(valist, num);

   /* access all the arguments assigned to valist */
   for (i = 0; i < num; i++) {
      //printf("%s", va_arg(valist, int));
       argi = va_arg(valist, int);
       len = len + (strlen(argi) - 1);
       
       //printf("%d#", (strlen(argi) - 1));
   }
   
   /* clean memory reserved for valist */
   va_end(valist);
   
   
   straux = (char *)calloc(len + 1, 1);
   
   if (straux == NULL) return -1;
   
   //strcpy(straux, ""); // iniciem cadena perque el que hi ha a dins es indeterminat
   
   /* initialize valist for num number of arguments */
   va_start(valist, num);
   
   for (i = 0; i < num; i++) {
      //printf("%s", va_arg(valist, int));
      argi = va_arg(valist, int);
      strcat(straux, argi);
   }
   
   /* clean memory reserved for valist */
   va_end(valist);
   
   
   //printf("%s", straux);
   
   
   return straux;

}

