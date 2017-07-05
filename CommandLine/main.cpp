#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h> // https://github.com/gcc-mirror/gcc/blob/master/include/getopt.h

/* Flag set by `--verbose'. */
static int verbose_flag;

static struct option long_options[] = {
    /* This option set a flag. */
    {"verbose", no_argument,       &verbose_flag, 1},
    /* These options don't set a flag.
       We distinguish them by their indices. */
    {"blip",    optional_argument, 0, 'b'},
    {"slip",    no_argument,       0, 's'},
    {0,         0,                 0,  0}
};

struct options {
  char* b = NULL;
  unsigned char s = 0;       
};
    
/* getopt_long stores the option index here. */
int option_index = 0;

// https://stackoverflow.com/questions/498320/pass-arguments-into-c-program-from-command-line
// https://linux.die.net/man/3/getopt_long
// https://stackoverflow.com/questions/9996130/command-line-args-in-c-program-using-netbeans

int main (int argc, char *argv[]) {
    
  options opts;  
    
  while (1) {

    // el : es en cas d'arguments
    int c = getopt_long (argc, argv, "b:s", long_options, &option_index); 

    /* Detect the end of the options. */
    if(c == -1)
       break;

    switch (c) {
      case 'b':
        //puts ("option -b");
        //if (optarg)
        //  printf (" with arg %s", optarg);
        
        opts.b = strdup(optarg);
      break;
      case 's':
        //puts ("option -s");
        opts.s = 1;
      break;

      default:;
        //abort();
    }
    
    printf("\n");
  }

  if (verbose_flag)
    puts ("verbose flag is set");

  /* Print any remaining command line arguments (not options). */
  /* if (optind < argc) {
      
      printf ("non-option ARGV-elements: ");
      
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      
      putchar ('\n');
  
  } */
  
  // Aqui escribim el codi nostre
  if(opts.b != NULL) {
      printf ("option: b with arg %s\n", opts.b);
  }
  if(opts.s) {
      printf ("option: s\n");
  }
  
  puts("Enter a character");
  getchar();
  
  //exit(0);

  return 0;
}


