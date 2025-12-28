/*
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].


*/


/*
TC is O(N log k) where N is total number of elements in all arrays and k is number of arrays
log k because we are using a min heap of size k

SC is O(k) for the min heap
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p;

        int min;
        int maximum = INT_MIN;

        int n = nums.size();
        // Pushing first element of each array into the min heap
        for(int i=0;i<n;i++){
            p.push(make_pair(nums[i][0],make_pair(i,0)));
            maximum  = max(maximum ,nums[i][0]);
        }
        min = p.top().first;
        //Since range consist of 2 elements we will use a vector of size 2 to store the answer
        vector<int> ans(2);
        ans[0] = min;
        ans[1] = maximum ;

        pair<int,pair<int,int>> temp;
        int ele,row,col;

        while(p.size() == nums.size()){ //Initial size of priority queue should not decrease
            temp = p.top();
            p.pop();
            //Extracting the details of the element
            int ele = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;

            //If there is a next element in the same array, push it into the min heap
            if(col+1 < nums[row].size()){
                col++; //move to next column
                //Pushing the next element of the same array into the min heap
                p.push(make_pair(nums[row][col],make_pair(row,col)));
                maximum = max(maximum,nums[row][col]);
                min = p.top().first;

                //IF we got a smaller range than previous one
                if(maximum - min < ans[1] - ans[0]){
                    ans[0] = min;
                    ans[1] = maximum;
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> nums = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    vector<int> range = sol.smallestRange(nums);
    cout << "Smallest Range: [" << range[0] << ", " << range[1] << "]" << endl;
    return 0;
}