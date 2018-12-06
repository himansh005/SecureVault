//
//  treefy.h
//  TREE-ENCRYPTION
//
//  Created by himanshu on 01/05/17.
//  Copyright © 2017 CSE2003. All rights reserved.
//

#ifndef treefy_h
#define treefy_h
#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include <algorithm>
#include<fstream>
using namespace std;
struct node
{
    int key;
    struct node *left, *right;
};
// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
    
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    /* return the (unchanged) node pointer */
    return node;
}
vector<int> TraversalPreorder(struct node* root)
{
    vector<int> start;
    while (root)
    {
        // If left child is null, print the current node data. Move to
        // right child.
        if (root->left == NULL)
        {
            start.push_back(root->key);
            root = root->right;
        }
        else
        {
            // Find inorder predecessor
            struct node* current = root->left;
            while (current->right && current->right != root)
                current = current->right;
            
            // If the right child of inorder predecessor already points to
            // this node
            if (current->right == root)
            {
                current->right = NULL;
                root = root->right;
            }
            
            // If right child doesn't point to this node, then print this
            // node and make right child point to this node
            else
            {
                start.push_back(root->key);
                current->right = root;
                root = root->left;
            }
        }
    }
    return start;
}

vector<int> BST(vector<int> vals)
{
    int a=vals.size();
    struct node *root = NULL;
    root = insert(root, vals[0]);
    for(int i=0;i<(a-1);i++){
        insert(root, vals[i+1]);
    }
    
    return(TraversalPreorder(root));
        
    
    /*	vector<int>::iterator t=(inorder(root)).begin();
     while(t!=((inorder(root)).end())){
     cout<<*t<<"\n";
     t++;
     }
     
     //return inordervec;*/
}

#endif
