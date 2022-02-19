#include <iostream>
#include "BST.h"
#include <queue>
using namespace std;

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter Root Data" << endl;
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter Left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter Right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
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
            cout << "L" << front->left->data;
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}

int height(BinaryTreeNode<int> *node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}
BinaryTreeNode<int> *InPre(BinaryTreeNode<int> *root)
{
    while(root && root->right!=NULL){
        root = root->right;
    }
    return root;
}
BinaryTreeNode<int> *InSucc(BinaryTreeNode<int> *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

    BinaryTreeNode<int> *DeleteinBST(BinaryTreeNode<int> * root, int key)
    {
        BinaryTreeNode<int> *q;

        if (root == NULL)
        {
            return NULL;
        }
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        if (key < root->data)
            root->left = DeleteinBST(root->left, key);
        else if (key > root->data)
            root->right = DeleteinBST(root->right, key);
        else
        {
            if (height(root->left) > height(root->right))
            {
                q = InPre(root->left);
                root->data = q->data;
                root->left = DeleteinBST(root->left, q->data);
            }
            else
            {
                q = InSucc(root->right);
                root->data = q->data;
                root->right = DeleteinBST(root->right, q->data);
            }
        }

        return root;
    }
    int main()
    {
        BinaryTreeNode<int> *root = takeInputLevelWise();
        PrintLevelWise(root);
        DeleteinBST(root,1);
        PrintLevelWise(root);
    }

    // for input copy paste ->
    //  1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1