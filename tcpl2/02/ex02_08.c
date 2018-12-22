unsigned rightrot(unsigned x, unsigned n)
{
	int wordlength(void);
	int rbits;

	#if 0
	if((n = n % wordlength()) > 0)
	{
	  rbits = ~(~0 << n) & x;
	  rbits =rbits << (wordlength() - n);
	  x = x >> 1;
	  x = x | rbits;
	}
	#else
	while (n-- > 0) 
	{
	  rbits = (x & 1) << (wordlength() - 1);
	  x = x >> 1;
	  x = x | rbits;
	}
	#endif
    return x;
}

int wordlength(void)
{
  int i;
  unsigned v = (unsigned) ~0;

  for(i = 1; (v = v >> 1) > 0; i++)
	;
  return i;
}
/* main driver added, in a hurry while tired, by RJH. Better test driver suggestions are welcomed! */

#include <stdio.h>

int main(void)
{
  unsigned x;
  int n;

  for(x = 0; x < 9; x += 1)
    for(n = 1; n < 8; n++)
      printf("%u, %d: %u\n", x, n, rightrot(x, n));
  return 0;
}


