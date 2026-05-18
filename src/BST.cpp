#include <iostream>

class Node
{
public:
    int key;
    Node* left = nullptr;
    Node* p = nullptr;
    Node* right = nullptr;

    Node(int key);
    ~Node() = default;
};

Node::Node(int key)
    : key {key} 
{
}

class BST
{
public:
    Node* root = nullptr;
    BST(/* args */);
    ~BST();

    Node* Search(Node* root, int key);
    void Insert(int key);
};

BST::BST(/* args */)
{
}

BST::~BST()
{
}

Node* Search(Node* root, int key)
{
    if (root == nullptr) return;
    if (root->key == key) return;

    if (key < root->key)
    {
        return Search(root->left, key);
    }
    
    return Search(root->right, key);   
}

Node* Insert(Node* root, int key)
{
    if (root == nullptr)
    {
        Node* new_node = new Node(key);
        return new_node;
    }

    if (key > root->key)
    {
        Node* new_node = Insert(root->right, key);
        root->right = new_node;
        new_node->p = root;
    } else
    {
        Node* new_node = Insert(root->left, key);
        root->left = new_node;
        new_node->p = root;
    }
    return root;
}
