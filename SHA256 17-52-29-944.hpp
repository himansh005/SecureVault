//
//  SHA256.hpp
//  TREE-ENCRYPTION
//
//  Created by himanshu on 30/04/17.
//  Copyright © 2017 CSE2003. All rights reserved.
//

#ifndef SHA256_hpp
#define SHA256_hpp

#include <stdio.h>
class SHA256
{
protected:
    typedef unsigned char uint8;
    typedef unsigned int uint32;
    typedef unsigned long long uint64;
    
    const static uint32 sha256_k[];
    static const unsigned int SHA224_256_BLOCK_SIZE = (512/8);
public:
    void init();
    void update(const unsigned char *message, unsigned int len);
    void final(unsigned char *digest);
    static const unsigned int DIGEST_SIZE = ( 256 / 8);
    
protected:
    void transform(const unsigned char *message, unsigned int block_nb);
    unsigned int m_tot_len;
    unsigned int m_len;
    unsigned char m_block[2*SHA224_256_BLOCK_SIZE];
    uint32 m_h[8];
};

#endif  /* SHA256_hpp */

