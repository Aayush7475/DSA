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

// Longest SubString wihtout repeating charcaters (Method 1) ->
int lengthOfLongestSubstring(string s){
    int n = s.length() ;
    int maxlen = 0 ;

    for(int i = 0 ; i < n ; i++){
        int hash[256] = {0} ;
        for(int j = i ; j < n ; j++){
            if(hash[s[j]] == 1) break;
            else{
                int len = j - i + 1 ;
                maxlen = max(maxlen , len) ;
                hash[s[j]] = 1 ;
            }
        }
    }
    return maxlen ;
}

// Longest SubString wihtout repeating charcaters (Method 2) ->
int lengthOflongestSubString(string s){
    int hash[256] = {-1} ;
    int n = s.length() ;
    int r = 0 ;
    int l = 0 ;
    int maxLen = 0 ;
    
    while(r < n){
        if(hash[s[r]] != -1){
            if(hash[s[r]] >= l){
                l = hash[s[r]] + 1 ;
            }
        }
        int len = r - l + 1 ;
        maxLen = max(maxLen , len) ;
        hash[s[r]] = r ;
        r ++ ;
    }
    return maxLen ;
}

// Max Consecutive Ones III (Method 1) ->
int longestOnes(vector<int> nums , int k){
    int n = nums.size() ;
    int maxlen = 0 ;
    for(int i = 0 ; i < n ; i++){
        int zeroes = 0 ;
        for(int j = i ; j < n ; j++){
            if(nums[j] == 0) zeroes ++ ;
            if(zeroes <= k){
                int len = j - i + 1 ;
                maxlen = max(maxlen , len) ;
            }
            else{
                break ;
            }
        }
    }
    return maxlen ;
}

// Max Consecutive Ones III (Method 2) ->
int longestOnes2(vector<int> nums , int k){
    int n = nums.size() ;
    int maxlen = 0 ;
    int zeroes = 0 ;
    int r = 0 ;
    int l = 0 ;

    while(r < n){
        if(nums[r] == 0) zeroes ++ ;

        while(zeroes > k){
            if(nums[l] == 0) zeroes -- ;
            l ++ ;
        }
        if(zeroes <= k){
            int len = r - l + 1 ;
            maxlen = max(maxlen , len) ;
        }
        r ++ ;
    }
    return maxlen ;
}

// Max Consecutive Ones III (Method 3) ->
int longestOnes3(vector<int> nums , int k){
    int n = nums.size() ;
    int maxlen = 0 ;
    int zeroes = 0 ;
    int r = 0 ;
    int l = 0 ;
    while(r < n){
        if(nums[r] == 0) zeroes ++ ;
        if(zeroes > k){
            if(nums[l] == 0){
                zeroes -- ;
            }
            l ++ ;
        }
        if(zeroes <= k){
            int len = r - l + 1 ;
            maxlen = max(maxlen , len) ;
        }
        r ++ ;
    }
    return maxlen ;
}

// Fruits into Basket (Method 1) ->
int totalfruits(vector<int>& nums){
    int n = nums.size() ;
    int maxlen = 0 ;
    for(int i = 0 ; i < n ; i++){
        set<int> s ;
        for(int j = i ; j < n ; j++){
            s.insert(nums[j]) ;
            if(s.size() <= 2){
                int len = j - i + 1 ;
                maxlen = max(maxlen , len) ;
            }
            else{
                break ;
            }
        }
    }
    return maxlen ;
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

    // Longest SubString wihtout repeating charcaters (M1 & M2) ->
    // string s ;
    // cout << "Enter the string : " ;
    // getline(cin , s) ;
    // cout << "Length of Longest Substring without Repeating Characters : " ;
    // cout << lengthOfLongestSubstring(s) ;
    // cout << lengthOflongestSubString(s) ;

    // Max consecutive Ones III (M1 & M2 & M3) ->
    // int n ;
    // cout << "Enter the number of elements : " ;
    // cin >> n ;
    // vector<int> nums(n) ;
    // cout << "Enter the elements in the array : " ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> nums[i] ;
    // }
    // int k ;
    // cout << "Enter the number of 0's that can be converted into 1 : " ;
    // cin >> k ;
    // cout << "Max Consecutive Ones after flipping " << k << " zeroes is : ";
    // cout << longestOnes(nums , k) ;
    // cout << longestOnes2(nums , k) ;
    // cout << longestOnes3(nums , k) ;

    // Fruits into Basket (M1) ->
    int n ;
    cout << "Enter the number of types of fruits : " ;
    cin >> n ;
    vector<int> nums(n) ;
    cout << "Enter the type of fruits : " << endl ;
    for(int i = 0 ; i < n ; i++){
        cin >> nums[i] ;
    }
    cout << "Max number of fruits that can be picked : " ;
    cout << totalfruits(nums) ;

    return 0 ;
}