#include <bits/stdc++.h>
using namespace std;

int Solution(vector<int> &A, int B) {
    priority_queue<int> p;
    for(int i=0;i<A.size();i++){
        p.push(A[i]);
    }
    
    int sum = 0;
    
    while(B && (!p.empty())){
        sum += p.top();
        
        if(p.top() - 1){
            p.push(p.top()-1);
        }
        p.pop();
        B--;
    }
    
    return sum;
    
}
int main(){
    vector<int> profits = {20,15,10,5,30};
    int time = 3;
    cout << "Maximum profit: " << Solution(profits, time) << endl;
    return 0;
}