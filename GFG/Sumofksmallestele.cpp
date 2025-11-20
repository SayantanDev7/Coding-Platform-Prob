// User function Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};


int helper(Node* root, int &k) {
    if (!root || k <= 0)
        return 0;

    int sumnode = 0;

    // Left subtree
    sumnode += helper(root->left, k);

    // Visit root
    
    if (k > 0){
        sumnode += root->data;
        k--;
    }
    else
        return sumnode;

    // Right subtree
    sumnode += helper(root->right, k);

    return sumnode;
}

int sum(Node* root, int k) {

    // Your code here
    return helper(root,k);
}
int main(){
        Node* root = new Node(5);
        root->left = new Node(3);
        root->right = new Node(8);
        root->left->left = new Node(2);
        root->left->right = new Node(4);
        int k = 3;
        cout<<sum(root,k);
                
        return 0;
}