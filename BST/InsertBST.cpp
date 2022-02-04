#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;


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
BinaryTreeNode<int>* InsertinBst(BinaryTreeNode<int> *root, int key){
    

    BinaryTreeNode<int> *Insertme = new BinaryTreeNode<int>(0);
    Insertme->data = key; 
    Insertme->left = NULL;
    Insertme->right = NULL;
    if(root==NULL) return Insertme;

    if (key < root->data)
        root->left = InsertinBst(root->left, key);
    if (key > root->data)
        root->right = InsertinBst(root->right, key);

    return root;
}


    int main()
    {
        // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
        // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
        // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
        // root->left = node1;
        // root->right = node2;
        // BinaryTreeNode<int> *root = takeinput();

        BinaryTreeNode<int> *root = new BinaryTreeNode<int>(10);
      
        InsertinBst(root, 5);
        InsertinBst(root, 8);
         InsertinBst(root, 20);
         InsertinBst(root, 30);
 

        PrintLevelWise(root);

         delete root;
}

// for input copy paste ->
//  1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1