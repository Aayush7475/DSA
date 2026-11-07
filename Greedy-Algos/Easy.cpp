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

// Fractional knapSack->
struct Item{
    int value ;
    int weight ;
};
bool comp(Item a , Item b){
    double r1 = (double)a.value / a.weight ;
    double r2 = (double)b.value / b.weight ;
    return r1 > r2 ;
}
double fractionalKnapSack(int W , vector<Item>& arr){
    sort(arr.begin() , arr.end() , comp) ;
    double totalValue = 0.0 ;

    for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i].weight <=  W){
            totalValue += arr[i].value ;
            W -= arr[i].weight ;
        }
        else{
            totalValue += (double)arr[i].value * W / arr[i].weight ;
            break ;
        }
    }
    return totalValue ;
}

// Jump game I ->
bool canJump(vector<int>& nums){
    int MaxJump = 0 ;
    for(int i = 0 ; i < nums.size() ; i++){
        if(i > MaxJump) return false ;
        else{
            MaxJump = max(MaxJump , i + nums[i]) ;
        }
    }
    return true ;
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

    // Fractional KnapSack ->
    // int n ;
    // cout << "Enter the number of items : " ;
    // cin >> n ; 
    // vector<Item> arr(n) ;
    // cout << "Enter the value and weight of each item : " << endl ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> arr[i].value >> arr[i].weight ;
    // }
    // int W ;
    // cout << "Enter the KnapSack Capacity :  " ;
    // cin >> W ;
    // double ans = fractionalKnapSack(W , arr) ;
    // cout << "Maximum Profit : " << fixed << setprecision(2) << ans << endl ;

    // Jump Game I->
    // int n ;
    // cout << "Enter the number of elements : " ;
    // cin >> n ;
    // vector<int> nums(n) ;
    // cout << "Enter the number of maximum jumps that can be made : " << endl ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> nums[i] ;
    // }
    // bool result = canJump(nums) ;
    // if(result) cout << "Can jump to the last index of the array " ;
    // else cout << "Can't jump to the last index of the array " ;

    return 0 ;

}