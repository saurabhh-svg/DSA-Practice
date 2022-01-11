//hackerrannk 
#include<iostream>
#include <bits/stdc++.h>	

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/

    void levelOrder(Node * root) {
       queue <Node*> q;  //creating a queue to store addresses of the nodes
       cout<<root->data<<" ";  
       q.push(root);  //enquing address of nodes 
    while(!q.empty()){
       Node* root = q.front(); //taking out the first adress and deleting it
            q.pop(); 
        if(root->left){  //if left child exists
             cout<<root->left->data<<" ";
             q.push(root->left);
        }
        if(root->right){
            cout<<root->right->data<<" ";
            q.push(root->right);
        }
    }
       

    }

}; //End of Solution

