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

// Lemonade Change ->
bool lemonade(vector<int>& bills){
    int five = 0 ;
    int ten = 0 ;
    for(int i = 0 ; i < bills.size() ; i++){
        if(bills[i] == 5){
            five ++ ;
        }
        else if(bills[i] == 10){
            if(five){
                ten ++ ;
                five -- ;
            }
            else{
                return false ;
            }
        }
        else{
            if(ten > 0 && five > 0){
                ten -- ;
                five ++ ;
            }
            else if(five >= 3){
                five -= 3 ;
            }
            else{
                return false ;
            }
        }
    }
    return false ;
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

    // Lemonade Change ->
    // int n ;
    // cout << "Enter the number of persons buying lemon : " ;
    // cin >> n ;
    // vector<int> bills(n) ;
    // cout << "Enter the Money given by the Buyers : " << endl ;
    // for(int i = 0 ; i < bills.size() ; i++){
    //     cin >> bills[i] ;
    // }
    // bool result = lemonade(bills) ;
    // if(result == true){
    //     cout << "Every Customer is provided with correct change " ;
    // }
    // else{
    //     cout << "Every customer is not provided with corect chnage " ;
    // }

    return 0 ;

}