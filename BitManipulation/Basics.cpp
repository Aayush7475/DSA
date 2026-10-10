#include<bits/stdc++.h>
using namespace std ;

// Addition of two binary numbers ->
string addBinary(string a , string b){
    int i = a.size() - 1 ;
    int j = b.size() - 1 ;
    int carry = 0 ;
    string ans = "" ;

    while(i >= 0 || j >= 0 || carry){
        int sum = carry ;

        if(i >= 0){
            sum += (a[i] - '0') ;
            i-- ;
        }
        if(j >= 0){
            sum += (b[j] - '0') ;
            j-- ;
        }

        ans += (sum % 2) + '0' ;
        carry = sum / 2 ; 
    }
    reverse(ans.begin() , ans.end()) ;
    return ans ;
}

// Finding non duplicate element ->
int nonDuplicate(vector<int>& nums){
    int ans = 0 ;
    for(auto x : nums){
        ans ^= x ;
    }
    return ans ;
}

// Number is power of two ->
bool isPowerOfTwo(int n){
    if(n <= 0) return false ;
    if((n & (n-1)) == 0) return true ;
    return false ;
}

int main(){
    
    // Binary Addition ->
    // string a ; 
    // string b ;
    // cout << "Enter the first binary numbers : " ;
    // getline(cin , a) ;
    // cout << "Enter the second binary number : " ;
    // getline(cin , b) ;
    // cout << addBinary(a , b) ;

    // Single Element ->
    // int n ; 
    // cout << "Enter the number of elements in the array : " ;
    // cin >> n ;
    // vector<int> nums(n) ;
    // cout << "Enter the elements in the array : " << endl ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> nums[i] ;
    // }
    // cout << "Non Duplicate element in the given array is : " ;
    // cout << nonDuplicate(nums) ;

    // Power of two ->
    // int n ;
    // cout << "Enter the number to be checked : " ;
    // cin >> n ;
    // int result = isPowerOfTwo(n) ;
    // if(result){
    //     cout << "Number is power of 2 " ;
    // }
    // else{
    //     cout << "Number is not a power of 2 " ;
    // }

    return 0 ;
}