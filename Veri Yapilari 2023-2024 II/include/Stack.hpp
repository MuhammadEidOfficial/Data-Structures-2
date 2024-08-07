#ifndef STACK_HPP
#define STACK_HPP

#include "StackNode.hpp"
class Stack{
	private:
		StackNode *topOfStack;
		int size;
		
	public:
		Stack();
		bool isEmpty()const;
		void push(const int& item);
		void pop();
		int count();
		const int& top()const;
		void makeEmpty();
		void print();
		~Stack();
};

#endif