#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
Node* insertBST(Node* root,int target){
    if(!root){
        Node* temp = new Node(target);
        return temp;
    }
    if(target < root -> data)
        root -> left = insertBST(root -> left,target);
    else
        root -> right = insertBST(root -> right,target);
    return root;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root -> left);
    cout<<root -> data<<" ";
    inorder(root -> right);
}

int search(Node* root,int target){
    if(!root)
        return 0;
    if(root -> data == target)
        return 1;
    if(root -> data > target){ //i.e target is less than current node so go left
        search(root -> left,target);
    }
    else
        search(root -> right,target);
    
}
int main(){
    vector<int> arr = {7,9,10,5,34,67,20,15,0};
    Node* root = NULL;

    for(int i=0;i<arr.size();i++){
        root = insertBST(root,arr[i]);
    }

    //Traversal in inorder
    inorder(root);

    if(search(root, 15))
        cout<<"\nElement found\n";
    else
        cout<<"\nElement not found\n";
    return 0;

}