//
//  Source.cpp
//  LinkedList
//
//  Created by Behrooz Keshavarzi on 4/11/22.
//

#include <stdio.h>
#include "Source.h"

node::node()
{
    
}
void node::getval()
{
    std::cout << val <<std::endl;
}
LL::LL()
{
}
void LL::addNode(int i, double v)
{
    if (head==nullptr)
    {
        head = new node();
        head->id = i;
        head->val = v;
    }
    else if (tail == nullptr)
    {
        tail = new node();
        tail->id = i;
        tail->val = v;
        tail->next = head;
        tail->prev = head;
        head->next = tail;
        head->prev = tail;
    }
    else
    {
        node * newNode = new node();
        newNode->id = i;
        newNode->val = v;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}
void LL::delNode(int i)
{
    bool is_found = false;
    
    if (head == nullptr && tail == nullptr)
    {
        std::cout << "There is no node in the linked list" << std::endl;
    }
    else
    {
        node * tempNode = new node();
        
        if (head == tail)
        {
            tempNode = head;
            delete tempNode;
            node * tempNode = new node();
            tempNode = tail;
            delete tempNode;
        }
        else
        {
            tempNode = head;
            while (tempNode->next != tail)
            {
                if (tempNode->id == i)
                {
                    tempNode->prev->next = tempNode->next->prev;
                    delete tempNode;
                    is_found = true;
                    break;
                }
                else tempNode = tempNode->next;
            }
            if (is_found == false) std::cout << "There is no node with id = " << i <<std::endl;
        }
    }
}
void LL::dispNode()
{
    if (head==nullptr&&tail==nullptr) {std::cout<<"There is no node to show"<<std::endl;return;}
    if (head != nullptr) std::cout << "Head id is : " << head->id <<" Head val is :"<< head->val << std::endl;
    if (head != tail)
    {
        node * tempNode = new node();
        tempNode = head->next;
        while (tempNode !=tail)
        {
            std::cout << "Id is = "<<tempNode->id<<" val is = "<<tempNode->val<<std::endl;
            tempNode = tempNode->next;
        }
        tempNode = nullptr;
        delete tempNode;
    }
    if (tail != nullptr) std::cout << "Tail id is : " << tail->id <<" Tail val is :"<<tail->val <<std::endl;
}
node * LL::findNode(int i)
{
    if (head == nullptr && tail == nullptr) return nullptr;
    else
    {
        node * tempNode = new node();
        tempNode = head;
        while (tempNode != tail)
        {
            if (tempNode->id == i) {return tempNode;}
            else tempNode = tempNode->next;
        }
        if (tail->id == i) {return tempNode;}
        else {tempNode = nullptr; delete tempNode; std::cout << "not found !" <<std::endl; return nullptr;}
    }
}
