#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

unsigned long get_sp(void) {
  __asm__("movl %esp,%eax");
}

void usage() {
  fprintf(stderr, "usage: spoffset [-x] offset\n");
}

int main(int argc, char **argv) {
  int printhex = 0;
  char oc;

  while ((oc = getopt(argc, argv, "x")) != -1) {
    switch(oc) {
    case 'x':
      printhex = 1;
      break;
    default:
      usage();
      return 1;
    }
  }

  if (argc != optind + 1) {
    usage();
    return 1;
  }

  long offset = atol(argv[optind]);

  unsigned long sp = get_sp();
  unsigned long addr = sp - offset;

  if (printhex) {
    printf("0x%lx\n", addr);
  }
  else {
    char bytes[4] = {(char) addr,
                     (char) (addr >> 8),
                     (char) (addr >> 16),
                     (char) (addr >> 24)};
    fwrite(bytes, 1, 4, stdout);
  }
  return 0;
}
