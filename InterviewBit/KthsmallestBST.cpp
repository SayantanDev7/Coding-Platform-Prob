
#include <bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
void inorder(TreeNode* A,vector<int> &nodelist){
    if(!A)
        return;
    inorder(A -> left,nodelist);
    nodelist.push_back(A -> val);
    inorder(A -> right,nodelist);
}
class Solution {
public:
    int kthsmallest(TreeNode* A, int B) {
        vector<int> nodelist;
        inorder(A, nodelist);
        return nodelist[B - 1];
    }
};

int main(){
     TreeNode* root = new TreeNode(5);
        root->left = new TreeNode(3);
        root->right = new TreeNode(8);
        root->left->left = new TreeNode(2);
        root->left->right = new TreeNode(4);
        int k = 3;
        cout<<Solution().kthsmallest(root,k);
              
    return 0;
}
