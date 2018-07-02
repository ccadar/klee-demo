#include <assert.h>

#define N 800

int main() {
  char buf[N]; // symbolic
  
  klee_make_symbolic(buf, sizeof(buf), "buf");
  struct pkt1 { char x, y, v, w; int z; } *pa = (struct pkt1*) buf;
  struct pkt2 { unsigned i, j; } *pb = (struct pkt2*) buf;

  if (pa[2].v < 0) 
    assert(pb[2].i >= 1<<23);

  return 0;
}
