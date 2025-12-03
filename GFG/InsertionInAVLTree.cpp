#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int val){
        height = 1; //Initially root node height is 1
        data = val;
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
    Node* child = root -> left;
    Node* childright = child -> right;

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
    Node* child = root -> right;
    Node* childleft = child -> left;

    child -> left = root;
    root -> right = childleft;
    //updating height and child after rotation
    root -> height = 1 + max(getheight(root -> left),getheight(root -> right));
    child -> height = 1 + max(getheight(child -> left),getheight(child -> right));

    //connecting new root to its parent
    return child;
}

Node* Insert(Node* root,int key){
    if(!root)
        return new Node(key);
    if(key < root -> data){
        root -> left = Insert(root -> left,key);
    }
    else if(key > root -> data){
        root -> right = Insert(root -> right,key);
    }
    else{
        //No duplicates allowed
        return root;
    }

    root -> height = 1 + max(getheight(root -> left),getheight(root -> right)); //updating height of the ancestor node
    int balance = getbalance(root); //getting balance factor of the ancestor node

    //balance = Left - Right + 1
    //LL
    if(balance > 1 && key < root -> left -> data)
        return rightrotation(root); //root -> left is the child here 
    //LR
    else if(balance > 1 && key > root -> left -> data){ //root -> left is the middle here node
        root -> left = leftrotation(root -> left);
        return rightrotation(root);
    }


    //RR
    else if(balance < -1 && key > root -> right -> data)
        return leftrotation(root);
    //RL
    else if(balance < -1 && key < root -> right -> data){
        root -> right = rightrotation(root -> right);
        return leftrotation(root);
    }

    //All balanced
    else{
        return root;
    }

}

void preorder(Node* root){
    if(!root)
        return;
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);

    return;
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
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,30);
    root = Insert(root,25);
    root = Insert(root,28);
    root = Insert(root,27);

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    return 0;
}