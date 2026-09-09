#include<bits/stdc++.h>
using namespace std ;

// Calculating Power of a number (x^n) ->
double myPow(double x, int n) {
    long long power = n;

    // Handle negative power
    if (power < 0) {
        x = 1 / x;
        power = -power;
    }
    double ans = 1;

    while (power > 0) {
        // If power is odd
        if (power % 2 == 1) {
            ans = ans * x;
        }

        x = x * x;
        power = power / 2;
    }

    return ans;
}

// Converting string into 32 Bit integer ->
int myAtoi(string s){
    int i = 0 ;
    int n = s.length() ;
    while(i < n && s[i] == ' '){
        i++ ;
    }
    int sign = 1 ;
    if(i < n && (s[i] == '+' || s[i] == '-')){
        if(s[i] == '-') sign = -1 ;
        i ++ ;
    }
    long long nums = 0 ;
    while(i < n && isdigit(s[i])){
        int digit = s[i] - '0' ;
        if(nums > INT_MAX / 10 || (nums == INT_MAX / 10  && digit > (sign == 1 ? 7 : 8))){
            return sign == 1 ? INT_MAX : INT_MIN ;
        }
        nums = nums * 10 + digit ;
        i++ ;
    }
    return sign * nums ;
}

int main(){

    // Power of a number ->
    // double x ;
    // cout << "Enter the base : " ;
    // cin >> x ;
    // int n ;
    // cout << "Enter the power : " ;
    // cin >> n ;
    // int ans = myPow(x ,n) ;
    // cout << x << " raised to power " << n << " is " << ans ;
    
    // Converting string into 32 Bit integer -> 
    // string s ;
    // cout << "Enter the string to be converted : " ;
    // getline(cin , s) ;
    // int ans = myAtoi(s) ;
    // cout << ans ;

    return 0 ;
    
}