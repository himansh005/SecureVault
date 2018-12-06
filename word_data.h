//
//  word_data.h
//  TREE-ENCRYPTION
//
//  Created by himanshu on 02/05/17.
//  Copyright © 2017 CSE2003. All rights reserved.
//

#ifndef word_data_h
#define word_data_h


#include <string>
#include <iostream>
#include <math.h>
#include "SHA256.hpp"
#include "Transform.h"
#include <vector>
#include <map>
#include <stdlib.h>
#include <ctype.h>
#include "encrypt.h"
using namespace std;

struct user
{
    string id;
    string ct;
};
struct treeNode
{
    user data;
    treeNode *left;
    treeNode *right;
};

treeNode *Insert(treeNode *node,user data)
{
    if(node==NULL)
    {
        treeNode *temp;
        temp=new treeNode;
        
        temp -> data = data;
        temp -> left = temp -> right = NULL;
        return temp;
    }
    if((data.id).compare(((node->data).id))<0)
    {
        node->right = Insert(node->right,data);
    }
    else if((data.id).compare(((node->data).id))>0)
    {
        node->left = Insert(node->left,data);
    }
    
    return node;
}
treeNode * Find(treeNode *node, string data)
{
    if(node==NULL)
    {
        
        return NULL;
    }
    if((data).compare(((node->data).id))<0)
    {
        
        return Find(node->right,data);
    }
    else if((data).compare(((node->data).id))>0)
    {
                return Find(node->left,data);
    }
    else
    {
                return node;
    }
}


#endif
