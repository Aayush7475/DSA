#include<bits/stdc++.h>
using namespace std ;

// Assigning Cookies ->
int findContentChildren(vector<int>& g , vector<int>& s){
    int n = g.size() ;
    int m = s.size() ;
    int l = 0 ;
    int r = 0 ;
    sort(g.begin() , g.end()) ;
    sort(s.begin() , s.end()) ;
    while(l < m && r < n){
        if(g[r] <= s[l]){
            r++ ;
        }
        l++ ;
    }
    return r ;
}

int main(){

    // Assigning Cookies ->
    // int n1 ;
    // cout << "Enter the Greed factor : " ;
    // cin >> n1 ;
    // vector<int> g(n1) ;
    // cout << "Enter the Greed factors : " << endl ;
    // for(int i = 0 ; i < n1 ; i++){
    //     cin >> g[i] ;
    // }
    // cout << endl ;
    // int n2 ;
    // cout << "Enter the Number of Cookies : " ;
    // cin >> n2 ;
    // vector<int> s(n2) ;
    // cout << "Enter the Cookies : " << endl ;
    // for(int i = 0 ; i < n2 ; i++){
    //     cin >> s[i] ;
    // }
    // cout << "Number of Childrens Satisfied : " ;
    // cout << findContentChildren(g , s) ;

    return 0 ;

}