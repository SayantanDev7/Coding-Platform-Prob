#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    Node* ArrtoBST(vector<int> &arr,int start,int end){
        if(start > end)
            return NULL;
        int mid = start + (end - start)/2;
        Node* root = new Node(arr[mid]);
        root -> left = ArrtoBST(arr,start,mid - 1);
        root -> right = ArrtoBST(arr,mid+1,end);
        return root;
    }
    Node* sortedArrayToBST(vector<int>& arr) {
        // code here
        Node* root = ArrtoBST(arr,0,arr.size()-1);
        return root;
    }
};
int main(){
        vector<int> arr = {-10,-3,0,5,9};
        Solution sol;
        Node* root = sol.sortedArrayToBST(arr);
        cout<<root -> data; //printing root node data
        return 0;
}