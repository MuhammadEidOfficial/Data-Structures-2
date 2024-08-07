#ifndef AVLNODE_HPP
#define AVLNODE_HPP

#include "iostream"
using namespace std;
class AvlNode{
    public:
	    int data;
        AvlNode *left;
        AvlNode *right;
        int height;
        
        AvlNode(const int& vr,AvlNode* sl,AvlNode* sg);
        AvlNode(const int& vr);
};

#endif