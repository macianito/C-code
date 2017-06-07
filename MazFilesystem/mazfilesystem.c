#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h> // http://pubs.opengroup.org/onlinepubs/007908775/xsh/dirent.h.html

#include "./myboolean.h"


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

char* file_get_contents(char* path) {
    
   FILE *fp;
   char* buff;
   int fsize = filesize(path);
   
   buff = malloc(fsize + 1);
   
   if (buff == NULL) return -1;
   
   fp = fopen(path, "r");
   fgets(buff, fsize, fp);
   
   fclose(fp);
   
   //printf("%s", buff);
   
   return buff;

}

int filesize(char* filename) {

   int size = 0;
   
   struct stat st;
   stat(filename, &st);
   size = st.st_size;

   return size;
   
}

int file_put_contents(char* path, char* contents) {
  
   FILE *fp;
    
   fp = fopen(path, "w+");
   // fprintf(fp, "This is testing for fprintf...\n");
   fputs(contents, fp);
   fclose(fp);
   
   return 0;
   
}


bool is_file(const char* path) {
    struct stat buf;
    stat(path, &buf);
    return S_ISREG(buf.st_mode);
}

bool is_dir(const char* path) {
    struct stat buf;
    stat(path, &buf);
    return S_ISDIR(buf.st_mode);
}

void scandir(char* path) {
    
  DIR *dir;
  struct dirent *dent;
  //char path[50];
  // char current_dir[] = "C:/Intel";
  char aux_path[220] = "";

  //strcpy(path, folder);
  dir = opendir(path);   //this part
  
  if(dir != NULL) {
    while((dent = readdir(dir)) != NULL)
      //puts(dent->d_name);

      if(strcmp(dent->d_name, ".") != 0 && strcmp(dent->d_name, "..") != 0) {
        strcpy(aux_path, path);
        strcat(aux_path, "/");
        strcat(aux_path, dent->d_name);
        printf("Aux path %s.\n", aux_path);
      }

      
      
      printf("Is %s a file? %s.\n", aux_path,
        (is_file(aux_path) == 1) ? "Yes" : "No");
  }
  
  closedir(dir);

}
