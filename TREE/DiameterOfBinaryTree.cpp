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

int height(BinaryTreeNode<int>* root){
    if(root==NULL)
        return 0;
    return 1+ max( height(root->left),height(root->right));
}
int diameter(BinaryTreeNode<int>* root){
    if(root==NULL)
        return 0;
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

int main(){
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    // root->left = node1;
    // root->right = node2;

   // BinaryTreeNode<int> *root = takeinput();
   
   BinaryTreeNode<int> *root = takeInputLevelWise();
   cout<<"diameter"<<diameter(root);
   // PrintLevelWise(root);
   delete root;
}

//for input copy paste ->
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 