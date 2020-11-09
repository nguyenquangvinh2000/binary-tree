//
//  treenode.h
//  binary tree
//
//  Created by Nguyễn Quang Vinh on 11/5/20.
//

#ifndef treenode_h
#define treenode_h
using namespace std;
template<class T>
struct treenode{
    T data;
    treenode<T> *left;
    treenode<T> *right;
};

#endif /* treenode_h */
