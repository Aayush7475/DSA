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

// Fruits into Basket (Method 2) ->
int totalFruits(vector<int>& nums){
    map<int , int> mpp ;
    int n = nums.size() ;
    int maxlen = 0 ;
    int r = 0 ;
    int l = 0 ;
    while(r < n){
        mpp[nums[r]] ++ ;

        if(nums[r] > 2){
            while(nums[r] > 2){
                mpp[nums[l]] -- ;
                if(mpp[nums[l]] == 0){
                    mpp.erase(nums[l] );
                    l ++ ;
                }
            }
        }
        if(mpp.size() <= 2){
            int len = r - l + 1 ;
            maxlen = max(maxlen , len) ;
        }
        r ++ ;
    }
    return maxlen ;
}

// Fruits into Basket (Method 3) ->
int Totalfruits(vector<int>& nums){
    int n = nums.size() ;
    map<int , int> mpp ;
    int maxlen = 0 ;
    int r = 0 ;
    int l = 0 ;
    while(r < n){
        mpp[nums[r]] ++ ;
        if(mpp.size() > 2){
            mpp[nums[l]] -- ;
            if(mpp[nums[l]] == 0){
                mpp.erase(mpp[nums[l]]) ;
                l ++ ;
            }
        }
        if(mpp.size() <= 2){
            int len = r - l + 1 ;
            maxlen = max(maxlen , len) ;
        }
        r ++ ;
    }
    return maxlen ;
}

// Longest Substring with atmost K distinct Characters ->
int longestSubstringAtMostKDistinct(string s , int k){
    int n = s.size() ;
    if(n == 0 || k <= 0){
        return 0 ;
    }
    unordered_map<char , int> freq ;
    int l = 0 ;
    int maxlen = 0 ;

    for(int r = 0 ; r < n ; r++){
        freq[s[r]] ++ ;

        while(freq.size() > k){
            freq[s[l]] -- ;
            if(freq[s[l]] == 0){
                freq.erase(s[l]) ;
            }
            l ++ ;
        }
        int len = r - l + 1 ;
        maxlen = max(maxlen , len) ;
    }
    return maxlen ;
}

// Longest repeating Characters replacement (Method 1) ->
int characterReplacement(string s, int k){
    int n = s.size() ;
    int maxlen = 0 ;
    for(int i = 0 ; i < n ; i++){
        int hash[26] = {0} ;
        int maxfreq = 0 ;
        for(int j = i ; j < n ; j++){
            hash[s[j] - 'A'] ++ ;
            maxfreq = max(maxfreq , hash[s[j] - 'A']) ;

            int changes = (j - i + 1) - maxfreq ;
            if(changes <= k) maxlen = max(maxlen , j - i + 1) ;
            else{
                break ;
            }
        }
    }
    return maxlen ;
}

// Longest repeating Characters replacement (Method 2) ->
int CharacterReplacement(string s , int k){
    int n = s.size() ;
    int maxlen = 0 ;
    int maxfreq = 0 ;
    int hash[26] = {0} ;
    int r = 0 ;
    int l = 0 ;
    while(r < n){
        hash[s[r] - 'A'] ++ ;
        maxfreq = max(maxfreq , hash[s[r] - 'A']) ;

        while((r-l+1) - maxfreq > k){
            hash[s[l] - 'A'] -- ;
            maxfreq = 0 ;
            
            for(int i = 0 ; i < 26 ; i++){
                maxfreq = max(maxfreq , hash[i]) ;
            }
            l ++ ;

        }
        if((r-l+1) - maxfreq <= k){
            maxlen = max(maxlen , (r-l+1)) ;
        }
        r ++ ;
    }
    return maxlen ;
}

// Minimum Window Substring (Method 1) ->
string minWindow(string s, string t){
    int m = s.size() ;
    int n = t.size() ;
    int minlen = INT_MAX ;
    int sIndex = -1 ;

    if(n == 0 || m < n) return "" ;

    for(int i = 0 ; i < m ; i++){
        int hash[256] = {0} ;
        int cnt = 0 ;
        for(int j = 0 ; j < n ; j++){
            hash[t[j]] ++ ;
        }
        for(int j = i ; j < m ; j++){
            if(hash[s[j]] > 0){
                cnt ++ ;
                hash[s[j]] -- ;
            }
            if(cnt == n){
                if((j-i+1) < minlen){
                    minlen = j-i+1 ;
                    sIndex = i ;
                }
                break ;
            }
        }
    }
    if(sIndex == -1) return "" ;
    return s.substr(sIndex , minlen) ;
}

// Minimum Window Substring (Method 2) ->
string MinWindow(string s , string t){
    int m = s.size() ;
    int n = t.size() ;
    int r = 0 ;
    int l = 0 ;
    int minlen = INT_MAX ;
    int sIndex = -1 ;
    int hash[256] = {0} ;
    int cnt = 0 ;

    if(n == 0 || m < n) return "" ; 

    for(int i = 0 ; i < n ; i++){
        hash[t[i]] ++ ;
    }
    while(r < m){
        if(hash[s[r]] > 0){
            cnt ++ ;
        }
        hash[s[r]] -- ;

        while(cnt == n){
            if((r-l+1) < minlen){
                minlen = r-l+1 ;
                sIndex = l ;
            }
            hash[s[l]] ++ ;
            if(hash[s[l]] > 0){
                cnt -- ;
            }
            l ++ ;
        }
        r ++ ;
    }
    return sIndex == -1 ? "" : s.substr(sIndex , minlen) ;
}

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

    // Fruits into Basket (M1 & M2 & M3) ->
    // int n ;
    // cout << "Enter the number of types of fruits : " ;
    // cin >> n ;
    // vector<int> nums(n) ;
    // cout << "Enter the type of fruits : " << endl ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> nums[i] ;
    // }
    // cout << "Max number of fruits that can be picked : " ;
    // cout << totalfruits(nums) ;
    // cout << totalFruits(nums) ;
    // cout << Totalfruits(nums) ;

    // Longest Substring with atmost K distinct Characters ->
    // string s ;
    // cout << "Enter the string : " ;
    // getline(cin , s) ;
    // int k ;
    // cout << "Enter the number of distinct elements to be taken : " ;
    // cin >> k ;
    // cout << "Longest Substring with Atmost " << k << "distinct characters  " ;
    // cout << longestSubstringAtMostKDistinct(s , k) ;

    // Longest repeating Characters replacement ->
    // string s ;
    // cout << "Enter the string : " ;
    // getline(cin , s) ;
    // int k ;
    // cout << "Enter the number of characters that can be replaced : " ;
    // cin >> k ;
    // cout << "Longest Repeating Character Sequence is : " << characterReplacement(s , k) ;
    // cout << "Longest Repeating Character Sequence is : " << CharacterReplacement(s , k) ;

    // Minimum Window Substring (M1 & M2) ->
    // string s ;
    // cout << "Enter the main string : " ;
    // getline(cin , s) ;
    // string t ;
    // cout <<"Enter the small one string : " ;
    // getline(cin , t) ;
    // cout << "Substring with minimum length containing all the characters of t in s is : " ;
    // cout << minWindow(s , t) ;
    // cout << MinWindow(s , t) ;

    // Number of substrings containing all three characters (M1 & M2) ->
    // string s ;
    // cout << "Enter the string (containing only a,b,c) : " ;
    // getline(cin , s) ;
    // cout << "Number of SubStrings containing all three characters : " ;
    // cout << numberOfSubstrings(s) ;
    // cout << NumberOfSubstrings(s) ;

    return 0 ;
}