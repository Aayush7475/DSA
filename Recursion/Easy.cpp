#include<bits/stdc++.h>
using namespace std ;

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

int main(){

    // Power of a number ->
    double x ;
    cout << "Enter the base : " ;
    cin >> x ;

    int n ;
    cout << "Enter the power : " ;
    cin >> n ;

    int ans = myPow(x ,n) ;
    cout << x << " raised to power " << n << " is " << ans ;
    
}