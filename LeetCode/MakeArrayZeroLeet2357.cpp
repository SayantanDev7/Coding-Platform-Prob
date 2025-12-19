//Title: Make Array 0 by Subtracting Equal Amounts
/*
TC is O(nlong) because O(nlong) for building min heap and O(nlogn) for popping all elements from heap
1st while loop runs till heap is empty and remove one element and inner while loop pops all occurrences of curr element
inner while loop do not contribute in tc as each element is popped only once

Sc is O(n) for building min heap as heap can contains all elements in worst case
*/

/*
Apporach is my approach is i will use min heap using priority_queue stl method of cpp and 
keep on removing smallest element from heap and for each unique smallest element i will increase operation count by 1
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> p;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > 0)
                p.push(nums[i]);
        }
        int opn = 0;//to count the numbers of operations
        int prev = 0; //how much we have already subtracted in previous operations
        //let the smallest ele be curr

        while(!p.empty()){
            int curr = p.top();
            if(curr - prev > 0){
                opn += 1;
                prev = curr;
            }

            while(!p.empty() && p.top() == curr)
                p.pop();
        }
        return opn;
    }
};
int main(){
    return 0;
}