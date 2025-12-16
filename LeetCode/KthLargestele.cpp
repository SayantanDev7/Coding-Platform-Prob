#include <bits/stdc++.h>
using namespace std;
#include <queue>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>p;

        for(int i=0;i<k;i++){
            p.push(nums[i]);
        }
        int n = nums.size();
        for(int i=k;i<n;i++){
            if(nums[i] > p.top()){
                p.pop();
                p.push(nums[i]);
            }
        }

        return p.top();
    }
};
int main(){
    Solution sol;
    vector<int> arr = {3,2,1,5,6,4};
    int k = 2;
    cout << "Kth largest element is: " << sol.findKthLargest(arr, k) << endl;
    return 0;
}