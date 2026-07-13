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
bool canWePlace(vector<int>& nums , int dist , int cows){
    int cntCows = 1 ;
    int last = nums[0] ;
    for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i]-last >= dist){
            cntCows ++ ;
            last = nums[i] ;
        }
        if(cntCows >= cows) return true ;
    }
    return false ;
}
int aggressiveCows(vector<int>& nums , int k){
    sort(nums.begin() , nums.end());
    int n = nums.size() ;
    int low = 0 ;
    int high = nums[n-1] - nums[0] ;
    while(low <= high){
        int mid = (low + high) / 2 ;
        if(canWePlace(nums , mid , k) == true){
            low = mid + 1 ;
        }
        else{
            high = mid - 1 ;
        }
    }
    return high ;
}

// Books allocation ->
int countStudents(vector<int>& nums , int pages){
    int students = 1 ;
    long long pagesStudent = 0 ;
    for(int i = 0 ; i < nums.size() ; i++){
        if(pagesStudent + nums[i] <= pages){
            pagesStudent += nums[i] ;
        }
        else{
            students += 1 ;
            pagesStudent = nums[i] ;
        }
    }
    return students ;
}
int findpages(vector<int>& nums , int k , int m){
    if(m > k) return -1 ;
    int low = *max_element(nums.begin() , nums.end()) ;
    int high = accumulate(nums.begin() , nums.end() , 0LL) ;
    while(low <= high){
        int mid = (low + high) / 2 ;
        int students = countStudents(nums , mid) ;
        if(students > m){
            low = mid + 1 ;
        }
        else{
            high = mid - 1 ;
        }
    }
    return low ;
}

// Split array into largest sum ->
int countPartitons(vector<int>& nums , int maxSum){
    int partition = 1 ;
    long long subArraySum = 0 ;
    for(int i = 0 ; i < nums.size() ; i++){
        if(subArraySum + nums[i] <= maxSum){
            subArraySum += nums[i] ;
        }
        else{
            partition ++ ;
            subArraySum = nums[i] ;
        }
    }
    return partition ;
}
int largestSubArray(vector<int>& nums , int k){
    int low = *max_element(nums.begin() , nums.end()) ;
    int high = accumulate(nums.begin() , nums.end() , 0) ;
    while(low <= high){
        int mid = (low + high) / 2 ;
        int partition = countPartitons(nums , mid) ;
        if(partition > k){
            low = mid + 1 ;
        }
        else{
            high = mid - 1 ;
        }
    }
    return low ;
}

// Minimize maximum distance between two Gas Stations Method 1 ->
long double minimizeMaxDistance(vector<int>& nums , int k){
    int n = nums.size() ;
    vector<int> howMany(n-1 , 0) ;
    priority_queue<pair<long double , int>> pq ;
    for(int i = 0 ; i <= n-1 ; i++){
        pq.push({nums[i+1] - nums[i] , i}) ;
    }

    for(int gasStation = 1 ; gasStation <= k ; gasStation++){
        auto x = pq.top() ; pq.pop() ;
        int secIndex = x.second ;
        howMany[secIndex] ++ ;
        long double iniDiff = nums[secIndex + 1] - nums[secIndex] ;
        long double newSecLen = iniDiff / (long double) (howMany[secIndex] + 1) ;
        pq.push({newSecLen , secIndex}) ;
    }
    return pq.top().first ;
}

// Minimize maximum distance between two Gas Stations Method 2 ->
int numberOfGasStationsRequired(vector<int>& nums , long double dist){
    int cnt = 0 ;
    for(int i = 1 ; i <= nums.size() ; i++){
        int numberInBetween = ((nums[i] - nums[i+1]) / dist) ;
        if((nums[i] - nums[i-1]) / dist == numberInBetween * dist ){
            numberInBetween ++ ;
        }
        cnt += numberInBetween ;
    }
    return cnt ;
}
long double MinimizeMaxDistance(vector<int>& nums , int k){
    int n = nums.size() ;
    long double low = 0 ;
    long double high = 0 ;
    for(int i = 1 ; i < n-1 ; i++){
        high = max(high , (long double) (nums[i+1] - nums[i])) ;
    }

    long double diff = 1e-6 ;
    while(high - low > diff){
        long double mid = (low + high) / (2.0) ;
        int cnt = numberOfGasStationsRequired(nums , mid); 
        if(cnt > k){
            low = mid ;
        }
        else{
            high = mid ;
        }
    }
    return high ;
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

    // int k ;         // Position of the missing number in the array 
    // cout << "Enter the position of missing element : ";
    // cin >> k ;

    // int k ;         // Number of cows to be placed in between the stalls 
    // cout << "Enter the number of cows to be placed in between : ";
    // cin >> k ;

    // int k ;         // Number of books to be distributed 
    // cout << "Enter the value of k : " ;
    // cin >> k ;

    // int m ;         // Number of people in which books will be distributed 
    // cout << "Enter the value of m : " ;
    // cin >> m ;

    // int k ;         // Number of subarrays in which the array will be divided 
    // cout << "Enter the number of Sub Arrays in which the Array will be divided : ";
    // cin >> k ;

    int k ;            // Number of Gas Station to be added in between 
    cout << "Enter the number of Gas Stations to be added :" ;
    cin >> k ;

    // cout << "Floor value of square root of the target is  = " << squareRoot(target) ;

    // cout << "Nth root of " << target << " is : " << nRoot(target , root);

    // cout << "Minimum time in which koko can eat all the bananas : " << minEatingSpeed(nums , h) ;

    // cout << "Minimum time required to make " << m << " bouquets with " << k << " flowers is : " << minDay(nums , m , k); 

    // cout << "Smallest divisor : " << small(nums , limit) ;

    // cout << "Minimum Capacity of the ship to move the goods is : " << shipWithinDays(nums , days) ;

    // cout << "The " << k << " missing number is : " << missingK(nums , k) ;

    // cout << "Maximum distance at which " << k << " Cows can be placed is : " << aggressiveCows(nums , k) ;

    // cout << "The answer is : " << findpages(nums , k , m) ; 

    // cout << "Largest SubArray with minimum sum is : " << largestSubArray(nums , k) ;

    cout << "Minimized maximum distance between the Gas Stations is : " << MinimizeMaxDistance(nums , k) ;
    
    return 0 ;

}