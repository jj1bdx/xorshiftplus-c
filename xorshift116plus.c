/* Written in 2014 by Sebastiano Vigna (vigna@acm.org) and 
   Kenji Rikitake (kenji.rikitake@acm.org).

To the extent possible under law, the author has dedicated all copyright
and related and neighboring rights to this software to the public domain
worldwide. This software is distributed without any warranty.

See <http://creativecommons.org/publicdomain/zero/1.0/>. */

#include <stdint.h>

#define UINT58MASK (uint64_t)((uint64_t )1 << 58) - 1)

/* This generator is a variant of xorshift128+ for dynamic languages, such
   as Erlang, that can use only 58 bits of a 64-bit integer. Only the lower
   58 bits of each state word are valid (the upper six are zeroes).
   
   This generator passes BigCrush without systematic failures, but due to
   the relatively short period it is acceptable only for applications with
   a mild amount of parallelism; otherwise, use a xorshift1024* generator.

   The state must be seeded so that the lower 58 bits of s[ 0 ] and s[ 1 ]
   are not all zeroes. If you have a nonzero 64-bit seed, we suggest to
   pass it twice through MurmurHash3's avalanching function and take the
   lower 58 bits, taking care that they are not all zeroes (you can apply
   the avalanching function again if this happens). */

uint64_t s[ 2 ];

uint64_t next(void) { 
	uint64_t s1 = s[ 0 ];
	const uint64_t s0 = s[ 1 ];
	s[ 0 ] = s0;
	s1 ^= (s1 << 24) & UINT58MASK ; // a
	return ((( s[ 1 ] = ( s1 ^ s0 ^ ( s1 >> 11 ) ^ ( s0 >> 41 ) ) ) + s0) & UINT58MASK) ; // b, c
}
