#ifndef list_h
#define list_h
#include "node.h"
template <class T>
class List
{
private:
    Node<T> *head;
    //int a[100];
    //int N;
public:
    List()
    {
        head = 0;
        //N = 0
    };
    void Add(T value)
    {
        Node<T> * n = new Node<T>;
        n->data = value;
        n->next = 0;
        
        if (head == 0)
            head = n;
        else
        {
            Node<T> *p = head;
            while (p->next != 0)
                p = p->next;
            p->next = n;
        }
    };
    T Get(int pos) const
    {
        //return a[pos-1];
        Node<T> *p = head;
        for(int i = 1; i<pos; i++)
            p = p->next;
        return p->data;
    };
    int Count() const
    {
        int dem = 0;
        Node<T> *p = head;
        while (p != 0)
        {
            p=p->next;
            dem++;
        }
        return dem;
    };
    void Insert(T value, int pos)
    {
        Node<T> *n = new Node<T>;
        n->data = value;
        if (pos == 1)
        {
            n->next = head;
            head = n;
        }
        else
        {
            Node<T> *p = head;
            for(int i = 1; i<pos-1; i++)
                p = p->next;
            n->next = p->next;
            p->next = n;
        }
    };
    
    void Delete(int pos)
    {
        if (pos == 1)
        {
            Node<T> *p = head;
            head = head->next;
            delete p;
        }
        else
        {
            Node<T> *p = head;
            for(int i = 1; i<pos-1; i++)
                p=p->next;
            Node<T> *q = p->next;
            p->next = p->next->next;
            delete q;
        }
        
    };
};



#endif
