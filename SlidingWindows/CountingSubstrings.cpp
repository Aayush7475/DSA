#include<bits/stdc++.h>
using namespace std ;

// Number of substrings containing all three characters (Method 1) ->
int numberOfSubstrings(string s){
    int n = s.size() ;
    int cnt = 0 ;
    for(int i = 0 ; i < n ; i++){
        int hash[3] = {0} ;
        for(int j = i ; j < n ; j++){
            hash[s[j] - 'a'] = 1 ;
            if(hash[0] + hash[1] + hash[2] == 3){
                cnt += (n - j) ;
                break ;
            }  
        }
    }
    return cnt ;
}

// Number of substrings containing all three characters (Method 2) ->
int NumberOfSubstrings(string s){
    int n = s.size() ;
    int lastSeen[3] = {-1 , -1 , -1} ;
    int cnt = 0 ;
    for(int i = 0 ; i < n ; i++){
        lastSeen[s[i] - 'a'] = i ;
        if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
            cnt += (1 + min({lastSeen[0] , lastSeen[1] , lastSeen[2]})) ;
        }
    }
    return cnt ;
}

// Binary SubArrays with given Sum ->
int atMost(vector<int>& nums , int goal){
    int n = nums.size() ;
    int cnt = 0 ;
    int sum = 0 ;
    int l = 0 ;
    for(int r = 0 ; r < n ; r++){
        sum += nums[r] ;

        while(sum > goal){
            sum -= nums[l] ;
            l ++ ;
        }
        cnt += (r - l + 1) ;
    }
    return cnt ;
}
int numSubarraysWithSum(vector<int>& nums, int goal){
    return atMost(nums , goal) - atMost(nums , goal - 1) ;
}

// Count Number of good Subarrays ->
int AtMost(vector<int>& nums , int k){
    int n = nums.size() ;
    int cnt = 0 ;
    int sum = 0 ;
    int l = 0 ;
    for(int r = 0 ; r < n ; r++){
        sum += nums[r] % 2 ;

        while(sum > k){
            sum -= nums[l] % 2 ;
            l ++ ;
        }
        cnt += (r - l + 1) ;
    }
    return cnt ;
}
int numberOfSubArrays(vector<int>& nums , int k){
    return AtMost(nums , k) - AtMost(nums , k - 1) ;
}

int main(){

    // Number of substrings containing all three characters (M1 & M2) ->
    // string s ;
    // cout << "Enter the string (containing only a,b,c) : " ;
    // getline(cin , s) ;
    // cout << "Number of SubStrings containing all three characters : " ;
    // cout << numberOfSubstrings(s) ;
    // cout << NumberOfSubstrings(s) ;

    // Number Of subArrays with given Sum  ->
    // int n ; 
    // cout << "Enter the number of elements in the Binary Array : " ;
    // cin >> n ;
    // vector<int> nums(n) ;
    // cout << "Enter the elements in the Binary Array : " << endl ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> nums[i] ;
    // }
    // int goal ;
    // cout << "Enter the goal : " ;
    // cin >> goal ;
    // cout << "Number of Binary SubArrays with Given Sum : " ;
    // cout << numSubarraysWithSum(nums , goal) ;

    // Count Number of good Subarrays ->
    // int n ;
    // cout << "Enter the number of elements in the Array : " ;
    // cin >> n ;
    // vector<int> nums(n) ;
    // cout << "Enter the elements in the array : " << endl ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> nums[i] ;
    // }
    // int k ;
    // cout << "Enter the sum to be required : " ;
    // cin >> k ;
    // cout << "Number of Good Sub Arrays : " ;
    // cout << numberOfSubArrays(nums , k) ;

    return 0 ;
}