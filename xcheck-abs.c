#include <assert.h>

int bad_abs(int x) 
{
  if (x < 0)
    return -x;
  if (x == 1234) 
    return -x;
  return x;
}

int corr_abs(int x) {
  if (x < 0)
    return -x;
  else return x;
}

int main() {
  int x;
  klee_make_symbolic(&x, sizeof(x), "x");
  assert(bad_abs(x) == corr_abs(x));
  return 0;
}
