/*
Given N bags, each bag contains Bi chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Bi chocolates, 
then the magician fills the ith bag with floor(Bi/2) chocolates.

Find the maximum number of chocolates that kid can eat in A units of time.

NOTE: 

floor() function returns the largest integer less than or equal to a given number.
Return your answer modulo 109+7

*/

#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int Solution(int A, vector<int> &B) {
    priority_queue<int> p;
    
    for(int i=0;i<B.size();i++){
        p.push(B[i]);
    }   
    /*
    If we are adding values in a loop and
    values can be up to 10⁹ or higher,
    use long long for the sum.
    */
    /*
    coz in worst cake B[i] i.e no of chocolates can be 10^9 and time can be 10^5 i.e 10^9 X 10^5 = 10^14 
    which is way more larger than INT_MAX
    */
    long long maxchoc = 0;
    while(A && (!p.empty())){
        maxchoc += p.top();
        if(p.top()/2){ //checking if after dividing by 2 the value becomes 0 or not
            p.push(p.top()/2);
        }
        /*pop the value because the original bag is consumed completely 
        nd must be replaced by a bag containing half the chocolates.*/
        p.pop();
        A--;
    }
    
    return maxchoc%1000000007; //because return type is int
}
int main(){
    int time = 3;
    vector<int> choc = {6,5,7,11};
    cout << "Maximum chocolates eaten: " << Solution(time, choc) << endl;
    return 0;
}