#ifndef AVL_HPP
#define AVL_HPP
#include "AvlNode.hpp"
#include "Stack.hpp"
class Avl{
	private:	
		AvlNode *root;
		int toplam;

		AvlNode* SearchAndAdd(AvlNode *subNode,const int& item);
		AvlNode* SwapWithLeftChild(AvlNode *subNode);
		AvlNode* SwapWithRightChild(AvlNode *subNode);
		bool DeleteNode(AvlNode *&subNode);
		void inorder(AvlNode *subNode);
		void preorder(AvlNode *subNode);
		void findToplam(AvlNode *subNode);
		void push_leafs(AvlNode*,Stack*&);
		
		int Height(AvlNode *subNode);
		void PrintLevel(AvlNode *subNode,int level);
		bool Search(AvlNode *subNode,const int& item);
	public:
		Avl();
		bool isEmpty()const;
		void Add(const int& item);
		void inorder();
		void preorder();
		void findToplam();
		void levelorder();
		int Height();
		bool Search(const int& item);
		void push_leafs(Stack *&);
		int get_toplam();
		friend ostream& operator<<(ostream& screen,Avl& right);
		friend bool operator==(const Avl& right,const Avl& left);
		void Clear();
		~Avl();
};


#endif