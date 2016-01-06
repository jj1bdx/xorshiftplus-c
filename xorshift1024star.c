/*  Written in 2014 by Sebastiano Vigna (vigna@acm.org)

To the extent possible under law, the author has dedicated all copyright
and related and neighboring rights to this software to the public domain
worldwide. This software is distributed without any warranty.

See <http://creativecommons.org/publicdomain/zero/1.0/>. */

#include <stdint.h>

/* This is a fast, top-quality generator. If 1024 bits of state are too
   much, try a xorshift128+ or generator. */

/* The state must be seeded so that it is not everywhere zero. If you have
   a 64-bit seed,  we suggest to seed a xorshift64* generator and use its
   output to fill s. */

uint64_t s[ 16 ]; 
int p;

uint64_t next(void) { 
	uint64_t s0 = s[ p ];
	uint64_t s1 = s[ p = ( p + 1 ) & 15 ];
	s1 ^= s1 << 31; // a
	s1 ^= s1 >> 11; // b
	s0 ^= s0 >> 30; // c
	return ( s[ p ] = s0 ^ s1 ) * 1181783497276652981LL; 
}
