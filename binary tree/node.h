//
//  node.h
//  binary tree
//
//  Created by Nguyễn Quang Vinh on 11/9/20.
//

#ifndef node_h
#define node_h
template<class T>

struct node{
    T data;
    node<T> *next;
    node<T> *prev;
};

#endif /* node_h */
