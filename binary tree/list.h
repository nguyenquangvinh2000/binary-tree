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
    
    
};

#endif /* list_h */
