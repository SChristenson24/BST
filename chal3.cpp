#include <iostream>
#include "bstH.h"

using namespace std;


bool BST::find(Node *node, int data)
{
    if (node == nullptr)
    {
        return false;
    }

    if (data < node->data)
    {
        return find(node->left, data);
    }

    if (data > node->data)
    {
        return find(node->right, data);
    }

return true; 
}

bool BST::insert(Node*& node, int data)
{
    if (node == nullptr) 
    { 
        node = new Node(data); 
        return true; 
    }
    if (data < node->data) return insert(node->left, data);
    if (data > node->data) return insert(node->right, data);
    return false;
}

bool BST::remove(Node*& node, int data)
{
    Node childNode;
    if (node == nullptr)  return false;
    if (data < node->data) return remove(node->left, data);
    if (data > node->data) return remove(node->right, data);

    int deg = childNode.degree(node);

    if(deg == 0)
    {
        delete node;
        node = nullptr;
    }

    else if (deg ==1)
    {
        Node* tmp = node;
        if (node->left != nullptr)
        {
            node = node->left;
        }

        else
        {
            node = node->right;
        }

        delete tmp;
    }

    else if (deg == 2)
    {
        Node* tmp = node->left;
        while(node->right != nullptr)
        {
            tmp = tmp->right;
        }

        node->data = tmp->data;
        remove(node->left, tmp->data);
    }

    return true;
}

void BST::postOrder(Node* node, ostream& os)//LRN
{
    if (node == nullptr) return;
    postOrder(node->left, os);
    postOrder(node->right, os);
    os << node->data << " ";
}
void BST::preOrder(Node* node, ostream& os) //NLR
{
    if (node == nullptr) return;
    os << node->data << " ";
    preOrder(node->left, os);
    preOrder(node->right, os);  
}
void BST::inOrder(Node* node, ostream& os) //LNR
{
    if (node == nullptr) return;
    inOrder(node->left, os);
    os << node->data << " ";
    inOrder(node->right, os);  
}

int main()
{
    BST b;
    b.insert(56);
    b.insert(34);
    b.insert(70);
    b.insert(5);
    b.insert(1);
    b.insert(42);
    b.insert(40);
    b.insert(52);
    b.insert(62);
    b.insert(57);
    b.insert(89);
    b.insert(90);
    cout << b.find(44) << endl;
    cout << b.find(62) << endl;
    b.remove(62);
    cout << b.find(62) << endl;
    b.insert(44);
    cout << b.find(44) << endl;
    cout << "Post Order: ";
    b.postOrder(cout);
    cout << endl;
    cout << "Pre Order: ";
    b.preOrder(cout);
    cout << endl;
    cout << "In Order: ";
    b.inOrder(cout);
}