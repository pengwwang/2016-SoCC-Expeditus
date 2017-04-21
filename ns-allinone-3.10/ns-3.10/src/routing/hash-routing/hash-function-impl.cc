/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
// # Copyright (c) 2014 Hong Xu

// # This is hash function implementation. The HsiehHash() function is 
// # added into this file instead of as a separate file.
// # 
// # This program is free software: you can redistribute it and/or modify
// # it under the terms of the GNU General Public License as published by
// # the Free Software Foundation, either version 3 of the License, or
// # (at your option) any later version.

// # This program is distributed in the hope that it will be useful,
// # but WITHOUT ANY WARRANTY; without even the implied warranty of
// # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// # GNU General Public License for more details.

// # You should have received a copy of the GNU General Public License
// # along with this program.  If not, see <http://www.gnu.org/licenses/>.

// # Author: Hong Xu, <henry.xu@cityu.edu.hk>
// # based on:
// * Author: Chang Liu <cliu02@students.poly.edu>
// * Author: Adrian S.-W. Tam <adrian.sw.tam@gmail.com>
 
#include "hash-function-impl.h"
#include "md5sum.h"
// #include "hsieh.h"
#include <sstream>
#include <stdint.h>

#undef get16bits
#if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) \
  || defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
#define get16bits(d) (*((const uint16_t *) (d)))
#endif

#if !defined (get16bits)
#define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)\
                       +(uint32_t)(((const uint8_t *)(d))[0]) )
#endif

namespace ns3 {
	
uint32_t HsiehHash (const char * data, int len) {
	uint32_t hash = len, tmp;
	int rem;

	if (len <= 0 || data == 0) return 0;

	rem = len & 3;
	len >>= 2;

	/* Main loop */
	for (; len > 0; --len) {
		hash  += get16bits (data);
		tmp    = (get16bits (data+2) << 11) ^ hash;
		hash   = (hash << 16) ^ tmp;
		data  += 2*sizeof (uint16_t);
		hash  += hash >> 11;
	}

	/* Handle end cases */
	switch (rem) {
		case 3: hash += get16bits (data);
			hash ^= hash << 16;
			hash ^= data[sizeof (uint16_t)] << 18;
			hash += hash >> 11;
			break;
		case 2: hash += get16bits (data);
			hash ^= hash << 11;
			hash += hash >> 17;
			break;
		case 1: hash += *data;
			hash ^= hash << 10;
			hash += hash >> 1;
	}

	/* Force "avalanching" of final 127 bits */
	hash ^= hash << 3;
	hash += hash >> 5;
	hash ^= hash << 4;
	hash += hash >> 17;
	hash ^= hash << 25;
	hash += hash >> 6;

	return hash;
}

uint64_t HashMD5::operator() (uint32_t salt, flowid tuple) const
{
	md5sum MD5;		// MD5 engine
	char x[4+17];		// Stringify the salt
	for (int i=0;i<4;i++) {
		x[i] = ((char*)(&salt))[i];
	};
	tuple.Write(&x[4]);
	MD5 << x;		// Feed salt and flowid into MD5

	// Convert 128-bit MD5 digest into 64-bit unsigned integer
	unsigned char* b = MD5.getDigest();
	uint64_t val = 0;
	for (int i=0; i<8; i++) {
		val <<= 8;
		val |= b[i] ^ b[15-i];
	};
	return val;
}

uint64_t HashHsieh::operator() (uint32_t salt, flowid tuple) const
{
	char x[4+17];		// 4-byte for salt, 16-byte/128-bit for tuple
	for (int i=0;i<4;i++) { // Stringify the salt
		x[i] = ((char*)(&salt))[i];
	};
	tuple.Write(&x[4]);
	return HsiehHash (x, 4+16);
}

};
