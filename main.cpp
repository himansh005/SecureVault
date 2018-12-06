#include <iostream>
#include <string>
#include <math.h>
#include "SHA256.hpp"
#include "Transform.h"
#include <vector>
#include <map>
#include <stdlib.h>
#include <ctype.h>
#include "encrypt.h"
#include "treefy.h"
#include "word_data.h"
#include <algorithm>
#include "decrypt.h"
#include <time.h>
#include <fstream>

using namespace std;


struct users{
    vector<double> a,b;
};

int main()
{

    
    
    treeNode *root = NULL,*temp;
    user a;
    int ch;
    
    
    while(1)
    {
        cout<<"\n\n\n+++++++++++++++++++++++++++  Password guardian  +++++++++++++++++++++++++++++\n\n\n";
        cout<<"                                1. STORE                                       \n";
        cout<<"                                2. ACCESS                                        \n";
        cout<<"                                3. EXIT                                      \n\n\n";
        cout<<"                          <Enter Your Choice>:";
        cin>>ch;
        int cntr=0;
        switch(ch)
        {
            case 1:{
                
                do{
                
                cout<<"     \n\n        ----------------------------------------------------------\n";
                cout<<"\n                            Enter Unique ID:  ";
                    
                    
                    cin.ignore();
                    getline(cin,a.id);
                    if(Find(root,a.id)!=NULL)
                    {
                        cout<<"ID already exists ! Please enter another : ";
                        cntr=1;
                    }
                    else
                    {
                        cntr=0;
                    }
                }while(cntr!=0);
                
                
                cout<<"\n\n\n       ---------------------------------------------------------\n";
                cout<<"\n                    Thanks For Choosing Secure Vault !   \n\n";
                cout<<"       ---------------------------------------------------------";
                cout<<"\n\n                    Enter Your Secret Information:  ";
                cin.clear();
                
                
                /*fstream infile;
                infile.open("/Users/himanshu/Desktop/abc.txt");
                infile >> a.ct;*/
                
                
                getline(cin,a.ct);

                cout<<"\n\n       **********************************************************";
                cout<<"\n                           Enter Your Secret Key :  ";
                string key;
                cin>>key;
                a.ct=encrypt(a.ct,key);
                key.clear();
                root = Insert(root, a);
                
                /*ofstream bc;
                bc.open("/Users/himanshu/Desktop/abc.txt");
                bc << a.ct;*/
                                            break;}
        
            case 2:{
                
                cout<<"\n\n\n#_______________________________WELCOME BACK !___________________________#";
                cout<<"\n\n\n\n                          Enter Your Unique ID : ";
                cin>>a.id;
                temp = Find(root,a.id);
     
                if(temp==NULL)
                {
                    cout<<"\n\n\n                            ID does not exists !                 \n";
                }
                else
                {
                    int x;
                    cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~1. VIEW DECRYPTED INFORMATION~~~~~~~~~~~~~~~~~~~~~~~~\n";
                    cout<<"~~~~~~~~~~~~~~~~~~~~~2. VIEW ENCRYPTED INFORMATION~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                    cout<<"                             SELECT YOUR CHOICE :";
                    cin>>x;
                    if(x==1){
                        string key;
                        cout<<"\n\n       **********************************************************\n\n";
                        cout<<"                          Enter Your Secret Key : ";
                      
                        cin>>key;
                        cout<<"\n\n                                 NAME : "<<(temp->data).id<<"\n\n";
                        cout<<"                             YOUR INFORMATION :"<<decrypt(((temp->data).ct),key)<<"\n\n";
                        key.clear();
                        
                    }
                    else if(x==2)
                    {
                        
                        cout<<"\n\n                                 NAME : "<<(temp->data).id<<"\n\n";
                        cout<<"                   YOUR INFORMATION ENCRYPTED :"<<((temp->data).ct)<<"\n\n";
                        

                        
                    }
                    
                    
                    

                }
                

                break;}
            case 3:{
                exit(1);
                break;}
            default:{
                cout<<"\nEnter correct choice:";
                break;}
        }
    }
    
    
    
    return 0;}

