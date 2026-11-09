#include<bits/stdc++.h>
using namespace std ;

// Shortest job First (CPU Scheduling = Scheduling Policy that selects the waiting process with shortest execution time to execute next) ->
int SJF(vector<int> nums){
    sort(nums.begin() , nums.end()) ;
    int waitTime = 0 ;
    int t = 0 ; 
    int n = nums.size() ;
    for(int i = 0 ; i < n ; i++){
        waitTime += t ;
        t += nums[i] ;
    }
    return (waitTime / n) ;
}

// Job Sequencing Problem ->
struct jobs{
    int id ;
    int profit ;
    int deadline ;
};
bool comp1(jobs a , jobs b){
    return a.profit > b.profit ;
}
vector<int> Job(vector<jobs>& nums){
    sort(nums.begin() , nums.end() , comp1) ;
    int cnt = 0 ;
    int totalProfit = 0 ;
    int maxDeadline = -1 ;
    
    for(int i = 0 ; i < nums.size() ; i++){
        maxDeadline = max(maxDeadline , nums[i].deadline) ;
    }

    vector<int> hash(maxDeadline + 1 , -1) ;

    for(int i = 0 ; i < nums.size() ; i++){
        for(int j = nums[i].deadline ; j > 0 ; j--){
            if(hash[j] == -1){
                cnt ++ ;
                hash[j] = nums[i].id ;
                totalProfit += nums[i].profit ;
                break ;
            }
        }
    }
    return {cnt , totalProfit} ;
}

// N Meeting In One Room ->
struct meetings{
    int start ;
    int end ;
    int pos ;
};
bool comp2(meetings a , meetings b){
    if(a.end == b.end) return a.pos < b.pos ;
    return a.end < b.end ;
}
vector<int> Meet(vector<meetings>& nums){
    int n = nums.size() ;
    if(n == 0) return {} ;
    for(int i = 0 ; i < n ; i++){
        nums[i].pos = i + 1 ;
    }
    sort(nums.begin() , nums.end() , comp2) ;
    
    int cnt = 1 ;
    int freeTime = nums[0].end ;
    vector<int> ds ;
    ds.push_back(nums[0].pos) ; 
    
    for(int i = 1 ; i < n ; i++){
        if(nums[i].start > freeTime){
            cnt ++ ;
            freeTime = nums[i].end ;
            ds.push_back(nums[i].pos) ;
        }
    }
    return ds ; 
}

// Erase OverLapping Intervals ->
bool comp3(const vector<int>& a , const vector<int>& b){
    return a[1] < b[1] ;
}
int eraseOverlappingIntervals(vector<vector<int>>& intervals){
    int n = intervals.size() ;
    if(n <= 1) return 0 ;
    sort(intervals.begin() , intervals.end() , comp3) ;
    int cnt = 1 ;
    int LastEndTime = intervals[0][1] ;

    for(int i = 1 ; i < n ; i++){
        if(intervals[i][0] >= LastEndTime){
            cnt ++ ;
            LastEndTime = intervals[i][1] ;
        }
    }
    return (n - cnt) ;
}

// Insert Intervals ->
vector<vector<int>> insert(vector<vector<int>>& intervals , vector<int>& newIntervals){
    vector<vector<int>> res ;
    int n = intervals.size() ;
    int i = 0 ;

    while(i < n && intervals[i][1] < newIntervals[0]){
        res.push_back(intervals[i]) ;
        i ++ ;
    }

    while(i < n && intervals[i][0] <= newIntervals[1]){
        newIntervals[0] = min(newIntervals[0] , intervals[i][0]) ;
        newIntervals[1] = max(newIntervals[1] , intervals[i][1]) ;
        i ++ ;
    }
    res.push_back(newIntervals) ;

    while(i < n){
        res.push_back(intervals[i]) ;
        i ++ ;
    }
    return res  ;
}

int main(){

    // SJF ->
    // int n ; 
    // cout << "Enter the number of Processes : " ;
    // cin >> n ;
    // vector<int> nums(n) ;
    // cout << "Enter the Scheduling Process Timings : " << endl ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> nums[i] ;
    // }
    // cout << "Average Waiting Time : " ;
    // cout << SJF(nums) ;
    
    // Job Scheuling Problem ->
    // int n ;
    // cout << "Enter the number of Jobs : " ;
    // cin >> n ;
    // vector<jobs> nums(n) ;
    // cout << "Enter the details of Jobs Like id , profit , deadline : " << endl ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> nums[i].id ;
    //     cin >> nums[i].profit ;
    //     cin >> nums[i].deadline ;
    // }
    // vector<int> ans = Job(nums) ;
    // cout << "Jobs Completed : " << ans[0] << endl  ;
    // cout << "Profit Earned : " << ans[1] << endl ;

    // N Meetings in One Room ->
    // int n ;
    // cout << "Enter the number of Meetings : " ;
    // cin >> n ;
    // vector<meetings> nums(n) ;
    // cout << "Enter start and end times for each meeting : " << endl ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> nums[i].start >> nums[i].end ;
    // }
    // vector<int> ans = Meet(nums) ;
    // cout << "Total Meetings: " << ans.size() << endl ;
    // cout << "Meeting Order (1-based index): " ;
    // for(int x : ans) cout << x << " " ;
    // cout << endl ;

    // Remove OverLapping intervals ->
    // int n ;
    // cout << "Enter the number of intervals : " ;
    // cin >> n ;
    // vector<vector<int>> intervals(n , vector<int>(2)) ;
    // cout << "Enter the start and end points of the intervals : " << endl ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> intervals[i][0] >> intervals[i][1] ;
    // }
    // cout << "Minimum intervals to remove : " << eraseOverlappingIntervals(intervals) << endl ;

    // Insert Intervals ->
    int n ;
    cout << "Enter the number of intervals : " ;
    cin >> n ;
    vector<vector<int>> intervals(n , vector<int>(2)) ;
    cout << "Enter the start and end points of the intervals : " << endl ;
    for(int i = 0 ; i < n ; i++){
        cin >> intervals[i][0] >> intervals[i][1] ;
    }
    vector<int> newIntervals(2) ;
    cout << "Enter the new Interval to be inserted (start and end) : " << endl ;
    cin >> newIntervals[0] >> newIntervals[1] ;
    vector<vector<int>> ans = insert(intervals , newIntervals) ;
    cout << "The overall intervals set is : " << endl ;
    for(int i = 0 ; i < ans.size() ; i++){
        cout << "[" << ans[i][0] << ", " << ans[i][1] << "] " ;
    }
    cout << endl ;

    return 0 ;
}