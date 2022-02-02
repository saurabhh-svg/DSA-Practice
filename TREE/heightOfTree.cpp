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
int heightofTree(BinaryTreeNode<int>* root){
   if(root==NULL)
       return 0;
        int ldepth =heightofTree(root->left);
        int rdepth = heightofTree(root->right);
        if(ldepth>rdepth)
            return ldepth + 1;
        else
            return rdepth + 1;
}

int main(){
   
   
   BinaryTreeNode<int> *root = takeInputLevelWise();
   cout<< heightofTree(root)<<endl;
}

//for input copy paste ->
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 