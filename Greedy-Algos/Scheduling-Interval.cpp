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

int main(){

    // SJF ->
    int n ; 
    cout << "Enter the number of Processes : " ;
    cin >> n ;
    vector<int> nums(n) ;
    cout << "Enter the Scheduling Process Timings : " << endl ;
    for(int i = 0 ; i < n ; i++){
        cin >> nums[i] ;
    }
    cout << "Average Waiting Time : " ;
    cout << SJF(nums) ;
    
    return 0 ;
}