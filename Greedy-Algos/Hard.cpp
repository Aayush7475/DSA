#include<bits/stdc++.h>
using namespace std ;

// Candy Distribution (Method 1) ->
int candy(vector<int>& nums){
    int n = nums.size() ;
    vector<int> left(n , 1) ;
    vector<int> right(n , 1) ;

    left[0] = 1 ;
    right[n-1] = 1 ;

    for(int i = 1 ; i < n ; i++){
        if(nums[i] > nums[i-1]){
            left[i] = left[i-1] + 1 ;
        }
        else{
            left[i] = 1 ;
        }
    }

    for(int i = n-2 ; i >= 0 ; i--){
        if(nums[i] > nums[i+1]){
            right[i] = right[i+1] + 1 ;
        }
        else{
            right[i] = 1 ;
        }
    }

    int sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        sum = sum + max(left[i] , right[i]) ;
    }
    return sum ;
}

// Candy Distribution (Method 2) ->
int candy2(vector<int>& nums){
    int n = nums.size() ;
    vector<int> left(n , 1) ;
  
    left[0] = 1 ;

    for(int i = 1 ; i < n ; i++){
        if(nums[i] > nums[i-1]){
            left[i] = left[i-1] + 1 ;
        }
        else{
            left[i] = 1 ;
        }
    }

    int curr = 1 ; 
    int right = 1 ;
    int sum = max(1 , left[n-1]) ;

    for(int i = n-2 ; i >= 0 ; i--){
        if(nums[i] > nums[i+1]){
            curr = right + 1 ;
            right = curr ;
        }
        else{
            curr = 1 ;
        }
        sum = sum + max(curr , left[i]) ;
    }
    return sum ;
}

// candy distribution (Method 3) ->
int candy3(vector<int>& nums){
    int sum = 1 ;
    int i = 1 ;
    int n = nums.size() ;

    while(i < n){
        if(nums[i] == nums[i-1]){
            sum = sum + 1 ;
            i++ ;
            continue ;
        }
        
        int peak = 1 ;
        while(i < n && nums[i] > nums[i-1]){
            peak += 1 ;
            sum += peak ;
            i++ ;
        }

        int down = 1 ;
        while(i < n && nums[i] < nums[i-1]){
            sum += down ;
            i++ ;
            down += 1 ;
        }

        if(down > peak){
            sum += down - peak ;
        }
    }
    return sum ;
}

int main(){

    // candy Distribution (M1 and M2 and M3) ->
    // int n ;
    // cout << "Enter the number of childrens : " ;
    // cin >> n ; 
    // vector<int> nums(n) ;
    // cout << "Enter the ratings of each child : " << endl ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> nums[i] ;
    // }
    // cout << "Total Sum of candies required is " << candy(nums) ;
    // cout << "Total Sum of candies required is " << candy2(nums) ;
    // cout << "Total Sum of candies required is " << candy3(nums) ;

    return 0 ;
}