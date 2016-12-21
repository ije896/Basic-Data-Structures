//
//  main.cpp
//  prog1
//
//  Created by Isaiah Egan on 4/15/16.
//  Copyright © 2016 Isaiah Egan. All rights reserved.
//

#include <iostream>
#include "hashTable.hpp"
#include "heap.hpp"
#include "quicken.hpp"

using namespace std;


int main()
{
    string s;
    string b;
    int temp;
    
    quicken qHash = quicken();
    
    while(cin >> s)
    {
        if(s == "insert")
        {
            cin >> b;
            temp = atoi(b.c_str());
            
            qHash.insert(temp);
            
        }
        else if(s == "delete")
        {
            cin >> b;
            temp = atoi(b.c_str());
            qHash.del(temp);
            
        }
        else if(s == "deleteMin")
        {
            qHash.delMin();
            
        }
        else if(s == "lookup")
        {
            cin >> b;
            temp = atoi(b.c_str());
            qHash.lookup(temp);
            
        }
        else if(s == "print")
        {
            
            qHash.print();
            
        }
        
    }
    
    return 0; 


}
