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
bool comp(jobs a , jobs b){
    return a.profit > b.profit ;
}
vector<int> Job(vector<jobs>& nums){
    sort(nums.begin() , nums.end() , comp) ;
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

    return 0 ;
}