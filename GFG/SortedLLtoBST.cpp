#include <bits/stdc++.h>
using namespace std;

struct LNode { //Linked List
    int data;
    struct LNode* next;
    LNode(int x){
        data = x;
        next = NULL; }
};
struct TNode {   //Tree
    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x){
        data=x;
        left=right=NULL; }
}; 
class Solution {
  public:
    TNode *BuildBST(vector<int> &tree,int start,int end){
        if(start > end)
            return NULL;
        //end - start + 1 because in question they are taking the ceil values
        int mid = start + (end - start + 1)/2; // for tackling overflow
        TNode *root = new TNode(tree[mid]);
        root -> left = BuildBST(tree,start,mid - 1);
        root -> right = BuildBST(tree,mid+1,end);
        return root;
    }
    TNode *sortedListToBST(LNode *head) {
        // code here
        vector<int> tree;
        while(head){ //traversing linked list and storing values in vector tree
            tree.push_back(head -> data);
            head = head -> next;
        }
        return BuildBST(tree,0,tree.size() - 1); //building BST from sorted vector
    }
};
int main(){
    return 0;
}