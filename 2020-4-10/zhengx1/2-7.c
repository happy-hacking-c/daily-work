#include <stdio.h>

int bitlen(unsigned d);
unsigned invert(unsigned x, unsigned p, unsigned n);

int main() {
  printf("invert(5, 1, 1) -> %u\n", invert(5, 1, 1));
  printf("invert(8, 2, 1) -> %u\n", invert(8, 2, 1));
}


unsigned invert(unsigned x, unsigned p, unsigned n) {
  return x ^ (~(~0 << n) << (p + 1 - n));
}