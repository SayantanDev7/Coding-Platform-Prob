#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
};


int getheight(Node* root){
    if(!root)
        return 0;
    return root -> height;
}

int getbalance(Node* root){
    return getheight(root -> left) - getheight(root -> right);
}

// For LL unbalanced
Node* rightrotation(Node* root){
    //Right Rotation on root
    Node* child = root -> left;
    Node* childright = child -> right;
    //Managaing edge case by making childright as root's left
    child -> right = root;
    root -> left = childright;
    //updating height and child after rotation  
    root -> height = 1 + max(getheight(root -> left),getheight(root -> right));
    child -> height = 1 + max(getheight(child -> left),getheight(child -> right));
    //connecting new root to its parent
    return child;
}

// For RR unbalanced
Node* leftrotation(Node* root){
    //Left Rotation on root
    Node* child = root -> right;
    Node* childleft = child -> left;
    //Managaing edge case by making childleft as root's right
    child -> left = root;
    root -> right = childleft;
    //updating height and child after rotation
    root -> height = 1 + max(getheight(root -> left),getheight(root -> right));
    child -> height = 1 + max(getheight(child -> left),getheight(child -> right));

    //connecting new root to its parent
    return child;
}
Node* deleteNode(Node* root, int data) {
    // add code here,
    if(!root)
        return NULL;
    if(data < root -> data)
        root -> left = deleteNode(root -> left,data);
    else if(data > root -> data)
        root -> right = deleteNode(root -> right,data);
    else
        {
            //Leaf Node
            if(!root -> left && !root -> right){
                delete root;
                return NULL;
            }
            //Has Single Child
            //Has Left child only
            else if(root -> left && !root -> right){
                Node* temp = root -> left;
                delete root;
                return temp;
            }
            //Has Right child only
            else if(!root -> left && root -> right){
                Node* temp = root -> right;
                delete root;
                return temp;
            }
            //Has Both child
            else{
                //Replace the root with the right child min
                Node* child = root -> right;
                while(child -> left){
                    child = child -> left;
                }
                root -> data = child -> data;
                root -> right = deleteNode(root -> right, child -> data);
            }
        }
        //update height
        root -> height = 1+ max(getheight(root -> left),getheight(root -> right));
        
        int balance = getbalance(root);
        
        if(balance > 1){
            //Unbalance in Left Side
            
            if(getbalance(root -> left) >=0) // LL
                return rightrotation(root);
            else{ //LR
                root -> left = leftrotation(root -> left);
                return rightrotation(root);
            }
        }
        else if(balance < -1){
            if(getbalance(root -> right) <=0){ // RR
                return leftrotation(root);
            }
            else{ //RL
                 root -> right = rightrotation(root -> right);
                return leftrotation(root);
            }
        }
        else{//balance = 0
            return root;
        }
        
        return root;
}
void inorder(Node* root){
    if(!root)
        return;
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);

    return;
}
int main(){
    Node* root = NULL;
    root = new Node(9);
    root -> left = new Node(5);
    root -> right = new Node(10);
    root -> left -> left = new Node(1);
    root -> left -> right = new Node(6);
    root -> right -> right = new Node(11);
    root -> left -> left -> left = new Node(0);
    root -> left -> left -> right = new Node(2);
    root -> left -> left -> right -> right = new Node(3);
    cout << "Inorder before deletion: ";
    inorder(root);
    root = deleteNode(root,10);
    cout << "\nInorder after deletion: ";
    inorder(root);
}