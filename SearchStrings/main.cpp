#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h> // http://pubs.opengroup.org/onlinepubs/007908775/xsh/dirent.h.html
#include <sys/types.h>
#include <sys/stat.h>

#include "./filesystem.h"

#include <getopt.h> // https://github.com/gcc-mirror/gcc/blob/master/include/getopt.h



struct Options {
    char *extensions = NULL;
    char *path = NULL;
    char *type = NULL;
} ops;

static struct option long_options[] = {
    /* This option set a flag. */
    /* These options don't set a flag.
       We distinguish them by their indices. */
    {"extensions", required_argument, 0, 'e'},
    {"path",       required_argument, 0, 'p'},
    {"type",       required_argument, 0, 't'},
    {0, 0, 0, 0}
};
    
/* getopt_long stores the option index here. */
int option_index = 0;

// https://stackoverflow.com/questions/498320/pass-arguments-into-c-program-from-command-line
// https://linux.die.net/man/3/getopt_long
// https://stackoverflow.com/questions/9996130/command-line-args-in-c-program-using-netbeans

int main (int argc, char *argv[]) {
    
  DIR *dir;
  struct dirent *dent;
  char path[50];
  char current_dir[] = "C:/Intel";
  char aux_path[220] = "";
  
  while (1) {

    int c = getopt_long (argc, argv, "e:pt", long_options, &option_index);

    /* Detect the end of the options. */
    if(c == -1)
       break;

    switch (c) {

      case 'e':
        //puts ("option -e extension");
        if (optarg)
          ops.extensions = optarg;
      break;
      case 'p':
        //puts ("option -p path");
        if (optarg)
          ops.path = optarg;
      break;
      case 't':
        //puts ("option -s type");
      break;

      default:
        abort ();
    }
    
    printf("\n");

  }
  
  strcpy(path, current_dir);
  dir = opendir(path);   //this part
  
  if(dir != NULL) {
    while((dent = readdir(dir)) != NULL)
      //puts(dent->d_name);

      if(strcmp(dent->d_name, ".") != 0 && strcmp(dent->d_name, "..") != 0) {
        strcpy(aux_path, current_dir);
        strcat(aux_path, "/");
        strcat(aux_path, dent->d_name);
        printf("Aux path %s.\n", aux_path);
      }

      
      
      printf("Is %s a file? %s.\n", aux_path,
        (is_file(aux_path) == 1) ? "Yes" : "No");
  }
  
  closedir(dir);
  
  puts("Enter a character");
  
  getchar();
  
  exit(0);

  return 0;
}