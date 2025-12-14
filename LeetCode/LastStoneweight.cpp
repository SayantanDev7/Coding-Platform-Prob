#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;
        for(int i=0;i<stones.size();i++){
            p.push(stones[i]);
        }

        while(p.size() != 1){
            int first = p.top();
            p.pop();
            int second = p.top();
            p.pop();
            p.push(first-second);
        }

        return p.top();

    }
};

int main(){
    Solution obj;
    vector<int> stones = {2,7,4,1,8,1};
    cout << "Last stone weight: " << obj.lastStoneWeight(stones) << endl;
    return 0;
}