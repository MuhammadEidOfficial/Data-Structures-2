#ifndef STACKNODE_HPP
#define STACKNODE_HPP

#include <iostream>
using namespace std;

class StackNode{
	public:
		StackNode(int);
		int item;
		StackNode* next;
};

#endif