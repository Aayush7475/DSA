#include<bits/stdc++.h>
using namespace std ;

// Finding Square Root ->
int squareRoot(int target){ 
    int low = 0 ; 
    int high = target ;
    int ans = 1 ;
    while(low <= high){
        int mid = (low + high) / 2 ;
        if((1LL*mid*mid) <= target){
            ans = mid;
            low = mid+1 ;
        } 
        else{
            high = mid -1  ;
        }
    }
    return ans ;
}

// Finding Nth Root ->
int multiply(int number , int power){
    int ans = 1 ;
    for(int i = 0 ; i < power ; i++){
        ans = ans * number ;
    }
    return ans ;

}
int nRoot(int target , int root){
    int low = 1 ;
    int high = target ;

    while(low <= high){
        int mid = low + (high-low) / 2 ;
        int value = multiply(mid , root) ;
        
        if(value == target){
            return mid ;
        }
        else if(value < target){
            low = mid + 1 ;
        }
        else{
            high = mid - 1 ;
        }
    }
    return -1 ;
}

// Koko eating bananas ->
int maxElement(vector<int>& nums){
    int n = nums.size() ;
    int maxi = INT_MIN ;
    for(int i = 0 ; i < n ; i++){
        maxi = max(maxi , nums[i]) ;
    }
    return maxi ;
}
int TotalHours(vector<int>& nums , int hourly){
    int n = nums.size() ;
    int totalHour = 0 ;
    for(int i = 0 ; i < n ; i++){
        totalHour += ceil((double)nums[i] / (double)hourly); 
    }
    return totalHour ;
}
int minEatingSpeed(vector<int>& nums , int h){
    int low = 1 ;
    int high = maxElement(nums) ;
    while(low < high){
        int mid = (low + high) / 2 ;
        int totalHours = TotalHours(nums , mid) ;
        if(totalHours <= h){
            high = mid - 1 ;
        }
        else{
            low = mid + 1 ;
        }
    }
    return low ;
}



int main(){
    int n ; 
    cout << "Enter the number of elements in the array : " ;
    cin >> n ;

    vector<int> nums(n) ;
    cout << "Enter the elements in the array : " << endl ;
    for(int i = 0 ; i < n ; i++){
        cin >> nums[i] ;
    }

    // int target ;
    // cout << "Enter the target element : ";
    // cin >> target ;

    // int root ;
    // cout << "Enter the number of root to be calculated : " ;
    // cin >> root ;

    int h ;
    cout << "Enter the value of h : ";
    cin >> h ;

    // cout << "Floor value of square root of the target is  = " << squareRoot(target) ;

    // cout << "Nth root of " << target << " is : " << nRoot(target , root);

    cout << "Minimum time in which koko can eat all the bananas : " << minEatingSpeed(nums , h) ;


    return 0 ;

}