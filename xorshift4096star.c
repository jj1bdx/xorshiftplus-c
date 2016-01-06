/*  Written in 2014 by Sebastiano Vigna (vigna@acm.org)

To the extent possible under law, the author has dedicated all copyright
and related and neighboring rights to this software to the public domain
worldwide. This software is distributed without any warranty.

See <http://creativecommons.org/publicdomain/zero/1.0/>. */

#include <stdint.h>

/* While you can use this generator, we rather suggest to use a
   xorshift1024* generator. */

/* The state must be seeded so that it is not everywhere zero. If you have
   a 64-bit seed,  we suggest to seed a xorshift64* generator and use its
   output to fill s. */

uint64_t s[ 64 ];
int p;

uint64_t next(void) { 
	uint64_t s0 = s[ p ];
	uint64_t s1 = s[ p = ( p + 1 ) & 63 ];
	s1 ^= s1 << 25; // a
	s1 ^= s1 >> 3;  // b
	s0 ^= s0 >> 49; // c
	return ( s[ p ] = s0 ^ s1 ) * 8372773778140471301LL; 
}
