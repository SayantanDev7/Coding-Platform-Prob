/*
LeetCode Problem 2335: Minimum Amount of Time to Fill Cups

You have a water dispenser that can dispense cold, warm, and hot water. 
Every second, you can either fill up 2 cups with different types of water, or 1 cup of any type of water.

You are given a 0-indexed integer array amount of length 3 where amount[0], amount[1], and amount[2] denote the number of cold,
warm, and hot water cups you need to fill respectively. 
Return the minimum number of seconds needed to fill up all the cups.

*/

/*Approach: Use a max heap to always fill the two types of water with the most cups remaining.
where we push the amounts of each type of water into the max heap,then we repeatedly 
pop the top two elements (the two types of water with the most cups remaining),

TC is O(n log k) where n is the total number of cups to be filled and k is the number of types of water (which is 3 in this case).
SC is O(k) for the max heap to store the amounts of each type of water.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(int i=0;i<3;i++){
            if(amount[i]>0){
                pq.push(amount[i]);
            }
        }
        int seconds = 0;
        // While there are cups remaining to be filled
        while(!pq.empty()){
            if(pq.size() >= 2){ // If there are at least two types of water remaining
                int first = pq.top();
                pq.pop();
                int second = pq.top();
                pq.pop();
                first--;
                second--;
                if(first > 0){
                    pq.push(first);
                }
                if(second > 0){
                    pq.push(second);
                }
            }else{// If there is only one type of water remaining
                int first = pq.top();
                pq.pop();
                first--;
                if(first > 0){
                    pq.push(first);
                }
            }
            seconds++;
        }
        return seconds;
    }
};