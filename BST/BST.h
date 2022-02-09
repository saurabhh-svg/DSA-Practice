#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;
class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    BinaryTreeNode<int> *deleteData(BinaryTreeNode<int> *node, int key)
    {
        if (node == NULL)
            return NULL;
        if (key > node->data)
        {
            node->right = deleteData(node->right, key);
            return node;
        }
        else if (key < node->data)
        {
            node->left = deleteData(node->left, key);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(node->right, rightMin);
                return node;
            }
        }
    }

private:
    void PrintLevelWise(BinaryTreeNode<int> *root)
    {
        queue<BinaryTreeNode<int> *> pendingNodes;
        pendingNodes.push(root);

        while (pendingNodes.size() != 0)
        {
            BinaryTreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();
            cout << front->data << ":";
            if (front->left != NULL)
            {
                cout << " L" << front->left->data;
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                cout << " R" << front->right->data;
                pendingNodes.push(front->right);
            }
            cout << endl;
        }
    }

public:
    void printTree()
    {
        PrintLevelWise(root);
    }
    void deleteData(int data)
    {
        deleteData(root, data);
    }

private:
    BinaryTreeNode<int> *insert(BinaryTreeNode<int> *root, int key)
    {
        if (root == NULL)
        {
            BinaryTreeNode<int> *Insertme = new BinaryTreeNode<int>(key);
            return Insertme;
        }
        if (key < root->data)
            root->left = insert(root->left, key);
        else
            root->right = insert(root->right, key);
        return root;
    }

public:
    void insert(int data)
    {
        this->root = insert(this->root, data);
    }

private:
    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
            return false;
        if (node->data == data)
            return true;
        else if (data < node->data)
            return hasData(data, node->left);
        else
            return hasData(data, node->right);
    }

public:
    bool hasData(int data)
    {
        return hasData(data, root);
    }
};