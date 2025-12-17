#include <bits/stdc++.h>
using namespace std;
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    
    int totalnode(Node* root){
        if(!root){
            return 0;
        }
        return 1 + totalnode(root -> left) + totalnode(root -> right);
    }
    
    int CBT(Node* root,int ind,int totalnodes){
        if(!root)
            return 1;
        
        if(ind >= totalnodes) //violating CBT property
            return 0;
        
        return CBT(root -> left,2*ind+1,totalnodes) && CBT(root -> right,2*ind+2,totalnodes);
    }
    
    bool MaxHeap(Node* root){
        if(root -> left){
            if(root -> data < root -> left -> data)
                return 0;
            if(!MaxHeap(root -> left))
                return 0;
        }
        if(root -> right){
             if(root -> data < root -> right -> data)
                return 0;
            return MaxHeap(root -> right);
        }
        return 1;
    }
    bool isHeap(Node* tree) {
        // code here
        int count = totalnode(tree);
        
        //check the condition index -> totalnode if yes then its not CBT
        if(!CBT(tree,0,count)){
            return 0;
        }
        //Now check for Heap property which is parent >= child
        return MaxHeap(tree);
    }
};
int main() {
    Solution sol;
    
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    
    if (sol.isHeap(root)) {
        cout << "The binary tree is a max-heap." << endl;
    } else {
        cout << "The binary tree is not a max-heap." << endl;
    }
    
    return 0;
}