#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
    Node* delNode(Node* root, int x) {
        // code here
        if(!root)
            return NULL;
        if(x < root -> data){
            root -> left = delNode(root -> left,x);
            return root; //returning the root after deletion in left subtree
        }
        
        else if(x > root -> data){
            root -> right = delNode(root -> right,x);
            return root; //returning the root after deletion in right subtree
        }
        else{
            //x is a leaf Node
            if(!root -> left && !root -> right){
                delete root;
                return NULL;
            }
            
            //x is a node having only right child
            if(!root -> left && root -> right){ // No left child only
                Node* temp = root -> right;//store the right child in a variable
                delete root;
                return temp;
            }
            //x is a node having only left child
            if(root -> left && !root -> right){ // No left child only
                Node* temp = root -> left;//store the right child in a variable
                delete root;
                return temp;
            }
            
            //x is a node having both left and right child
            else{
                //Find the largest ele from the leftsubtree of x
                Node* parent = root;
                Node* child = root -> left;
                //its a bst i.e largest element in the leftsubtree will be present in rightside
                //i.e traverse till the rightmose node
                while(child -> right){
                    parent = child; //updating parent 
                    child = child -> right;//updating child
                }
                //We can not directly delete the child it can have left child present
                
                
                if(root != parent){
                    if(child -> left) //if the child node has a left child make parent point to it
                        parent -> right = child -> left;
                    //Now updating child inplace of root node
                    else
                        parent -> right = NULL;
                         child->left  = root->left;
                    child -> right = root -> right;
                    delete root;
                    return child;
                }
                
                //if the parent is root node itself(i.e if the parent is the target node to be deleted)
                else{
                    child -> right = root -> right;
                    delete root;
                    return child;
                }
                
            }
        }
        return root;
    }
};

void inorder(Node* root){
    if(!root) return;
    inorder(root -> left);
    cout<<root -> data<<" ";
    inorder(root -> right);
}
int main(){
    Solution sol;
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int key = 50;
    root = sol.delNode(root, key);

    // Inorder traversal to verify the result
    function<void(Node*)> inorder = [&](Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    };

    inorder(root);
    cout << endl;

    return 0;
}