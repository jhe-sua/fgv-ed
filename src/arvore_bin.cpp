#include <iostream>

using namespace std;

class Node
{
public:
    Node* left = nullptr;
    Node* p = nullptr;
    Node* right = nullptr;

    int key;
    Node(int key);
    ~Node() = default;
};

Node::Node(int key)
    : key {key} 
{
}

class Tree
{
private:
public:
    Node* root = nullptr;
    Tree() = default;
    ~Tree() = default;

    void insert(int key);
};

void Tree::insert(int key)
{
    Node* new_node = new Node(key);

    if (root == nullptr)
    {
        root = new_node;
        return;
    }

    Node** atual = &root;

    while (*atual != nullptr)
    {   
        if ((*atual)->key > key)
        {
            atual = &((*atual)->left);
        } else
        {
            atual = &((*atual)->right);
        }
    }
    *atual = new_node;
}

void dfs_pre(Node* root)
{   
    if (root != nullptr)
    {
        cout << root->key << ", ";
        dfs_pre(root->left);
        dfs_pre(root->right);
    }
    
}

void dfs_in(Node* root)
{   
    if (root != nullptr)
    {
        dfs_in(root->left);
        cout << root->key << ", ";
        dfs_in(root->right);
    }
    
}

void dfs_pos(Node* root)
{   
    if (root != nullptr)
    {
        dfs_pos(root->left);
        dfs_pos(root->right);
        cout << root->key << ", ";
    }
}

int main(void)
{   
    Tree arvore = Tree();
    arvore.insert(20);
    arvore.insert(10);
    arvore.insert(5);
    arvore.insert(2);
    arvore.insert(25);
    arvore.insert(30);
    arvore.insert(7);
    dfs_pre(arvore.root);
    cout << endl;
    dfs_in(arvore.root);
    cout << endl;
    dfs_pos(arvore.root);
    cout << endl;
    return 0;
}
