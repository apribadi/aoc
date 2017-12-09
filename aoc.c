#include <stdint.h>
#include <stdio.h>
#include "input1.c"

typedef uint64_t u64;
typedef int64_t i64;
typedef uint8_t u8;
typedef int8_t i8;

i64 digit(u8 c) {
  return (i64) (c - 0x30);
}

void p1(void) {
  u8* d = input1_txt;
  i64 n = input1_txt_len - 1;
  i64 x = 0;
  i64 y = 0;
  i64 m = n / 2;
  for (u64 i = 0; i < n; ++i) {
    i64 a = digit(d[ i         ]);
    i64 b = digit(d[(i + 1) % n]);
    i64 c = digit(d[(i + m) % n]);
    if (a == b) { x += a; }
    if (a == c) { y += a; }
  }
  printf("1.1: %d\n", (int) x);
  printf("1.2: %d\n", (int) y);
}

int main(void) {
  p1();
  return 0;
}
