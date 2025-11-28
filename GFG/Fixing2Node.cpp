// Usinng Morris Traversal
// Tc - O(N) , Sc - O(1)
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    void correctBST(Node* root) {
        Node *first = NULL,*second = NULL;
        Node *present = NULL;
        Node *last = NULL;
        Node *curr = NULL;
        
        while(root){
            if(!root -> left){
                //visit curr
                last = present;
                present = root;
                if(last && last -> data > present -> data){
                    if(!first) // checking if we are at first violation as if it will be second violation then first will not be null
                        first = last;
                    second = present; 
                }
                root = root -> right; // move to right child
            }
            else{ // left child exists
                curr = root -> left;
                while(curr -> right && curr -> right != NULL){
                    curr = curr -> right;
                }
                if(!curr -> right){
                    curr -> right = root;
                    root = root -> left;
                }
                else{ //connection already built as right child is not null
                    curr -> right = NULL;
                    //visit curr
                    //checking this condition only when going to right because in inorder traversal we visit left first then root and then right
                    last = present;
                    present = root;
                    if(last && last -> data > present -> data){
                    if(!first) // checking if we are at first violation as if it will be second violation then first will not be null
                        first = last;
                    second = present; 
                }
                root = root -> right; // move to right child

                }   
            }
        }
        //swapping the data of first and second
        int num = first -> data;
        first -> data = second -> data;
        second -> data = num;
    }
};
int main(){
    return 0;
}