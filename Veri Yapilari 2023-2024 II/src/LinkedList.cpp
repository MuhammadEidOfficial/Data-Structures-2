#include "LinkedList.hpp"

// private:
ListNode* LinkedList::FindPrevByPosition(int position){
    if(position < 0 || position > size) throw "Index out of range";
    int index=1;
    
    for(ListNode *itr=head;itr!=NULL;itr=itr->next,index++){
        if(position == index) return itr;
    }
    return NULL;
}
// public:
LinkedList::LinkedList(){
    head = NULL;	
    size=0;
}
bool LinkedList::isEmpty() const{
    return head == NULL;
}
int LinkedList::Count() const{
    return size;
}
const Avl& LinkedList::first(){
    if(isEmpty()) throw "Empty list";
    return head->item;
}
const Avl& LinkedList::last(){
    if(isEmpty()) throw "Empty list";
    return FindPrevByPosition(size)->item;
}
void LinkedList::add(const Avl& item,Stack* stk,char ascii){
    insert(size,item,stk,ascii);
}
void LinkedList::insert(int index,const Avl& item,Stack* stk,char ascii){
    if(index == 0) head = new ListNode(item,index + 1,ascii,stk, head);
    else{
        ListNode *prev = FindPrevByPosition(index);
        prev->next = new ListNode(item,index + 1,ascii,stk,prev->next);
    }						
    size++;
}
void LinkedList::remove(const Avl& item){
    int position = indexOf(item);
    removeAt(position);			
}
void LinkedList::removeAt(int index){
    if(size == 0) throw "Empty list";
    ListNode *del;
    if(index == 0){
        del = head;
        head = head->next;
    }
    else{
        ListNode *prev = FindPrevByPosition(index);
        del = prev->next;
        prev->next = prev->next->next;
    }
    delete del;
    size--;
}
bool LinkedList::find(const Avl& item) const{
    for(ListNode *itr=head;itr!=NULL;itr=itr->next){
        if(itr->item == item) return true;
    }
    return false;
}
int LinkedList::indexOf(const Avl& item){
    int index=0;
    for(ListNode *itr=head;itr!=NULL;itr=itr->next,index++){
        if(itr->item == item) return index;
    }
    throw "Index out of range";
}

ListNode* LinkedList::get_min_stack_node(int& index){
    if(size == 0) throw "Empty list";
    ListNode* result = head;
    ListNode* itr = head;
    int i = 0;
    int minIndex = 0;
    while(itr != NULL){
        if(itr->stack->top() < result->stack->top())
        {
            result = itr;
            minIndex = i;
        }
        
        itr = itr->next;
        i++;
    }
    index = minIndex;
    return result;
}
ListNode* LinkedList::get_max_stack_node(int& index){
    if(size == 0) throw "Empty list";
    ListNode* result = head;
    ListNode* itr = head;
    int maxIndex= 0;
    int i = 0;
    while(itr != NULL){
        if(itr->stack->top() > result->stack->top())
        {
            result = itr;
            maxIndex = i;
        }
        
        itr = itr->next;
    }
    index = maxIndex;
    return result;
}
void LinkedList::update_stacks(){
    if(size == 0) throw "Empty list";
    ListNode* itr = head;
    while(itr != NULL){
        delete itr->stack;
        itr->stack = new Stack();
        itr->item.push_leafs(itr->stack);
        itr = itr->next;
    }
}
void LinkedList::run(){
    while(size != 1){
        ListNode* itr = head;
        int minIndex = 0;
        ListNode* minNode = get_min_stack_node(minIndex);
        minNode->stack->pop();
        if(minNode->stack->isEmpty()){
            removeAt(minIndex);
            if(size > 1)
                update_stacks();
            system("CLS");
            cout << *this << endl;
            continue;   
        }
        int maxIndex = 0;
        ListNode* maxNode = get_max_stack_node(maxIndex);
        maxNode->stack->pop();
        if(maxNode->stack->isEmpty()){
            int maxIndex = indexOf(maxNode->item);
            removeAt(maxIndex);

            if(size > 1)
                update_stacks();
            system("CLS");       
            cout << *this << endl;

            continue;   
        }

    }
}
ostream& operator<<(ostream& screen, LinkedList &right){
    if(right.isEmpty()) screen<<"Empty list";
    else if (right.Count() == 1){
        ListNode *itr=right.head;
        screen << "=============================="<<endl;
        screen << "|" <<  "                            " << "|" << endl;
        screen << "|" <<  "                            " << "|" << endl;
        screen << "|" << "     " << "Son Karakter:" << itr->ascii <<"         " << "|" << endl;
        screen << "|"<< "     "  << "AVL No" << "      :" <<itr->index <<"       "<< "|" <<  endl;
        screen << "|" <<  "                            " << "|" << endl;
        screen << "=============================="<<endl;
    }
    else{
        for(ListNode *itr=right.head;itr!=NULL;itr=itr->next){
            screen<<itr->item;
        }
    }
    return screen;
}
void LinkedList::clear(){
    while(!isEmpty())
        removeAt(0);			
}
LinkedList::~LinkedList(){
    clear();
}
