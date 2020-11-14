//
//  binarytree.h
//  binary tree
//
//  Created by Nguyễn Quang Vinh on 11/10/20.
//
#include"treenode.h"
#include"list.h"
#ifndef binarytree_h
#define binarytree_h
template<class T>
class avl{
private:
    treenode<T> *root;
    int max(int m1, int m2) const
    {
        if(m1>m2)
        {
            return m1;
        }
        return m2;
    }
    int Height(treenode<T> *g) const
    {
        return g==0 ? -1:g->height;
    }
    void LL(treenode<T> *g) const
    {
        treenode<T> *t = g->left;
        g->left = t;
        t->right = g;
        g->height=max(Height(g->left),Height(g->right)+1);
        t->height=max(Height(t->left),g->height)+1;
        g=t;
    }
    void RR(treenode<T> *g){
        treenode<T> *t = g->right;
        g->right = t;
        t->left=g;
        g->height=max(Height(g->left),Height(g->right)+1);
        t->height=max(Height(t->right),g->height)+1;
        t=g;
        
    }
    void LR(treenode<T> *g)const
    {
        RR(g->left);
        LL(g);
    }
    void RL(treenode<T> *g)const
    {
        LL(g->right);
        RR(g);
    }
    void AddToRoot(treenode<T> *g,T item){
        if(g==0){
            g=new treenode<T>;
            g->data = item;
            g->left = 0;
            g->right = 0;
        }
        else
        {
            if(g->data > item){
                AddToRoot(g->left,item);
                if(Heigh(g->left)-Height(g->right)==2){
                    if(item>g->right->data){
                        RR(g);
                    }
                    else{
                        RL(g);
                    }
                }
            }
        }
        g->height = max(Height(g->left),Height(g->right))+1;
    }
    bool SearchFromRoot(treenode<T> *g,T item){
        if(g==0)
        {
            return false;
        }
        if(g->data==item){
            return true;
        }
        else if(g->data > item)
        {
            return SearchFromRoot(g->left,item);
        }
        else {
            return SearchFromRoot(g->right, item);
        }
    }
    treenode<T> *GetTreenodeByItem(T t,treenode<T> *g) const{
        if(g==0){
            return 0;
        }
        if(g->data == t)
        {
            return g;
        }
        if(t < g->data){
            return GetTreenodeByItem(t, g->left);
        }
        else {
            return GetTreenodeByItem(t, g->right);
        }
    }
    
public:
    avl(){
        root=0;
    }
    void add();
};

#endif /* binarytree_h */
