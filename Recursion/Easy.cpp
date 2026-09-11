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

// Contains Duplicate (Return true if any value appears atleast twice) ->
bool containsDuplicate(vector<int> &nums){
    unordered_set<int> s ;
    for(int x : nums){
        if(s.find(x) != s.end()) return true ;
        s.insert(x) ;
    }
    return false ;
}

// Generate all combinations of parenthesis ->
void generate(string s , int open , int close , int n , vector<string> &ans){
    if(open == n && close == n){
        ans.push_back(s) ;
        return ;
    }
    if(open < n){
        generate(s + "(" , open + 1 , close , n , ans) ;
    }
    if(close < open){
        generate(s + ")" , open , close + 1 , n , ans) ;
    }
}
vector<string> generateParenthesis(int n){
    vector<string> ans ;
    generate("" , 0 , 0 , n , ans);
    return ans ;
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

    // Contains Duplicate ->
    // int n ;
    // cout << "Enter the number of elements in the array : " ;
    // cin >> n ;
    // vector<int> nums(n) ;
    // cout << "Enter the elements in the array : " << endl ;
    // for(int i = 0 ; i< n ; i++){
    //     cin >> nums[i] ;
    // }
    // if(containsDuplicate(nums) == true){
    //     cout << "Contains duplicate element" ;
    // }
    // else{
    //     cout << "Doesn't contains duplicate element " ;
    // }

    //  Generate all combinations of parenthesis ->
    // int n ;
    // cout << "Enter the number of parenthesis : " ;
    // cin >> n ;
    // vector<string> ans = generateParenthesis(n);
    // cout << "All valid combinations are:" << endl;
    // for (string s : ans) {
    //     cout << s << endl;
    // }


    return 0 ;
    
}