//
//  quicken.hpp
//  prog1
//
//  Created by Isaiah Egan on 4/23/16.
//  Copyright © 2016 Isaiah Egan. All rights reserved.
//

#ifndef quicken_hpp
#define quicken_hpp

#include "heap.hpp"
#include "hashTable.hpp"
#include <stdio.h>

class quicken
{
private:
    hashTable table;
    heap tree;
    
public:
    quicken();
    ~quicken();
    void delMin();
    void del(int i);
    void insert(int i);
    void lookup(int i);
    void print();
};
#endif /* quicken_hpp */
