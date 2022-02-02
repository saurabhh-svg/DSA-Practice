#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter Root Data" << endl;
    cin >> rootData;
    if(rootData==-1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter Left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData!=-1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
        front->left = child;
        pendingNodes.push(child);
        }
        cout << "Enter Right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData!=-1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
        front->right = child;
        pendingNodes.push(child);
        }
    }
    return root;
}
//is node with a certain data is present or not ?
bool IsNodePresent(BinaryTreeNode<int>* root,int key){
    if(root==NULL)
        return false;
    if (root->data == key)
        return true;
   return IsNodePresent(root->left, key) || IsNodePresent(root->right, key);
    
}

int main(){
   
   
   BinaryTreeNode<int> *root = takeInputLevelWise();
   int key;
   cin >> key;
   cout<<IsNodePresent(root, key)<<endl;
   delete root;
}

//for input copy paste ->
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 