#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here

        //My apporach is that in BST if both n1 and n2 are smaller than root then LCA lies in left subtree
        //if both n1 and n2 are greater than root then LCA lies in right subtree
        
        
        if(!root)
            return NULL;
        if(root -> data > n1 -> data && root -> data > n2 -> data)
            LCA(root -> left ,n1,n2);
        else if(root -> data < n1 -> data && root -> data < n2 -> data)
            LCA(root -> right,n1,n2);
        else
            return root;
    }
};

int main() {

    return 0;
}