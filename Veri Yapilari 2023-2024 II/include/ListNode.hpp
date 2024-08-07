#ifndef LISTNODE_HPP
#define LISTNODE_HPP

#include <iostream>
#include "Avl.hpp"
#include "Stack.hpp"
using namespace std;

class ListNode{
	public:	
		Avl item;
		int index;
		Stack* stack;
		char ascii;
		ListNode* next;
		ListNode(const Avl& item,int index,char ascii,Stack* stack,ListNode *nx=NULL);
        ListNode(const Avl& item,int index,char ascii,Stack* stack);
		~ListNode();
};
#endif