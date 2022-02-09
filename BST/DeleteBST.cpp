#include <iostream>
#include "BST.h"
#include <queue>
using namespace std;
int height(BinaryTreeNode<int> *node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

BinaryTreeNode<int> *DeleteinBST(BinaryTreeNode<int> *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
    }
    if (key < root->data)
        root->left = DeleteinBST(root->left, key);
    else if (key > root->data)
        root->right = DeleteinBST(root->right, key);
    else
    {
        if (height(root->left) > height(root->right))
        {
        }
    }

    return root;
}
int main()
{
}

// for input copy paste ->
//  1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1