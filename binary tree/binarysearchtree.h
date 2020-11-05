#ifndef tree_h
#define tree_h
#include "treenode.h"
#include "queue.h"
#include "list.h"
template <class T>
class Tree
{
private:
    TreeNode<T> *root;
  TreeNode<T> * GetNode(T t, TreeNode<T> *r) const
  {
    Queue<TreeNode<T> *> q;
    q.EnQueue(r);
    while (!q.IsEmpty())
    {
      TreeNode<T> * p = q.DeQueue();
      if (p->data == t)
        return p;
      if (p->child != 0)
        q.EnQueue(p->child);
      if (p->next != 0)
        q.EnQueue(p->next);
    }
    return 0;

  }
public:
  Tree()
  {
    root = 0;
  };
  void AddRoot(T t)
  {
    if (root != 0)
      root->data = t;
    else
    {
      root = new TreeNode<T>;
      root->data = t;
      root->child = 0;
      root->next = 0;
    }
  };

  void AddChild(T value_parent, T value_child)
  {
    TreeNode<T> *p = GetNode(value_parent, root);
    if (p->child == 0)
    {
      TreeNode<T> * q = new TreeNode<T>;
      q->next = 0;
      q->child = 0;
      q->data = value_child;
      p->child = q;
    }
    else
    {
      TreeNode<T> *c = p->child;
      while (c->next != 0)
        c= c->next;
        TreeNode<T> * q = new TreeNode<T>;
      q->next = 0;
      q->child = 0;
      q->data = value_child;
      c->next = q;
    }
  };
  List<T> GetChild(T value_parent) const
  {
    List<T> kq;
    TreeNode<T> *p = GetNode(value_parent, root);
    if (p!=0)
    {
      TreeNode<T> * q = p->child;
      while (q != 0)
      {
        kq.Add(q->data);
        q = q->next;
      }
    }
    return kq;
  };
};

#endif
