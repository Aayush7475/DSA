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

// Minimum days to make a bouquets ->
int Possiblities(vector<int>& nums , int day , int m , int k){
    int n = nums.size() ;
    int count = 0 ;
    int bouquets = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(nums[i] <= day){
            count ++ ;
        }
        else{
            bouquets += count / k ;
            count = 0 ;
        }
    }
    bouquets += count / k ;
    if(bouquets >= m) return true ;
    else return false ;
}
int minDay(vector<int>& nums , int m , int k){
    long long totalFlowers = 1LL * m * k ;

    if(totalFlowers > nums.size()) return -1 ;

    int low = *min_element(nums.begin() , nums.end());
    int high = *max_element(nums.begin() , nums.end());

    for(int i = low ; i <= high ; i++){
        if(Possiblities(nums , i , m , k)){
        return i ;
        }
    }
    return -1 ;
}

// Find smallest divisor ->
int divisor(vector<int>& nums , int div){
    int n = nums.size() ;
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        sum += ceil((double)nums[i] / (double)div) ;
    }
    return sum ; 
}
int small(vector<int>& nums , int limit){
    int n = nums.size() ;
    int low = 1 ;
    int high = *max_element(nums.begin() , nums.end());
    while(low <= high){
        int mid = (low + high) / 2 ;
        if(divisor(nums , mid) <= limit){
            high = mid - 1 ;
        }
        else{
            low = mid + 1 ;
        }
    }
    return low ;
}

// Capacity to ship packages within D days ->
int requiresDays(vector<int>& nums , int capacity){
    int days = 1 ;
    int load = 0 ;
    for(int i = 0 ; i < nums.size() ; i++){
        if(load + nums[i] > capacity){
            days = days + 1 ;
            load = nums[i] ;
        }
        else{
            load += nums[i] ;
        }
    }
    return days ;
}
int shipWithinDays(vector<int>& nums , int days){
    int n = nums.size() ;
    int left = *max_element(nums.begin() , nums.end());
    int right = (n*(n+1)) / 2 ;
    for(int capacity = left ; capacity <= right ; capacity++){
        int needed = requiresDays(nums , capacity) ;
        if(needed <= days){
            return capacity ;
        }
    }
    return right ;
}

// Missing the Kth positive number ->
int missingK(vector<int>& nums , int k){
    int n = nums.size() ;
    int low = 0 ;
    int high = n-1 ;
    while(low <= high){
        int mid = (low + high) / 2 ;
        int missing = nums[mid] - (mid + 1) ;
        if(missing < k){
            low = mid + 1 ;
        }
        else{
            high = mid - 1 ;
        }
    }
    return k + high + 1 ;
}

// Aggresive Cows ->




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

    // int root ;      // Nth root of a number
    // cout << "Enter the number of root to be calculated : " ;
    // cin >> root ;

    // int h ;         // Hours required by koko to eat bananas 
    // cout << "Enter the value of h : ";
    // cin >> h ;

    // int m ;         // Number of bouquets to be made
    // cout << "Enter the number of bouquets to be made : ";
    // cin >> m ;

    // int k ;         // Number of adjacent flowers required to make a bouquet
    // cout << "Enter the number of flowers required in the bouquet : ";
    // cin >> k ;

    // int limit ;     // Limit so that divisor should be smaller than it
    // cout << "Enter the limit from which the divisor should be small : " ;
    // cin >> limit ;

    // int days ;      // Number of days to ship the goods 
    // cout << "Enter the number of days to ship the goods : ";
    // cin >> days ;

// int k ;
// cout << "Enter the position of missing element : ";
// cin >> k ;


    // cout << "Floor value of square root of the target is  = " << squareRoot(target) ;

    // cout << "Nth root of " << target << " is : " << nRoot(target , root);

    // cout << "Minimum time in which koko can eat all the bananas : " << minEatingSpeed(nums , h) ;

    // cout << "Minimum time required to make " << m << " bouquets with " << k << " flowers is : " << minDay(nums , m , k); 

    // cout << "Smallest divisor : " << small(nums , limit) ;

    // cout << "Minimum Capacity of the ship to move the goods is : " << shipWithinDays(nums , days) ;

    // cout << "The " << k << " missing number is : " << missingK(nums , k) ;


    return 0 ;

}