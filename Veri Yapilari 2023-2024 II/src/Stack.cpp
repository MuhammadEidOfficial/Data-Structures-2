#include "Stack.hpp"

Stack::Stack(){
    topOfStack=NULL;
    size = 0;
}
bool Stack::isEmpty()const{
    return size == 0;
}
void Stack::push(const int& item){
    StackNode* added = new StackNode(item);
    if(topOfStack!=NULL)
        added->next=topOfStack;
    topOfStack= added;
    size++;
}
int Stack::count(){
    return size;
}
void Stack::pop(){
    if(isEmpty()) throw "Stack is Empty";

    StackNode* silinecek = topOfStack;
    topOfStack=topOfStack->next;
    delete silinecek;
    size--;
    
}
const int& Stack::top()const{
    if(isEmpty()) throw "Stack is Empty";
    return topOfStack->item;
}
void Stack::makeEmpty(){
    while(!isEmpty()) pop();
}
void Stack::print(){
    StackNode* itr = topOfStack;

    while(itr != NULL){
        cout << itr->item << endl;
        itr = itr->next;
    }

}
Stack::~Stack(){
    makeEmpty();
}