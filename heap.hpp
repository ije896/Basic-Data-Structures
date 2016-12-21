//
//  heap.hpp
//  prog1
//
//  Created by Isaiah Egan on 4/15/16.
//  Copyright © 2016 Isaiah Egan. All rights reserved.
//

#ifndef heap_hpp
#define heap_hpp

#include <stdio.h>
#include "hashTable.hpp"


class heap

{

private:
    int *tree;
    int length;
    int indexRChild(int i);
    int indexLChild(int i);
    int indexParent(int i){return i/2;}

public:
    heap(); 
    ~heap();
    void insert(int i); //requires, changes, requires
    void del (int i); //changes, requires
    int delMin(); //changes, requires
    void percUp (int i);
    void percDown(int i);
    void swap(int i, int j);
    void print();

};



#endif /* heap_hpp */
