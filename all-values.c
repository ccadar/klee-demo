// clang -emit-llvm -c -g all-values.c
// klee all-values.bc

int foo(unsigned k) {
  int a[4] = {3, 1, 0, 4};
  k = k % 4;
  return a[a[k]];
}

int main() {
  int k;
  klee_make_symbolic(&k, sizeof(k), "k");
  return foo(k);
}
