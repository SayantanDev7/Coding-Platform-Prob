#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        //pair<int,pair<int,int>>;
        vector<pair<int,pair<int,int>>> temp;
        int n = mat.size();
        for(int i=0;i<mat.size();i++){
            temp.push_back(make_pair(mat[i][0],make_pair(i,0)));
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p;
        for(auto &x : temp){
            p.push(x);
        }
        int ans;
        int i,j;
        while(k--){
            auto ele = p.top();
            p.pop();
            ans = ele.first;
            i = ele.second.first;
            j = ele.second.second;
            if(j+1<mat[i].size())
                p.push(make_pair(mat[i][j+1],make_pair(i,j+1)));
        }
        return ans;
    }
};
//TC is O(klogn) where n is number of rows and k is the kth smallest element to be found
//SC is O(n) for priority queue