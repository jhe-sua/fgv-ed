#include <iostream>


// 0 <= number of childs <= 2
// left.keys <= x.key < right.keys
// -1 <= BF(x) <= 1
// BF = height(x.left) - height(x.right)


class Node
{
public:
    int key;
    int height = 0;

    Node* left = nullptr;
    Node* parent = nullptr;
    Node* right = nullptr;

    Node(int key);
    ~Node() = default;
};

Node::Node(int key)
    : key {key} 
{
}

class AVL
{
public:
    Node* root = nullptr;

    AVL();
    ~AVL() = default;

    Node* RotateLeft(Node* y);
};

AVL::AVL(/* args */)
{
}


Node* AVL::RotateLeft(Node* y)
{
    Node* x = y->right;
    Node* t2 = x->left;

    x->left = y;
    y->right = t2;

    y->parent = x;
    if(t2 != nullptr) t2->parent = y;

    ReComputeHeight(x);
    ReComputeHeight(y);
}

