//Leetcode 506
//Title - Relative Rank

/*Approach - We can use a max heap to store the scores along with their original indices. 
By repeatedly extracting the maximum score from the heap, we can assign ranks based on the order of extraction. 
The top three scores will receive special titles ("Gold Medal", "Silver Medal", "Bronze Medal"), while the rest will receive their respective ranks as strings.
*/

/*
TC is O(nlogn) because we are pushing n elements into the heap which takes O(logn) time each and then we are popping n elements 
from the heap which again takes O(logn) time each
SC is O(n) for storing the heap and the answer array
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> p;
        int n = score.size();
        vector<string> ans(n);
        //pushing score along with their original indices
        for(int i=0;i<n;i++){
            p.push({score[i],i});
        }

        int rank = 1;
        while(!p.empty()){
            //using auto because p.top() returns a pair<int,int> and to avoid writing lengthy code
            auto top = p.top();
            p.pop();

            int ind = top.second; //fetching the original index of the score
            if(rank == 1)
                ans[ind] = "Gold Medal";
            else if(rank == 2)
                ans[ind] = "Silver Medal";
            else if(rank == 3)
                ans[ind] = "Bronze Medal";
            else{
                //to_string function converts int to string
                ans[ind] = to_string(rank); //inserting the rank after converting it to string
            }
            rank++;
        }

        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> scores = {10,3,8,9,4};
    vector<string> ranks = sol.findRelativeRanks(scores);
    cout << "Relative Ranks: ";
    for(const string& rank : ranks){
        cout << rank << " ";
    }
    cout << endl;
    return 0;
}