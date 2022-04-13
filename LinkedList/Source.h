//
//  Source.h
//  LinkedList
//
//  Created by Behrooz Keshavarzi on 4/10/22.
//

#ifndef Source_h
#define Source_h

#include <iostream>

class node
{
public:
    node();
    friend class LL;
    node * next;
    node * prev;
    void getval();
private:
    int id;
    double val;
};

class LL
{
public:
    LL();
    void addNode(int,double);
    void delNode(int);
    void dispNode();
    node * findNode(int);
private:
    node * head = nullptr;
    node * tail = nullptr;
    static int LL_size;
};
#endif /* Source_h */
