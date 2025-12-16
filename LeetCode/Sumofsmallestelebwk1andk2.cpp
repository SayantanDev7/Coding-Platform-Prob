#include <bits/stdc++.h>
using namespace std;
#include <queue>
class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long k1, long long k2) {
        // Your code goes here
        priority_queue<long long>p1;
        
        priority_queue<long long>p2;
        
        for(long long i=0;i<k1;i++){
            p1.push(A[i]);
        }
        
        for(long long i=0;i<k2;i++){
            p2.push(A[i]);
        }
        
        long long sum1=0;
        long long sum2 = 0;
        //calculating sum for K1
        for(long long i=k1;i<N;i++){
            if(A[i] < p1.top()){
                p1.pop();
                p1.push(A[i]);
            }
        }
        
        for(long long i=k2;i<N;i++){
            if(A[i] < p2.top()){
                p2.pop();
                p2.push(A[i]);
            }
        }
        while(!p1.empty()){
            sum1 += p1.top();
            p1.pop();
        }
        
        long long k2th = p2.top();
         while(!p2.empty()){
            sum2 += p2.top();
            p2.pop();
        }
        /*Order statistics depend on values, not indices.
        we can only exclude k2 after the heap finishes, not while building it.*/
        return sum2-sum1 -k2th;
        
    }
};
int main(){
    Solution sol;
    long long arr[] = {20, 8, 22, 4, 12, 10, 14};
    long long n = sizeof(arr)/sizeof(arr[0]);
    long long k1 = 3, k2 = 6;
    cout << "Sum of elements between k1 and k2 smallest: " << sol.sumBetweenTwoKth(arr, n, k1, k2) << endl;
    return 0;
}