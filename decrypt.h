//
//  decrypt.h
//  TREE-ENCRYPTION
//
//  Created by himanshu on 02/05/17.
//  Copyright © 2017 CSE2003. All rights reserved.
//
#ifndef decrypt_h
#define decrypt_h
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

using namespace std;
string xgenerateKey(int N, string key)
{
    int x=N;
    
    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == x)
            break;
        key.push_back(key[i]);
    }
    return key;
}
vector<int> findPair(vector<int> a, vector<int> b)//b=n
{
    // Initialize positions of two elements
    vector<int> c;
    
    // Search for a pair
    
    if(c.size()==0){
        for(int j=1;j<a.size();j++)
        {
            if((a[0]-a[j])==b[0])
            {
                c.push_back(a[0]);
                c.push_back(a[j]);
                a[j]=200;
                
                
                break;
            }
        }
        
    }
    for(int i=1;i<a.size()-1;i++)
        if(b[i]==0){
            c.push_back(c[i]);
        }
        else{
            c.push_back(c[i]-b[i]);}
    for(int i=0;i<c.size();i++)
        a[i]=c[i];
    return a;
}
//decrypt
string decrypt(string ct,string key)
{
    vector<int> a,l1,inorder,preorder,ql1,qpreorder,qinorder;
    for(int i=0;i<ct.length();i++)
    {
        a.push_back(int(ct[i]));
    }
    
    int G=a[8];
    int N=a[a.size()-1-8];
        //assimilate
    if(G%2!=0)
    {
        
        for(int i=8+5*N;i<7+6*N;i++)
        {
            l1.push_back(a[i]);
        }
        for(int i=8+4*N;i<8+5*N;i++)
        {
            inorder.push_back(a[i]);
        }
        for(int i=9;i<9+N;i++)
        {
            preorder.push_back(a[i]);
        }
        for(int i=9+N;i<2*N+9;i++)
        {
            qpreorder.push_back(a[i]);
        }
        for(int i=9+2*N;i<3*N+9;i++)
        {
            qinorder.push_back(a[i]);
        }
        for(int i=3*N+9;i<4*N+8;i++)
        {
            ql1.push_back(a[i]);
        }
    //}
        //testrun
    
    
    //reverseTransform
    for(int i=0;i<N-1;i++)
    {
        if(ql1[i]<0){
            l1[i]=G-(128*abs(ql1[i])+(l1[i]-33))/int(sha256(key).k3[i]);
            
        }
        else{
            l1[i]=G-(128*ql1[i]+l1[i])/int(sha256(key).k3[i]);}
        
    }
            for(int i=0;i<N;i++)
    {
        if((qpreorder[i])<0){
            preorder[i]=(128*abs(qpreorder[i])+(preorder[i]-33))/int(sha256(key).k1[i]);}
    
        else{
            preorder[i]=(128*qpreorder[i]+(preorder[i]))/int(sha256(key).k1[i]);
        }
    
        if(qinorder[i]<0){
            inorder[i]=(128*abs(qinorder[i])+(inorder[i]-33))/int(sha256(key).k2[i]);}
        else{
            inorder[i]=(128*qinorder[i]+(inorder[i]))/int(sha256(key).k2[i]);
        }
    }
       
    }
    
    
    
    
    //G is even
    else
    {
        
        for(int i=9;i<8+N;i++)
        {
            l1.push_back(a[i]);
        }
        
        for(int i=7+5*N;i<7+6*N;i++)
        {
            inorder.push_back(a[i]);
        }
        for(int i=4*N+7;i<7+5*N;i++)
        {
            preorder.push_back(a[i]);
        }
        for(int i=7+2*N;i<3*N+7;i++)
        {
            qpreorder.push_back(a[i]);
        }
        for(int i=7+3*N;i<4*N+7;i++)
        {
            qinorder.push_back(a[i]);
        }
        for(int i=N+8;i<2*N+7;i++)
        {
            ql1.push_back(a[i]);
        }
        //}
        //testrun
        
        
        //reverseTransform
        for(int i=0;i<N-1;i++)
        {
            if(ql1[i]<0){
                l1[i]=G-(128*abs(ql1[i])+(l1[i]-33))/int(sha256(key).k2[i]);
                
            }
            else{
                
                l1[i]=G-(128*ql1[i]+l1[i])/int(sha256(key).k2[i]);}
        }
        for(int i=0;i<N;i++)
        {
            if((qpreorder[i])<0){
                preorder[i]=(128*abs(qpreorder[i])+(preorder[i]-33))/int(sha256(key).k3[i]);
            }
            else{
                preorder[i]=(128*qpreorder[i]+(preorder[i]))/int(sha256(key).k3[i]);
            }
            
            if(qinorder[i]<0){
                inorder[i]=(128*abs(qinorder[i])+(inorder[i]-33))/int(sha256(key).k1[i]);
            }
            else{
                inorder[i]=(128*qinorder[i]+(inorder[i]))/int(sha256(key).k1[i]);
            }
        }}
    
    vector<int> PT;
    
    
    PT=findPair(preorder,l1);
    
   

    string recoveredText;
    for(int i=0;i<N;i++)
    {
        recoveredText.push_back(char(PT[i]));
    }
    
    return recoveredText;
    
    



 

}



    
    
    
    
    

    
    
    
    
    

#endif /* decrypt_h */
