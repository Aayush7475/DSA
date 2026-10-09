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




int main(){
    
    // Binary Addition ->
    // string a ; 
    // string b ;
    // cout << "Enter the first binary numbers : " ;
    // getline(cin , a) ;
    // cout << "Enter the second binary number : " ;
    // getline(cin , b) ;
    // cout << addBinary(a , b) ;

    
    return 0 ;
}