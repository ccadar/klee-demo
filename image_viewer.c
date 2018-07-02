// clang -emit-llvm -c -g image_viewer.c
//
// klee --posix-runtime image_viewer.bc --sym-files 1 1024 A
// or below
// klee --posix-runtime image_viewer.bc --sym-files 1 1024 --sym-arg 1

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>

struct image_t {
  unsigned short magic;
  unsigned short h, sz; // height, size
  char pixels[1018];
};

int main(int argc, char** argv) {
  struct image_t img;
  assert(argc == 2);
  int fd = open(argv[1], O_RDONLY);
  read(fd, &img, 1024);
  close(fd);
  
  if (img.magic != 0xEEEE)
    return -1;
  if (img.h > 1024)
    return -1;
  unsigned short w = img.sz / img.h;
  
  return w;
}
