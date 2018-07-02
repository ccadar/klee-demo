#include <stdio.h>

int main() {
  int x;
  klee_make_symbolic(&x, sizeof(x), "x");
  
  if (x > 0)
    printf("x\n");
  else printf("x\n");
  
  return 0;
}
