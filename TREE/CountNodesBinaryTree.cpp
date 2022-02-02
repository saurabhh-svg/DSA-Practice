
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

/* you only have to complete the function given below.  
Node is defined as  

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

   int countNodes(Node *root) //pass pointer to root
{
    int x=0,y=0;
    if(root!=NULL)
    {
      x=countNodes(root->left);
      y=countNodes(root->right);
      return x+y+1;
    } 
      return 0;
}

//nodes for degree two

   int countNodes(Node *root) //pass pointer to root
{
    int x=0,y=0;
    if(root!=NULL)
    {
      x=countNodes(root->left);
      y=countNodes(root->right);
      if(root->left && root->right)
      return x+y+1;
      else
          return x + y;
    }
      return 0;
}



}; //End of Solution