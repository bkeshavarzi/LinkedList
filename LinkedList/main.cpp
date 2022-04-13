
#include <iostream>
#include <list>
#include <algorithm>
#include "Source.h"

int main()
{
    
    //std::cout << "Test"<<std::endl;
    LL obj;
    obj.addNode(0,1.1);
    obj.addNode(1,2.4);
    obj.addNode(2,7.8);
    obj.addNode(3,9.2);
    //obj.dispNode();
    node * mynode = new node();
    mynode = obj.findNode(2);
    if (mynode != nullptr) mynode->getval();
}
