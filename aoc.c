#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef uint64_t u64;
typedef int64_t i64;
typedef uint32_t u32;
typedef int32_t i32;
typedef uint8_t u8;
typedef int8_t i8;

i64 parse(u8 * p, i64 n) {
  i64 r = 0;
  for (i64 i = 0; i < n; ++i) {
    r = 10 * r + (p[i] - '0');
  }
  return r;
}

extern u8 _binary_input1_txt_start[];
extern u8 _binary_input1_txt_end[];

void p1(void) {
  i64 n = _binary_input1_txt_end - _binary_input1_txt_start - 1;
  i64 *d = calloc(n, sizeof(i64));
  for (i64 i = 0; i < n; ++i) {
    d[i] = parse(_binary_input1_txt_start + i, 1);
  };
  i64 x = 0;
  i64 y = 0;
  i64 m = n / 2;
  for (u64 i = 0; i < n; ++i) {
    i64 a = d[ i         ];
    i64 b = d[(i + 1) % n];
    i64 c = d[(i + m) % n];
    if (a == b) { x += a; }
    if (a == c) { y += a; }
  }
  printf("1.1: %d\n", (int) x);
  printf("1.2: %d\n", (int) y);
  free(d);
}

int main(void) {
  p1();
  return 0;
}
