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


int main(){

    // Number of substrings containing all three characters (M1 & M2) ->
    // string s ;
    // cout << "Enter the string (containing only a,b,c) : " ;
    // getline(cin , s) ;
    // cout << "Number of SubStrings containing all three characters : " ;
    // cout << numberOfSubstrings(s) ;
    // cout << NumberOfSubstrings(s) ;

    
    return 0 ;
}