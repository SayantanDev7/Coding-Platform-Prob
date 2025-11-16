#include <climits> // For INT_MAX and INT_MIN
#include <iostream> // For input-output operations
using namespace std; // Namespace declaration  
class Solution {
public:
    int reverse(int num) {
        int rev = 0;

        while (num != 0) {
            int dig = num % 10; // Extract the last digit.

            // Checking for positive overflow:
            
            if (rev > INT_MAX / 10  // If rev > INT_MAX/10, multiplying by 10 will overflow.
               || (rev == INT_MAX / 10 && dig > 7)) // If rev == INT_MAX/10, then only digits 0–7 are safe.
                return 0;

            // Checking for negative overflow:
            
            if (rev < INT_MIN / 10  // If rev < INT_MIN/10, multiplying by 10 will overflow.
                || (rev == INT_MIN / 10 && dig < -8))// If rev == INT_MIN/10, then only digits 0 to -8 are safe.
                return 0;

            rev = rev * 10 + dig; //After passing overflow checks, safe to multiply and add.
            num /= 10; // Remove the last digit from num.
        }

        return rev; // Return the reversed integer.
    }
};

int main(){
    Solution sol;
    int num;
    cout << "Enter an integer to reverse: ";
    cin >> num;

    int reversedNumber = sol.reverse(num); //creating object of class Solution and calling reverse method
    if(reversedNumber == 0)
        cout << "Reversal results in overflow. Returning 0." << endl;
    else
        cout << "Reversed Number: " << reversedNumber << endl;


    return 0;
}
