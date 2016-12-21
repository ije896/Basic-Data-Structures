//
//  quicken.cpp
//  prog1
//
//  Created by Isaiah Egan on 4/23/16.
//  Copyright © 2016 Isaiah Egan. All rights reserved.
//

#include "quicken.hpp"
#include <iostream>
using namespace std;

quicken::quicken()
{
    table = hashTable();
    tree = heap();
}


quicken::~quicken()
{
    
}

void quicken::insert(int i)
{
    if(table.insert(i))
    {
        tree.insert(i);
    }
    else
        cout<< "error : item already exists" <<endl;
}


void quicken::lookup(int i)
{
    if(table.lookup(i))
        cout << i <<" found" << endl;
    else
        cout<< i<<" not found" <<endl;
}


void quicken::del(int i)
{
    if(table.del(i))
        tree.del(i);
    else
        cout << "error : item not present"<<endl;
}

void quicken::delMin()
{
    int value = tree.delMin();
    if (value==0)
    {
        cout<<"error"<< endl;
        return;
        
    }
    table.del(value);
    cout<<value<<endl;
}

void quicken::print()
{
    tree.print();
}