/*  Written in 2014 by Sebastiano Vigna (vigna@acm.org)

To the extent possible under law, the author has dedicated all copyright
and related and neighboring rights to this software to the public domain
worldwide. This software is distributed without any warranty.

See <http://creativecommons.org/publicdomain/zero/1.0/>. */

#include <stdint.h>

/* This is the fastest generator passing BigCrush without
   systematic failures, but due to the relatively short period it is
   acceptable only for applications with a mild amount of parallelism;
   otherwise, use a xorshift1024* generator.

   The state must be seeded so that it is not everywhere zero. If you have
   a nonzero 64-bit seed, we suggest to pass it twice through
   MurmurHash3's avalanching function. */

uint64_t s[ 2 ];

uint64_t next(void) { 
	uint64_t s1 = s[ 0 ];
	const uint64_t s0 = s[ 1 ];
	s[ 0 ] = s0;
	s1 ^= s1 << 23; // a
	return ( s[ 1 ] = ( s1 ^ s0 ^ ( s1 >> 17 ) ^ ( s0 >> 26 ) ) ) + s0; // b, c
}
