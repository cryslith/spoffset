#include <stdlib.h>
#include <stdio.h>

unsigned long get_sp(void) {
  __asm__("movl %esp,%eax");
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: spoffset offset\n");
    return 1;
  }

  long offset = atol(argv[1]);

  unsigned long sp = get_sp();
  printf("0x%lx\n", sp - offset);
  return 0;
}
