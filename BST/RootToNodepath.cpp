#include <iostream>
#include "BinaryTreeNode.h"
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

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root,int key){
    if(root==NULL)
        return NULL;
        if(root->data==key){
            vector<int>* output = new vector<int>();
            output->push_back(root->data);
            return output;
        }
        vector<int>* leftoutput = getRootToNodePath(root->left, key);
        if (leftoutput != NULL){
            leftoutput->push_back(root->data);
            return leftoutput;
        }
        vector<int> *rightOutput = getRootToNodePath(root->right, key);
            if(rightOutput!=NULL){
            rightOutput->push_back(root->data);
            return rightOutput;
            }else return NULL;
}

int main()
{
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    // root->left = node1;
    // root->right = node2;

    // BinaryTreeNode<int> *root = takeinput();

    BinaryTreeNode<int> *root = takeInputLevelWise();
    vector<int>* op = getRootToNodePath(root, 7);
    for (int i = 0; i < op->size();i++)
        cout << op->at(i) << " -> ";

        delete output;
}

// for input copy paste ->
//  1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1