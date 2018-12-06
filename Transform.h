//
//  Transform.h
//  TREE-ENCRYPTION
//
//  Created by himanshu on 30/04/17.
//  Copyright © 2017 CSE2003. All rights reserved.
//

#ifndef Transform_h
#define Transform_h
#include <iostream>
#include <string.h>
#include <vector>
#include <map>


using namespace std;
struct quotients
{
    vector<double> l1,inorder,preorder;
};

string generateKey(int N, string key)
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
int compress(string k)
{
    int x=0;
    for(int i=0;i<k.length();i++)
    {
        x+=int(k[i]);
    }
    return x%128;
}
string transform(vector<int> l1,vector<int> inorder,vector<int> preorder,int G,int N,string k1,string k2,string k3,string k4,string k5)
{
    quotients q;
    //key padding
    

    //arrays transforms
    for(int i=0;i<l1.size();i++)
    {
        l1[i]=G-l1[i];
        
    }
    
    if(G%2!=0)
    {
        
        if((N)>16)
        {
            k1=generateKey(N, k1);
            k2=generateKey(N, k2);
            
            
        }
        if(N-1>16)
        {
            
            k3=generateKey(N-1, k3);
        }

        
        //l[0] contains ascii of first character of plain text
        for(int i=0;i<N-1;i++)
        {
            int x=(l1[i]*(int(k3[i])))%128;
            if(x<33)
            {
                q.l1.push_back(((-1)*(l1[i]*int(k3[i]))/128));
                l1[i]=x+33;
                
                

            }
            else
            {
                
                q.l1.push_back(((l1[i]*int(k3[i]))/128));
                l1[i]=x;
                
            }}
        
        
        
        for(int i=0;i<N;i++)
        {
            
            int y=(inorder[i]*int(k2[i]))%128;
            if(y<33)
            {
                q.inorder.push_back((-1)*(inorder[i]*int(k2[i]))/128);
                inorder[i]=y+33;
                
                
            }
            else
            {
                q.inorder.push_back((inorder[i]*int(k2[i]))/128);
                inorder[i]=y;
                
                
            }
            
            int z=(preorder[i]*int(k1[i]))%128;
    
            if(z<33)
            {
                q.preorder.push_back(((-1)*(preorder[i]*int(k1[i]))/128));
                preorder[i]=z+33;
                

                
            }
            else
            {
                q.preorder.push_back((preorder[i]*int(k1[i]))/128);
                preorder[i]=z;
                

            }
            
        }
        
        
    }
    else
    {
        
        
        if((N)>16)
        {
            k1=generateKey(N, k1);
            k3=generateKey(N, k3);
            
            
        }
        if(N-1>16)
        {
            k2=generateKey(N-1, k2);
        }

        
        for(int i=0;i<N-1;i++)
        {
            int x=(l1[i]*(int(k2[i])))%128;
            if(x<33)
            {
                
                q.l1.push_back((-1)*((l1[i]*int(k2[i]))/128));
                l1[i]=x+33;
                
                
            }
            else
            {
               
                q.l1.push_back(((l1[i]*int(k2[i]))/128));
                l1[i]=x;
                            }
        }
        for(int i=0;i<N;i++){
            int y=(inorder[i]*int(k1[i]))%128;
            if(y<33)
            {
                q.inorder.push_back((-1)*(inorder[i]*int(k1[i]))/128);
                inorder[i]=y+33;
                
                
            }
            else
            {
                q.inorder.push_back((inorder[i]*int(k1[i]))/128);
                inorder[i]=y;
                
                
            }
            
            int z=(preorder[i]*int(k3[i]))%128;
            if(z<33)
            {
                q.preorder.push_back((-1)*(preorder[i]*int(k3[i]))/128);
                preorder[i]=z+33;
                
                
                
            }
            else
            {
                q.preorder.push_back((preorder[i]*int(k3[i]))/128);
                
                preorder[i]=z;
                
                
            }
            
            
        }
        


        
    }

    vector<int> key4;
    vector<int> key5;
    for(int i=0;i<8;i++)
    {
        key4.push_back(int(k4[i]));
        key5.push_back(int(k5[i]));
    }
    vector<int> output;
    
    
    if(G%2!=0)
    {
        output.insert(output.end(),key4.begin(),key4.end());
        output.push_back(G);
        output.insert(output.end(),preorder.begin(),preorder.end());
        output.insert(output.end(),(q.preorder).begin(),(q.preorder).end());
        output.insert(output.end(),(q.inorder).begin(),(q.inorder).end());
        output.insert(output.end(),(q.l1).begin(),(q.l1).end());
        output.insert(output.end(),inorder.begin(),inorder.end());
        output.insert(output.end(),l1.begin(),l1.end());
        output.push_back(N);
        output.insert(output.end(),key5.begin(),key5.end());
    }
    else{
            output.insert(output.end(),key5.begin(),key5.end());
            output.push_back(G);
            output.insert(output.end(),l1.begin(),l1.end());
            output.insert(output.end(),(q.l1).begin(),(q.l1).end());
            output.insert(output.end(),(q.preorder).begin(),(q.preorder).end());
            output.insert(output.end(),(q.inorder).begin(),(q.inorder).end());
        
            output.insert(output.end(),preorder.begin(),preorder.end());
            output.insert(output.end(),inorder.begin(),inorder.end());
            output.push_back(N);
            output.insert(output.end(),key4.begin(),key4.end());

        
            
            
        }
  
    
    
    //string conversion
    string outbound;
    for(int i=0;i<output.size();i++)
    {
        outbound.push_back(output[i]);
    }
    
    cout<<"\n\n";
    return outbound;
    
    
    
}

#endif /* Transform_h */
