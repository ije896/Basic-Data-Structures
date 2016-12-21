//
//  hashTable.hpp
//  prog1
//
//  Created by Isaiah Egan on 4/15/16.
//  Copyright © 2016 Isaiah Egan. All rights reserved.
//

#ifndef hashTable_hpp
#define hashTable_hpp

#include <stdio.h>
#include <stddef.h>

struct node
{
    
    node(int x): value(x), next(NULL){};
    int value;
    node *next;
    
};

class hashTable
{

    private:
        int hash (int key); //return location
        node **table;
    public:
        hashTable();
        ~hashTable();
        bool insert(int i);
        bool del(int i);
        bool lookup(int i);
        void print();
    
};


#endif /* hashTable_hpp */
