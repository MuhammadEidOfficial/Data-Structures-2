#include "Avl.hpp"

//private:

AvlNode* Avl::SearchAndAdd(AvlNode *subNode,const int& item){
    if(subNode == NULL) subNode = new AvlNode(item);
    else if(item < subNode->data){
        subNode->left = SearchAndAdd(subNode->left,item);
        
        if(Height(subNode->left) == Height(subNode->right)+2){
            if(item < subNode->left->data)
                subNode = SwapWithLeftChild(subNode);
            else{
                subNode->left = SwapWithRightChild(subNode->left);
                subNode = SwapWithLeftChild(subNode);
            }
        }
    }
    else if(item > subNode->data){
        subNode->right = SearchAndAdd(subNode->right,item);
        
        if(Height(subNode->right) == Height(subNode->left)+2){
            if(item > subNode->right->data)
                subNode = SwapWithRightChild(subNode);
            else{
                subNode->right = SwapWithLeftChild(subNode->right);
                subNode = SwapWithRightChild(subNode);
            }
        }
    }
    else;
    
    subNode->height = Height(subNode);
    return subNode;
}
AvlNode* Avl::SwapWithLeftChild(AvlNode *subNode){
    AvlNode *tmp = subNode->left;
    subNode->left = tmp->right;
    tmp->right = subNode;
    
    subNode->height = Height(subNode);
    tmp->height = 1+max(Height(tmp->left),subNode->height);
    
    return tmp;
}
AvlNode* Avl::SwapWithRightChild(AvlNode *subNode){
    AvlNode *tmp = subNode->right;
    subNode->right = tmp->left;
    tmp->left = subNode;
    
    subNode->height = Height(subNode);
    tmp->height = 1+max(Height(tmp->right),subNode->height);
    
    return tmp;
}
bool Avl::DeleteNode(AvlNode *&subNode){
    AvlNode *delNode = subNode;
    
    if(subNode->right == NULL) subNode = subNode->left;
    else if(subNode->left == NULL) subNode = subNode->right;
    else{
        delNode = subNode->left;
        AvlNode *parentNode = subNode;
        while(delNode->right != NULL){
            parentNode = delNode;
            delNode = delNode->right;
        }
        subNode->data = delNode->data;
        if(parentNode == subNode) subNode->left = delNode->left;
        else parentNode->right = delNode->left;
    }
    delete delNode;
    return true;
}
void Avl::inorder(AvlNode *subNode){
    if(subNode != NULL){
        inorder(subNode->left);
        cout<<subNode->data<<" ";
        inorder(subNode->right);
    }
}
void Avl::preorder(AvlNode *subNode){
    if(subNode != NULL){
        cout<<subNode->data<<" ";
        preorder(subNode->left);
        preorder(subNode->right);
    }
}
void Avl::findToplam(AvlNode *subNode){
    if(subNode != NULL){
        findToplam(subNode->left);
        findToplam(subNode->right);
        if(subNode->right != NULL || subNode->left != NULL)
            toplam+=subNode->data;
    }
}
void Avl::push_leafs(Stack*& leafNodes){
    push_leafs(root,leafNodes);
}
void Avl::push_leafs(AvlNode* root,Stack*& leafNodes) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        leafNodes->push(root->data);
        return;
    }
    push_leafs(root->left, leafNodes);
    push_leafs(root->right, leafNodes);
}
int Avl::Height(AvlNode *subNode){
    if(subNode == NULL) return -1;
    return 1+max(Height(subNode->left),Height(subNode->right));
}
void Avl::PrintLevel(AvlNode *subNode,int level){
    if(subNode == NULL) return;
    if(level == 0) cout<<subNode->data<<" ";
    else{
        PrintLevel(subNode->left,level-1);
        PrintLevel(subNode->right,level-1);
    }
}
bool Avl::Search(AvlNode *subNode,const int& item){
    if(subNode == NULL) return false;
    if(subNode->data == item) return true;
    if(item < subNode->data) return Search(subNode->left,item);
    else return Search(subNode->right,item);
}
// public:
Avl::Avl(){
    root = NULL;
    toplam = 0;
}
bool Avl::isEmpty()const{
    return root == NULL;
}
void Avl::Add(const int& item){
    root = SearchAndAdd(root,item);
}
void Avl::inorder(){
    inorder(root);
}
void Avl::preorder(){
    preorder(root);
}
void Avl::findToplam(){
    findToplam(root);
}
void Avl::levelorder(){
    int h = Height();
    for(int level=0;level<=h;level++){
        PrintLevel(root,level);
    }
}
int Avl::Height(){
    return Height(root);
}
bool Avl::Search(const int& item){
    return Search(root,item);
}
ostream& operator<<(ostream& screen,Avl& right){
    //right.findToplam();
    screen << (char)(right.get_toplam()%(90-65 + 1) + 65);
    return screen;
}

bool operator==(const Avl& left,const Avl& right){
    return &left == &right;
}
int Avl::get_toplam(){
    return toplam;
}

void Avl::Clear(){
    while(!isEmpty()) DeleteNode(root);
}
Avl::~Avl(){
    Clear();
}
