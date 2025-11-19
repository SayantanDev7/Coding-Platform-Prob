#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
  public:
  bool checkBST(Node* root,int &prev){
      if(!root)
            return 1; //returnin 1 because 0 is alloted for non BST
        bool l = checkBST(root -> left,prev); //chekcing left subtree
        if(l == 0)
            return 0;
        if(root -> data <= prev)
           return 0;
         
        prev = root -> data;
        
        
        return checkBST(root -> right,prev);
  }
    bool isBST(Node* root) {
        // code here
        int prev = INT_MIN;
        return checkBST(root,prev);
    }
};