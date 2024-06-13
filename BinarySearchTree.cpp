#include<iostream>
#include <string>
using namespace std;

class Node
{
    public:
    string info;
    Node* leftchild;
    Node* rightchild;

    // constructor for the node class
    Node(string i, Node* l, Node* r),
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class BinaryTree
{
    public:
        Node* ROOT;

        BinaryTree()
        {
            ROOT = nullptr; // initializing root to null
        }
    void insert(string element) // insert a node in the binary search tree
    {
        Node* newNode = new Node(element,nullptr, nullptr); //allocate memory for the new node
        newNode->info = element; //assign value to the data field of the new data
        newNode->leftchild = nullptr; // make the left child of the new node point to null
        newNode->rightchild = nullptr; // make the right child of the new data point to null

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode); //locate the new node wich be the parent of the node to be inserted

        if (parent == nullptr) // if the parent is null (tree is empty)
        {
            ROOT = newNode; // mark the new node as root
            return; //exit
        }

        if(element < parent->info) //if the value in the data field of the new node is less than of the parent
        {
            parent->leftchild = newNode; // make the left child of the parent point to the new node
        }
        else if (element > parent->info) // if the data data field of the new data is greater than that of the parent
        {
            parent->rightchild = newNode; // make the right child of the parent point to the new node
        }
    }

    void search(string element, Node*& parent, Node*& currentNode)
    {
        // this function searches the currentnode of the specified node as well as the current node of its parent
             currentNode = ROOT;
             parent = NULL;
             while ((currentNode !=NULL) && (currentNode->info != element))
             {
                parent = currentNode;
                if (currentNode < currentNode->info)
                    currentNode = currentNode->leftchild;
                else 
                    currentNode = currentNode->rightchild;
             }
    }
    void inorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            inorder(ptr->leftchild);
            cout << ptr->info <<  " ";
            inorder(ptr->rightchild);
        }
    }
    void preorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr !=NULL)
        {
            cout << ptr->info<<" ";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        }
    }

    void postorder(Node* ptr)
    {
        // performs the postorder traversal of the tree
        if (ROOT == NULL)
        {
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << " ";
        }
    }
};