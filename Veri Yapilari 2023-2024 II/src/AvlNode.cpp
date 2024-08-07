#include "AvlNode.hpp"

AvlNode::AvlNode(const int& vr,AvlNode* sl,AvlNode* sg){
    data = vr;
    left = sl;
    right = sg;
    height=0;
        
}
AvlNode::AvlNode(const int& vr):AvlNode(vr,NULL,NULL){}