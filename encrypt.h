//
//  encrypt.h
//  TREE-ENCRYPTION
//
//  Created by himanshu on 02/05/17.
//  Copyright © 2017 CSE2003. All rights reserved.
//

#ifndef encrypt_h
#define encrypt_h
//
//  encrypt.cpp
//  TREE-ENCRYPTION
//
//  Created by himanshu on 02/05/17.
//  Copyright © 2017 CSE2003. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include "SHA256.hpp"
#include "Transform.h"
#include <vector>
#include <map>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include "treefy.h"
#include <time.h>


using namespace std;

string encrypt(string plainText,string key){

    
    vector<int> ascii;
    vector<int> l1;
    vector<int> l2;
    vector<int> preorder;
    vector<int> inorder;
    int G,N;
    
    string::iterator it;
        
    
    
    
    //arrays
    
    for(int j=0;j<plainText.length();j++)
    {
        ascii.push_back(int(plainText[j]));
        
    }
    N=ascii.size();
   
    
    
    
    
    
    for(int i=0;i<N-1;i++){
        l2.push_back(abs(ascii[i]-ascii[i+1]));
        l1.push_back((ascii[i]-ascii[i+1]));}
    

    G=l2[0];
    for(int i=0;i<N-1;i++)
    {
        if(l2[i]>G)
            G=l2[i];
    }
    preorder=BST(ascii);
    //amendment
    vector<int>::iterator iter=preorder.begin();
    
  
    vector<int> aux;
    for(int i=0;i<preorder.size();i++){
        for(int j=0;j<ascii.size();j++)
        {
            if(preorder[i]==ascii[j])
            {
                aux.push_back(preorder[i]);
            }
            
        }
    }
    
    //close//
    for(int i=0;i<ascii.size();i++)
    {
        
        inorder.push_back(ascii[i]);
    }
    
    
    sort(inorder.begin(),inorder.end());
    
    

    sha256(key);
    

  
    return transform(l1,inorder,aux,G,N,sha256(key).k1,sha256(key).k2,sha256(key).k3,sha256(key).k4,sha256(key).k5);}



#endif /* encrypt_h */
