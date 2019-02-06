//
//  bst.h
//  Convert BST to Doube Linked List
//
//  Created by Navroop Singh Bajwa on 06/02/19.
//  Copyright © 2019 Navroop Singh Bajwa. All rights reserved.
//

#ifndef bst_h
#define bst_h
#include <iostream>
using namespace std;
class bst{
    
private :
    
    /**
     Left = prev
     Right = next
     */
    struct node{
        int data;
        struct node *left,*right;
    };
    
    struct node *head,*headForDList,*currentInsertionPos;
    
    struct node *newNode(int item){
        struct node *temp =  (struct node *)malloc(sizeof(struct node));
        temp->data = item;
        temp->left = temp->right = NULL;
        return temp;
    }
    
    struct node* insert(struct node* node, int key){
        if (node == NULL)
            return newNode(key);
        
        if (key < node->data)
            node->left  = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        
        return node;
    }
    
    void preOrderPrint(struct node *head){
        if(head){
            preOrderPrint(head->left);
            preOrderPrint(head->right);
            cout<<head->data<<" ";
            }
    }
    void convertBstToDoubleLinkedList(struct node *head){
        if(head){
            
            //creating stack of values basically
            convertBstToDoubleLinkedList(head->left);
            convertBstToDoubleLinkedList(head->right);
            
            //headForDList,*currentInsertionPos
            
            if(headForDList==NULL){
                
                // here right and left both will be NULL
                headForDList = currentInsertionPos = head;
           
            }else{
                currentInsertionPos->right=head;
                head->left=currentInsertionPos;
                currentInsertionPos=head;
                currentInsertionPos->right=NULL;
            }
        }
    }
    
    void displayDLinkedList(node *head){
        cout<<"Iterating Forward=";
        while(head){
            cout<<head->data<<", ";
            if(head->right)
                head=head->right;
            else
                break;
        }
        cout<<endl;
        cout<<"Iterating Backward=";
        while(head){
            cout<<head->data<<", ";
            head=head->left;
        }
        cout<<endl;
    }
    
    public :
    bst(){
        head=headForDList=currentInsertionPos=NULL;
    }
    
    void insert(int value){
        head=insert(head, value);
    }

    void preOrderPrint(){
        cout<<"PreOrder=";
        preOrderPrint(head);
        cout<<endl;
    }

    void convertBstToDoubleLinkedList(){
        convertBstToDoubleLinkedList(head);
        head=NULL;
    }
    
    void displayDLinkedList(){
        displayDLinkedList(headForDList);
    }
};

#endif /* bst_h */
