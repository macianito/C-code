#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

char* concat_strings(int num,...) { // TODO acabar conversions tipus
  
   va_list valist;
   int i, len = 0;
   char* argi;
   char* straux;

   /* initialize valist for num number of arguments */
   va_start(valist, num);

   /* access all the arguments assigned to valist */
   for (i = 0; i < num; i++) {
      //printf("%s", va_arg(valist, int));
       argi = (char*)va_arg(valist, int);
       len = len + (strlen(argi) - 1);
       
       //printf("%d#", (strlen(argi) - 1));
   }
   
   /* clean memory reserved for valist */
   va_end(valist);
   
   
   straux = (char *)calloc(len + 1, 1);
   
   if (straux == NULL) return NULL;
   
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

char** explode(const char a_del, char* str) { // https://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c

   int slen = strlen(str), i,
       numTokens = 0; // num cadenes
   
   char del[2];
   del[0] = a_del;
   del[1] = 0;
   
   char lastchar = del; // ultim caracter
   
   for (i = 0; i < slen; i++) {
       
     if(str[i] == del[0] && lastchar != del[0]) {
        ++numTokens;
     }
     
     lastchar = str[i];
       
   }
   
   if(lastchar != del[0]) {
       ++numTokens;
   }
   
   //printf("%d ", numTokens);
   
   char** arrayStrings = (char **)malloc(sizeof(char*) * numTokens);
   
   i = 0;
   
   if (arrayStrings) {
       
       char* token = strtok(str, del);
       
       while( token != NULL ) {
         printf( " %s\n", token );
         token = strtok(0, del);
         
         arrayStrings[i++] = strdup(token);
         
       }

//         arrayStrings[numTokens] = (char *)malloc(strlen(buff) + 1);
//         strcpy(arrayStrings[numTokens], buff);
   
   }
   
   return arrayStrings;
    
}

// http://www.cplusplus.com/reference/cstring/strtok/
// https://stackoverflow.com/questions/7652293/how-do-i-dynamically-allocate-an-array-of-strings-in-c
/* char** explode(char del, char* str) { 
    
    int slen = strlen(str), i, j,
        numTokens = 0; // inicialment 1 token
    
    char buff[slen + 1]; // reservem tota la llargaria de l'string
    char** arrayStrings = (char **)malloc(sizeof(char*));
    
    j = 0; // index de la subcadena
    
    for (i = 0; i < slen; i++) {
    
      if(str[i] == del) {
         
         buff[j] = '\0';
         
         if(strlen(buff) == 0) { // dos delimitadors contigus
           continue;
         }
         
         arrayStrings[numTokens] = (char *)malloc(strlen(buff) + 1);
         
         strcpy(arrayStrings[numTokens], buff);
         
         printf("%s ", arrayStrings[numTokens]);
         
         if(i != slen-1) { // no es l'ultim o sigui afegim nova cadena
           ++numTokens;
           arrayStrings = (char**)realloc(arrayStrings, sizeof(char *) * numTokens);
         }

         j = 0;
         
         //printf("%s ", buff);
         
      } else {
        
        buff[j] = str[i]; // anem afegint caracters
        
        j = j + 1;
        
        if(i == slen-1)  { // es l'ultim caracter
        
          buff[j] = '\0';
          
          arrayStrings[numTokens] = (char *)malloc(strlen(buff) + 1);
          
          strcpy(arrayStrings[numTokens], buff);
        
          printf("%s ", arrayStrings[numTokens]);
          
        }
        
      }
    
    }
    
    return NULL;
    
    return arrayStrings;
    
} */

// retorna mida d'un array d'strings
int array_strings_size(char** array) {
  return sizeof(array) / sizeof(char*);
}
