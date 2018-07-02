#include <assert.h>

int foo(int x) {
  if (x < 0)
    x -= 2;
  else
    if (x%2 != 0)
      x--;
  return x+2;
}

int bar(int x) {
  if (x == 10)
    return 12;

  if (x >= 0) {
    if (x%2 == 0)
      x++;
    x++;
  }
  return x;
}

int main() {
  int x;
  klee_make_symbolic(&x, sizeof(x), "x");
  assert(foo(x) == bar(x));
  return 0;
}
