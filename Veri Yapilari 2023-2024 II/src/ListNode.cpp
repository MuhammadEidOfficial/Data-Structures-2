#include "ListNode.hpp"


ListNode::ListNode(const Avl& item,int index,char ascii,Stack* stk,ListNode *nx){
    this->item=item;
    this->index = index;
    this->ascii = ascii;
    this->stack = stk;
    next=nx;
}
ListNode::ListNode(const Avl& itemm,int index,char ascii,Stack* stk) : ListNode(item,index,ascii,stk,NULL) { }

ListNode::~ListNode(){
    delete stack;
}
