#ifndef LinkedList_HPP
#define LinkedList_HPP

#include "ListNode.hpp"

class LinkedList{
	private:
		ListNode *head;
		int size;
        
		ListNode* FindPrevByPosition(int position);
	public:
		LinkedList();
		bool isEmpty() const;
		int Count() const;
		const Avl& first();
		const Avl& last();
		void add(const Avl& item,Stack* stack,char ascii);
		void insert(int index,const Avl& item,Stack* stack,char ascii);
		void remove(const Avl& item);
		void removeAt(int index);
		bool find(const Avl& item) const;
		int indexOf(const Avl& item);
		
		ListNode* get_min_stack_node(int&);
		ListNode* get_max_stack_node(int&);
		void run();
		void update_stacks();


		friend ostream& operator<<(ostream& screen, LinkedList &right);
		void clear();
		~LinkedList();
};
#endif