#ifndef queue_h
#define queue_h
#include "node.h"
template <class T>
class Queue
{
private:
    Node<T> *f, *l;
    //int a[100];
    //int N;
public:
    Queue()
  {
    f = 0; l = 0;
  }
  void EnQueue(T t)
  {
    Node<T> * n = new Node<T>;
    n->data = t;
    n->next = 0;
    if (f == 0)
    {
      f = n;
      l = n;
    }
    else
    {
      l->next = n;
      l = n;
    }
  };
  T DeQueue()
  {
    T t = f->data;
    Node<T> *q = f;
    f = f->next;
    delete q;
    if (f == 0)
      l = 0;
    return t;
  };
  T GetFirst() const
  {
    return f->data;
  };
  bool IsEmpty() const
  {
    return f == 0;
  };

};

#endif
