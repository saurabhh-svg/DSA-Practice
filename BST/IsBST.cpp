#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

BinaryTreeNode<int> *takeInputLevelWise(){
    int rootData;
    cout << "Enter Root Data" << endl;
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0){
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter Left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)  {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter Right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)  {
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

int maxim(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(root->data,max(maxim(root->left),maxim(root->right)));
}
int minim(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MAX;
    return min(root->data, min(maxim(root->left), maxim(root->right)));
}

bool IsBST(BinaryTreeNode<int> *root)
{
    if(root==NULL)
        return true;
    int leftmax = maxim(root->left);
    int rightmin = minim(root->right);
    bool output = (root->data > leftmax) && (root->data < rightmin) && IsBST(root->left) && IsBST(root->right);
    return output;
}
class ISBSTReturn
{
public:
    int maximum;
    int minimum;
    bool IsBst;
};
//Better appraoch ********************

ISBSTReturn IsBST2(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        ISBSTReturn obj;
        obj.IsBst = true;
        obj.maximum = INT16_MIN;
        obj.minimum = INT16_MAX;
        return obj;
    }
    ISBSTReturn leftOutput = IsBST2(root->left);
    ISBSTReturn rightOutput = IsBST2(root->right);
    int mini = min(root->data, min(leftOutput.maximum, rightOutput.minimum));
    int maxi = max(root->data, max(leftOutput.maximum, rightOutput.minimum));
    bool isbstFinal = (root->data > leftOutput.maximum) && (root->data <= leftOutput.minimum) && leftOutput.IsBst && rightOutput.IsBst;
    ISBSTReturn obj;
    obj.minimum = mini;
    obj.maximum = maxi;
    obj.IsBst = isbstFinal;
    return obj;
}
bool isBST3(BinaryTreeNode<int>* root,int min=INT_MIN, int max=INT_MAX){
    if(root==NULL)
        return true;
        if(root->data<min || root->data>max)
            return false;
        bool isLeftok = isBST3(root->left, min, root->data - 1);
        bool isRightok = isBST3(root->right, root->data + 1, max);
        bool ans = isLeftok && isRightok;
        return ans;
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
    ISBSTReturn ob;
    cout << isBST3(root) << endl;
    delete root;
}

// for input copy paste ->
//  1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1