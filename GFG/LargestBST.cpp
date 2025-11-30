#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

//creating a box class to store info about each subtree
class Box{
    public:
    bool BST;
    int size;
    int min,max;
    Box(int data){
        BST = 1;
        size = 1;
        min = data;
        max = data;
    }
    Box(bool bst,int sz,int mx,int mn){
        BST = bst;
        size = sz;
        min = mn;
        max = mx;
    }
    
};

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    Box* Find(Node* root,int &totalsize){
       //Leaf Node
       if(!root -> left && !root -> right){
           totalsize = max(totalsize, 1);
           return new Box(root -> data);
       }
       //Only right side exist
       else if(!root -> left && root -> right){
           Box* head = Find(root -> right,totalsize);
           if(head -> BST && head -> min > root -> data){ //checking BST property that all right subtree nodes are greater than root node
               head -> size++;//increasing size of BST
               head -> min = root -> data;//updating min value so that parent nodes can use it
               totalsize = max(totalsize,head -> size); //  updating total size of largest BST
               return head;
           }
           else{//if not a BST we return false box
               return new Box(false,head ->size+1,min(root -> data,head -> min),max(root -> data,head -> max));
           }
       }
       //Only left side exist
       else if(root -> left && !root -> right){
           Box* head = Find(root -> left,totalsize);
           if(head -> BST && head -> max < root -> data){ //checking BST property that all left subtree nodes are smaller than root node
               head -> size++;//increasing size of BST
               head -> max = root -> data; //updating max value so that parent nodes can use it
               totalsize = max(totalsize,head -> size); //  updating total size of largest BST
               return head;
           }
           else{//if not a BST we return false box
               return new Box(false,head ->size+1,min(root -> data,head -> min),max(root -> data,head -> max));
           }
       }
       //Both Side exist
       else{
           Box *lefthead = Find(root -> left,totalsize);
           Box *righthead = Find(root -> right,totalsize);
           
           if(lefthead -> BST && righthead -> BST && lefthead -> max < root -> data && righthead -> min > root -> data){
               Box *head = new Box(root -> data);
               head -> size += lefthead -> size + righthead -> size; // we dont add 1 because we already initialized size as 1 in constructor
               head -> min = lefthead -> min;//updating min value so that parent nodes can use it
               head -> max = righthead -> max;//updating max value so that parent nodes can use it
               totalsize = max(totalsize,head -> size); //  updating total size of largest BST
               return head;
           }
           else{ //if not a BST we return false box
              return new Box(false,1+lefthead -> size + righthead -> size,min(lefthead -> min,min(righthead -> min,root -> data)),max(lefthead -> max,max(righthead -> max,root -> data)));
           }
       }
       
    }
    int largestBst(Node *root) {
        // Your code here
        int totalsize = 0; //to store the size of largest BST
        Find(root,totalsize); //function call to find the largest BST
        return totalsize;
    }
};