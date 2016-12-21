//
//  hashTable.cpp
//  prog1
//
//  Created by Isaiah Egan on 4/15/16.
//  Copyright © 2016 Isaiah Egan. All rights reserved.
//


#include "hashTable.hpp"
#include <iostream>
using namespace std;



const int tableSize = 101;



hashTable::hashTable()
{
    table = new node*[tableSize];
    for(int i = 0; i < tableSize; ++i)
        table[i] = NULL;
}



hashTable::~hashTable()
{

}



int hashTable::hash(int  key)
{
    int hashed = key % 101;
    return hashed;
}



bool hashTable::insert(int i)
{
    node *val = new node(i);
    
    int pos = hash(i);
    
    if (table[pos]==NULL)
    {
        table[pos]=val;
        return true;
    }

    else {
        for (node * p = table[pos]; p!=NULL; p=p->next)//checks the chain for duplicate
        {     
            if (p->value==i)
            {
                return false;
            }
            else if (p->next==NULL)
            {
                p->next= val;
                return true;
            }
            
        }
    }
    return false;
}




bool hashTable::lookup(int i)
{
    
    int pos = hash(i);
    if (table[pos]==NULL) {
        return false;
    }
    for (node*p=table[pos]; p!=NULL; p=p->next)
        {
            if (p->value==i)
            {
                return true;
            }
        }
    return false;
}




bool hashTable::del(int i)
{
    int pos = hash(i);
    node * p = table[pos];
    if (p==NULL)
    {
        return false;
    }
    else if (p->value==i && p->next ==NULL)
    {
        table[pos]=p->next;
        delete p;
        return true;
    }
    else
    {
        node * j = p;
        p=p->next;
        while (p!=NULL)
        {
            if (p->value == i)
            {
                j->next=p->next;
                delete p;
                return true;
            }
            j=j->next;
            p=p->next;
        }
        return true;
    }
    return false;
}



void hashTable::print()
{
    for (int i=0; i<tableSize; ++i)
    {
        if (table[i]!=NULL)
        {
            for (node * j = table[i]; j!=NULL; j=j->next)
            {
                cout << "pos: "<< i;
                cout<< " entry: "<< j->value <<endl;
            }
        }
    }
}
