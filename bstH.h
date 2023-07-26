
#include<iostream>
using namespace std;
class Node
{
    public:
    Node *right;
    Node *left;
    int data;
    Node(): data(0), right(nullptr), left(nullptr){}
    Node(int data): data(data),right(nullptr), left(nullptr){}
    int degree(Node*& node);
};

//degree function
int Node::degree(Node*& node)

{
    int degree;
    if(node->left != nullptr && node->right != nullptr) return degree=2;
    else if(node->right != nullptr) return degree=1;
    else if(node->left != nullptr) return degree=1;
    return degree = 0;
}

class BST
{
    private:
    Node* root;
    bool insert(Node *&node, int data);
    bool remove(Node *&node, int data);
    bool find(Node* node, int data);
    void inOrder(Node* node, ostream& os);
    void preOrder(Node* node, ostream& os);
    void postOrder(Node*  , ostream& os);
    void destroy(Node*& node);
    public:
    BST(): root(nullptr) {}
    //~BST();

    //public-facing functions
    bool insert(int data)
    {
        return insert(root, data);
    }
    bool remove(int data)
    {
        return remove(root, data);
    }
    bool find(int data)
    {
        return find(root, data);
    }
    void inOrder(ostream& os) 
    {
        inOrder(root, os);
    }
    void preOrder(ostream& os) 
    {
        preOrder(root, os);
    }
    void postOrder(ostream& os)
    {
        postOrder(root, cout);
    }
};