//TC - O(nlog k)
/*
According to this apporach we create group of size k using max heap.
Then we traverse the array from k to n and whenever we find an element smaller than the largest element of the group
we remove the largest element of that group and insert the current element.
    then at last the largest element of that group will be our answer.

    Max Heap is used because we want to remove the largest element of that group whenever we find an element smaller than that.
*/
#include <bits/stdc++.h>
using namespace std;
#include <queue>
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> p; //creating the max heap using STL
        int n = arr.size();
        //creating the group of size k
        for(int i=0;i<k;i++){
            p.push(arr[i]);
        }
        
        for(int i=k;i<n;i++){
            if(arr[i] < p.top()){
                p.pop();//at first remove the largest ele of that group
                p.push(arr[i]);
            }
        }
        
        return p.top(); //retunrning the largest ele of our current group
    }
};

int main(){
    Solution sol;
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "Kth smallest element is: " << sol.kthSmallest(arr, k) << endl;
    return 0;
}