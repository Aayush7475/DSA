#include<bits/stdc++.h>
using namespace std ;

// Maximum points that can be obtained from cards ->
int maxPoints(vector<int>& nums , int k){
    int lSum = 0 ;
    int rSum = 0 ;
    int maxSum = 0 ;

    for(int i = 0 ; i < k ; i++){
        lSum = lSum + nums[i] ;
    }
    maxSum = lSum ;

    int R_index = nums.size() - 1 ;
    for(int i = k-1 ; i >= 0 ; i--){
        lSum = lSum - nums[i] ;
        rSum = rSum + nums[R_index] ;
        R_index -- ;
        maxSum = max(maxSum , lSum + rSum) ;
    }
    return maxSum ;
}

int main(){

    // Maximum points that can be obtained from cards ->
    // int n ;
    // cout << "Enter the number of Card Points : " ;
    // cin >> n ;
    // vector<int> nums(n) ;
    // cout << "Enter the Card Points : " << endl ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> nums[i] ;
    // }
    // int k ;
    // cout << "Enter the number of elements to be used : " ;
    // cin >> k ;
    // cout << "Maximum Card Points that can be obtained is : " ;
    // cout << maxPoints(nums , k) ;

    return 0 ;
}