//
//  caynhiphan.h
//  binary tree
//
//  Created by Nguyễn Quang Vinh on 11/5/20.
//

#ifndef caynhiphan_h
#define caynhiphan_h
#include"treenode.h"
using namespace std;
class binarytree{
private:
    treenode *root;
public:
    binarytree(){
        root=0;
    }
    void addItem(treenode *r,int item){
        if(r==NULL){
            treenode *t= new treenode;
            t->data=item;
            t->left=NULL;
            t->right=NULL;
            t=r;
        }
        else
        {
            if(r->data > item){
                addItem(r->left,item);
            }
            else
            {
                addItem(r->right, item);
            }
        }
    }
    void Menu(treenode *r){
        while(true){
            cout<<"\t\t\t=============MENU==============="<<endl;
            cout<<"\t1.Add data tree"<<endl;
            cout<<"\t2.Print data tree"<<endl;
            cout<<"\t0.End"<<endl;
            
            int choice;
            cout<<"type your choice:";
            cin>>choice;
            
            if(choice < 0 || choice > 2)
            {
                cout<<"choice available";
                system("pause");
            }
            else if(choice == 1){
                int item;
                cout<<"type item:";
                cin>>item;
                addItem(r, item);
            }
        }
        
    }
};

#endif /* caynhiphan_h */
