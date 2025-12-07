#include <bits/stdc++.h>
#include <climits>

using namespace std;


class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        // code here
        stack<int> lower,upper;
        //Initially
        lower.push(INT_MIN);
        upper.push(INT_MAX);
        int left,right;
        
        for(int i=0;i<N;i++){
            if(arr[i]<lower.top())
                return 0;
            while(arr[i] > upper.top()){
                lower.pop();
                upper.pop();
            }
            
            left = lower.top();
            right = upper.top();
            lower.pop();
            upper.pop();
            
            lower.push(arr[i]);
            upper.push(right);
            
            lower.push(left);
            upper.push(arr[i]);
        }
        return 1;
    }
};

int main(){
    int arr[] = {40,30,35,80,100};
    int N = sizeof(arr)/sizeof(arr[0]);
    Solution obj;
    cout<<obj.canRepresentBST(arr,N);
    return 0;
}