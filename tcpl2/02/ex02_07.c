unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0U << n) << (p+1-n));
}

/* main driver added, in a hurry while tired, by RJH. Better test driver suggestions are welcomed! */

#include <stdio.h>

int main(void)
{
  unsigned x;
  int p, n;

  for(x = 0; x < 4; x += 1)
    for(n = 1; n < 4; n++)
      for(p = 1; p < n+1; p++)
        printf("%u, %d, %d: %u\n", x, n, p, invert(x, n, p));
  return 0;
}


