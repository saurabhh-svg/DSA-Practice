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

void PrintLevelWise(BinaryTreeNode<int> *root){
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
            cout << front->data<<":";
       if(front->left!=NULL){
           cout << "L" << front->left->data;
           pendingNodes.push(front->left);
       }
       if(front->right!=NULL){
           cout << "R" << front->right->data;
           pendingNodes.push(front->right);
       }
       cout << endl;
    }
}
//Bad Method
void printTree(BinaryTreeNode<int> *root){
    if(root==NULL)
        return;
    cout << root->data << " : ";
    if(root->left != NULL){
        cout << "L" << root->left->data;
    }
    if(root->right != NULL){
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
} 
//Bad Method
 BinaryTreeNode<int>* takeinput(){
     int rootData;
     cout << "Enter data" << endl;
     cin >> rootData;
     if(rootData==-1) return NULL;
     BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
     BinaryTreeNode<int> *leftChild = takeinput();
      BinaryTreeNode<int> *rightChild = takeinput();
      root->left = leftChild;
      root->right = rightChild;
      return root;
 }

int main(){
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    // root->left = node1;
    // root->right = node2;

   // BinaryTreeNode<int> *root = takeinput();
   
   BinaryTreeNode<int> *root = takeInputLevelWise();
    PrintLevelWise(root);
    delete root;
}

//for input copy paste ->
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 