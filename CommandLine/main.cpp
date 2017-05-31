#include <stdio.h>
#include <stdlib.h>
#include <getopt.h> // https://github.com/gcc-mirror/gcc/blob/master/include/getopt.h

/* Flag set by `--verbose'. */
static int verbose_flag;

static struct option long_options[] = {
    /* This option set a flag. */
    {"verbose", no_argument,       0, 1},
    /* These options don't set a flag.
       We distinguish them by their indices. */
    {"blip",    optional_argument, 0, 'b'},
    {"slip",    no_argument,       0, 's'},
    {0,         0,                 0,  0}
};
    
/* getopt_long stores the option index here. */
int option_index = 0;

// https://stackoverflow.com/questions/498320/pass-arguments-into-c-program-from-command-line
// https://linux.die.net/man/3/getopt_long
// https://stackoverflow.com/questions/9996130/command-line-args-in-c-program-using-netbeans

int main (int argc, char *argv[]) {
  while (1) {

    int c = getopt_long (argc, argv, "b:s", long_options, &option_index);

    /* Detect the end of the options. */
    if(c == -1)
       break;

    switch (c) {
      case 0:
        /* If this option set a flag, do nothing else now. */
        if (long_options[option_index].flag != 0) break;
        printf("option %s", long_options[option_index].name);
        if (optarg)
          printf(" with arg %s", optarg);
        break;
      case 'b':
        puts ("option -b");
        if (optarg)
          printf (" with arg %s", optarg);
        break;
      case 's':
        puts ("option -s");
        break;
      case '?':
        /* getopt_long already printed an error message. */
        break;

      default:
        abort ();
    }
    
    printf("\n");
  }

  if (verbose_flag)
    puts ("verbose flag is set");

  /* Print any remaining command line arguments (not options). */
  if (optind < argc) {
      
      printf ("non-option ARGV-elements: ");
      
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      
      putchar ('\n');
  
  }
  
  puts("Enter a character");
  
  getchar();
  
  exit(0);

  return 0;
}