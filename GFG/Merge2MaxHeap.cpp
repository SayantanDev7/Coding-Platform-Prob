//TC is O(n+m) for merging + O(nlog(n+m)) for heapifying = O(nlog(n+m))
//SC is O(n+m) for merged array

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void Heapify(vector<int> &arr,int ind){
        int largest = ind;
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        int n = arr.size();
        if(left < n && arr[left] > arr[largest]){
            largest = left;
        }
        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }
        
        if(largest != ind){
            swap(arr[largest],arr[ind]);
            Heapify(arr,largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> arr;
        for(int i=0;i<n;i++){
            arr.push_back(a[i]);
        }
        for(int i=0;i<m;i++){
            arr.push_back(b[i]);
        }
        int size = arr.size();
        for(int i=size/2-1;i>=0;i--){
            Heapify(arr,i);
        }
        return arr;
    }
};
int main() {
    Solution sol;
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    int n = a.size();
    int m = b.size();
    vector<int> mergedHeap = sol.mergeHeaps(a, b, n, m);
    
    cout << "Merged Heap: ";
    for(int val : mergedHeap) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}