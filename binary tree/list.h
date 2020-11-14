//
//  list.h
//  binary tree
//
//  Created by Nguyễn Quang Vinh on 11/9/20.
//

#ifndef list_h
#define list_h
#include"node.h"
template<class T>
class list{
private:
    node<T> *head;
public:
    list(){
        head = 0;
    }
    void additem(T item)
    {
        node<T> *p = new node<T>;
        p->data = item;
        p->next = 0;
        
        if(head == 0)
        {
            head = p;
        }
        else{
            node<T> *p = head;
            while (p->next!=0) {
                p=p->next;
            }
            p->next = item;
        }
    }
    T getItem(int index){
        node<T> *p = new node<T>;
        for(int i=1;i<index;i++)
        {
            p=p->next;
        }
        return p->data;
    }
    int Count() const{
        int dem = 0;
        node<T> *p=head;
        while(p!=0){
            p=p->next;
            dem++;
        }
        return dem;
    }
    void insert(T item, int index){
        node<T> *n = new node<T>;
        n->data = item;
        if(index == 1)
        {
            n->next=head;
            head = n;
        }
        else {
            node<T> *p = new node<T>;
            for(int i=1;i<index-1;i++)
            {
                p=p->next;
            }
            n->next = p->head;
            p->next = n;
        }
    }
    void Delete(int index){
        if(index == 1){
            node<T> *p = head;
            head=head->next;
            delete p;
        }
        else{
            node<T> *p = head;
            for(int i=1;i<index-1;i++){
                p=p->next;
            }
            node<T> *q = p->next;
            p->next = p->next->next;
            delete q;
            
        }
        
    }
    
};

#endif /* list_h */
