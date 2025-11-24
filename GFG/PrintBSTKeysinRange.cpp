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
    void Find(Node* root,vector<int> &ans,int n1,int n2){
        if(!root)
            return;
        if(root -> data > n1 && root -> data > n2)
            Find(root -> left,ans,n1,n2);
        else if(root -> data < n1 && root -> data < n2)
            Find(root -> right,ans,n1,n2);
        else{
            Find(root -> left,ans,n1,n2);
            ans.push_back(root -> data);
            Find(root -> right,ans,n1,n2);
            
        }
            
            
    }
    vector<int> printNearNodes(Node *root, int low, int high) {
        // code here
        vector<int> ans;
        
        Find(root,ans,low,high);
            
        return ans;
    }
};
int main() {

    return 0;
}