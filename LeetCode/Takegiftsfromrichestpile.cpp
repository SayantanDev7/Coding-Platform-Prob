#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> p;
        for(int i=0;i<gifts.size();i++){
            p.push(gifts[i]);
        }
        long long maxgifts = 0;
        
        while(k && (!p.empty())){
            long long x = p.top();
            p.pop();
            
            p.push((long long)sqrt(x));
            k--;
        }

        while(!p.empty()){
            maxgifts += p.top();
            p.pop();
        }
        
        return maxgifts;

    }
};
int main(){
    Solution obj;
    vector<int> gifts = {25,64,9,4,100};
    int k = 4;
    cout << "Maximum gifts remaining: " << obj.pickGifts(gifts, k) << endl;
    return 0;
}