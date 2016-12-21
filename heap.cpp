//
//  heap.cpp
//  prog1
//
//  Created by Isaiah Egan on 4/15/16.
//  Copyright © 2016 Isaiah Egan. All rights reserved.
//

#include "heap.hpp"
#include "hashTable.hpp"
#include <algorithm>
#include <iostream>
using namespace std;

const int heapLength = 1000;



heap::heap()
{
    tree = new int[heapLength];
    length = 1;
    for(int i = 0; i < heapLength; ++i)
        tree[i]=0;
}

heap::~heap()
{
}

int heap::indexLChild(int i)
{
    int index = 2*i;
    if (tree[index]==0)
    {
        return 0;
    }
    return index;
}


int heap::indexRChild(int i)
{
    int index = 2*i+1;
    if (tree[index]==0)
    {
        return 0;
    }
    return index;
}


void heap::swap(int child, int parent) //swap the values at indeces i and j
{
    int tmp = tree[child];
    tree[child]=tree[parent];
    tree[parent] = tmp;
}

void heap::percUp(int i){ //for inserting
    
    int parent = indexParent(i);
    
    if (tree[i]>tree[parent])//base case
        return;
    
    else if (tree[i]<tree[parent])
    {
        swap(i, parent);
        percUp(parent);
    }
}

void heap::percDown(int parent){ //for delMin
    
    int left = indexLChild(parent);
    int right = indexRChild(parent);
    int minChild = 0;
    
    
    //first, find the minChild
    if (left == 0) //this means i is a leaf
    {
        return;
    }
    
    else if (right == 0 && left!=0)
    {
        minChild=left;
    }
    else if (right!=0 && left!=0)
    {
        if (tree[right]<tree[left])
        {
            minChild=right;
        }
        else
        {
            minChild=left;
        }
    }
    
    //now compare parent with child
    
    if (tree[parent]<tree[minChild]) //base case
    {
        return;
    }
    
    else if (tree[parent]>tree[minChild] && minChild!=0)
    {
        swap(minChild, parent);
        percDown(minChild);
    }
}

void heap::insert(int i)
{
    if (tree[1]==0)
    {
        tree[1]=i;
        length++;
        return;
    }
    
    else
    {
        tree[length]=i;
        percUp(length);
        length++;
    }
}

int heap::delMin()
{
    int min = tree[1];
    tree[1]=tree[length-1];
    tree[length-1]=0;
    length--;
    percDown(1);
    return min;
}

void heap::del(int i)
{
    

    for (int k=1; k<length+1; ++k)
    {
        if (tree[k]==i)
        {
            if (k==length-1)
            {
                tree[k]=0;
                length--;
                return;
            }
            else
            {
                tree[k]=tree[length-1];
                tree[length-1]=0;
                percUp(k);
                length--;
                percDown(k);
            }
            return;
        }
    }

}

void heap::print()
{
    int num = length-1;
    for (int i=0; i<num; ++i)
    {
        cout<< delMin()<<" ";
    }
    cout<<endl;
}