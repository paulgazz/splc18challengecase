#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#ifdef CONFIG_LBDAF
typedef uint64_t sector_t;
#else
typedef uint32_t sector_t;
#endif

sector_t blk_rq_pos() {
  return 0;
}

#ifdef CONFIG_AMIGA_Z2RAM
static void do_z2_request() {
  printf("bad access: block=%lu\n", blk_rq_pos()); // ERROR
  assert(sizeof(sector_t)==sizeof(uint32_t));
}
#endif

int main() {
  #ifdef CONFIG_AMIGA_Z2RAM
  do_z2_request();
  #endif
  return 0;
}

