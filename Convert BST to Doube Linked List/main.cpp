//
//  main.cpp
//  Convert BST to Doube Linked List
//
//  Created by Navroop Singh Bajwa on 06/02/19.
//  Copyright © 2019 Navroop Singh Bajwa. All rights reserved.
//


#include "bst.h"

int main(int argc, const char * argv[]) {
    bst *obj=new bst();
    int numberOfInputs;
    cout<<"Enter No of elements for Bst:";
    cin>>numberOfInputs;
    for(int no=0;no<numberOfInputs;no++){
        int var;
        cout<<"Enter value:";
        cin>>var;
        obj->insert(var);
    }
    obj->preOrderPrint();
    obj->convertBstToDoubleLinkedList();
    obj->displayDLinkedList();
    return 0;
}
