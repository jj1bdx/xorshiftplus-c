# Archive of Xorshift\*/+ C code

* Original source: <http://xoroshiro.di.unimi.it/> (refer to Archive.org WayBack Machine for the chronological change of the contents, including those of <http://xorshift.di.unimi.it/>)

## Notes

* Tag `original-20150905` contains Xorshift64\* and Xorshift4096\* code, later removed by the author.
* Tag `original-20160106` contains SplitMix64 code, and *revised* Xorshift128+ code.
* Tag `original-20160913` contains Xoroshiro128+ code, and put old Xorshift64\* and Xorshift4096\* code back as for archive.
* Tag `original-20170504` contains Xoroshiro116+ code, and includes revision of other codes changing `1ULL` to `UINT64_C(1)` of C99.

## On Xorshift128+ parameter change

Executive summary: the change was for a slight (measurable but non-critical) mathematical improvement. No need for immediate change from the 20150905 code.

See <http://v8project.blogspot.co.uk/2015/12/theres-mathrandom-and-then-theres.html?showComment=1450389868643#c2004131565745698275> for the details.

## LICENSE

Public Domain. See `UNLICENSE`.
