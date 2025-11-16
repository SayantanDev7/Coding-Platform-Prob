#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
class Solution {
  public:
  
    // Returns:
    //  - negative value if target found (distance upward as negative)
    //  - positive height if not found
    int Burn(Node* root, int target, int &timer) {

        if (!root) return 0;

        // Target found at this node
        if (root->data == target)
            return -1;   // negative indicates upward distance

        int left = Burn(root->left, target, timer);
        int right = Burn(root->right, target, timer);

        // If target found in left subtree
        if (left < 0) {
            timer = max(timer, (-left) + right);
            return left - 1;    // go one level upward
        }

        // If target found in right subtree
        if (right < 0) {
            timer = max(timer, (-right) + left);
            return right - 1;
        }

        // If target not found in either subtree → return height
        return 1 + max(left, right);
    }

    // Find the target node pointer inside the tree
    void find(Node* root, int target, Node* &BurnNode) {
        if (!root) return;

        if (root->data == target) {
            BurnNode = root;
            return;
        }
        find(root->left, target, BurnNode);
        find(root->right, target, BurnNode);
    }

    // Normal height of a subtree
    int Height(Node* root) {
        if (!root) return 0;
        return 1 + max(Height(root->left), Height(root->right));
    }

    int minTime(Node* root, int target) {

        int timer = 0;
        
        // Corrected parameter order
        Burn(root, target, timer);

        // Find target node pointer
        Node* BurnNode = NULL;
        find(root, target, BurnNode);

        // Height of subtree under target
        int height = Height(BurnNode) - 1;

        return max(timer, height);
    }
};
int main(){
    Node* root = new Node();
    root -> data = 1;
    root -> left = new Node();
    root -> left -> data = 2;
    root -> right = new Node();
    root -> right -> data = 3;
    root -> left -> left = new Node();
    root -> left -> left -> data = 4;
    root -> left -> right = new Node();
    root -> left -> right -> data = 5;
    Solution obj;
    int target = 2;
    cout<<obj.minTime(root, target);
    return 0;
}