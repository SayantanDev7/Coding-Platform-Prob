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
    void inorder(Node* root,vector<int> &ans){
        if(!root)
            return;
        inorder(root -> left,ans);
        ans.push_back(root -> data);
        inorder(root -> right,ans);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // code here
        
        vector<int> ans;
        
        //traversing both the BST using inorder traversal
        inorder(root1,ans);
        inorder(root2,ans);
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};
int main(){
    return 0;
}