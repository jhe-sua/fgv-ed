#include <iostream>

using namespace std;

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

class Tree
{
private:
    Node* SearchHelper(Node* current, int key);
public:
    Node* root = nullptr;
    Tree() = default;
    ~Tree() = default;

    void Insert(int key);
    Node* Search(int key);
};

void Tree::Insert(int key)
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

Node* Tree::SearchHelper(Node* current, int key)
{
    if (current == nullptr) return nullptr;
    if (current->key == key) return current;

    if (key < current->key)
    {
        return SearchHelper(current->left, key);
    }

    return SearchHelper(current->right, key);
}

Node* Tree::Search(int key)
{
    return SearchHelper(root, key);
}

int main(void)
{   
    Tree arvore = Tree();
    arvore.Insert(20);
    arvore.Insert(10);
    arvore.Insert(5);
    arvore.Insert(2);
    arvore.Insert(25);
    arvore.Insert(30);
    arvore.Insert(7);
    dfs_pre(arvore.root);
    cout << endl;
    dfs_in(arvore.root);
    cout << endl;
    dfs_pos(arvore.root);
    cout << endl;
    return 0;
}
