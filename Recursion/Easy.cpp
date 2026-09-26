#include<bits/stdc++.h>
using namespace std ;

// Calculating Power of a number (x^n) ->
double myPow(double x, int n) {
    long long power = n;

    // Handle negative power
    if (power < 0) {
        x = 1 / x;
        power = -power;
    }
    double ans = 1;

    while (power > 0) {
        // If power is odd
        if (power % 2 == 1) {
            ans = ans * x;
        }

        x = x * x;
        power = power / 2;
    }

    return ans;
}

// Converting string into 32 Bit integer ->
int myAtoi(string s){
    int i = 0 ;
    int n = s.length() ;
    while(i < n && s[i] == ' '){
        i++ ;
    }
    int sign = 1 ;
    if(i < n && (s[i] == '+' || s[i] == '-')){
        if(s[i] == '-') sign = -1 ;
        i ++ ;
    }
    long long nums = 0 ;
    while(i < n && isdigit(s[i])){
        int digit = s[i] - '0' ;
        if(nums > INT_MAX / 10 || (nums == INT_MAX / 10  && digit > (sign == 1 ? 7 : 8))){
            return sign == 1 ? INT_MAX : INT_MIN ;
        }
        nums = nums * 10 + digit ;
        i++ ;
    }
    return sign * nums ;
}

// Contains Duplicate (Return true if any value appears atleast twice) ->
bool containsDuplicate(vector<int> &nums){
    unordered_set<int> s ;
    for(int x : nums){
        if(s.find(x) != s.end()) return true ;
        s.insert(x) ;
    }
    return false ;
}

// Generate all combinations of parenthesis ->
void generate(string s , int open , int close , int n , vector<string> &ans){
    if(open == n && close == n){
        ans.push_back(s) ;
        return ;
    }
    if(open < n){
        generate(s + "(" , open + 1 , close , n , ans) ;
    }
    if(close < open){
        generate(s + ")" , open , close + 1 , n , ans) ;
    }
}
vector<string> generateParenthesis(int n){
    vector<string> ans ;
    generate("" , 0 , 0 , n , ans);
    return ans ;
}

// Power Set ->
vector<string> getSubSequences(string s){
    int n = s.size() ;
    int total = 1 << n ;
    vector<string> SubSequences ; 
    for(int temp = 0 ; temp < total ; temp ++){
        string subseq = "" ;
        for(int i = 0 ; i < n ; i++){
            if(temp & (1 << i)){
                subseq += s[i] ;
            }
        }
        SubSequences.push_back(subseq) ;
    }
    return SubSequences ;
}

// Combinational Sum ->
void findCombinationalSum(vector<int>& nums , int target , int ind , vector<int>& ds , vector<vector<int>>& ans){
    if(ind == nums.size()){
        if(target == 0){
            ans.push_back(ds) ;
        }
        return ;
    }

    if(nums[ind] <= target){
        ds.push_back(nums[ind]) ;
        findCombinationalSum(nums , target - nums[ind] , ind , ds , ans) ;
        ds.pop_back() ;
    }
    findCombinationalSum(nums , target, ind + 1 , ds , ans) ;
}
vector<vector<int>> combinationalSum(vector<int>& candidate , int target){
    vector<vector<int>> ans ;
    vector<int> ds ;
    findCombinationalSum(candidate , target , 0 , ds , ans) ;
    return ans ;
}

// Combinational Sum 2 ->
void findCombinational2(int ind , int target , vector<int>& arr , vector<vector<int>>& ans  , vector<int>& ds){
    if(target == 0){
        ans.push_back(ds) ;
        return ;
    }
    for(int i = ind ; i < arr.size() ; i++){
        if(i > ind && arr[i] == arr[i-1]) continue ;
        if(arr[i] > target) break ;
        ds.push_back(arr[i]) ;
        findCombinational2(i+1 , target - arr[i] , arr , ans , ds) ;
        ds.pop_back() ;
    }
}
vector<vector<int>> combinationalSum2(vector<int>& candidates , int target){
    sort(candidates.begin() , candidates.end()) ;
    vector<vector<int>> ans ;
    vector<int> ds ;
    findCombinational2(0 , target , candidates , ans , ds) ;
    return ans ;
}

// Combinational Sum 3 ->
void solve(int start , int k , int n , vector<int>& current , vector<vector<int>>& ans ){
    if(current.size() == k){
        if(n == 0){
            ans.push_back(current) ;
        }
        return ;
    }
    for(int i = start ; i <= 9 ; i++){
        if(i > n) break ;

        current.push_back(i) ;
        solve(i+1 , k , n-i , current , ans) ;
        current.pop_back() ;
    }
}
vector<vector<int>> combinationalSum3(int k , int n){
    vector<vector<int>> ans ;
    vector<int> current ;

    solve(1 , k , n , current , ans) ;
    return ans ;
}

// Return All SubSets / Power Set (Containg unique Elements) ->
void func(int ind , vector<int>& nums , vector<int>& current , vector<vector<int>>& subSets){
    int n = nums.size() ;

    if(ind == n){
        subSets.push_back(current) ;
        return ;
    }

    current.push_back(nums[ind]);                   // taking the nxt element in the recursion call
    func(ind+1 , nums , current , subSets) ;

    current.pop_back() ;                            // Back tracking

    func(ind+1 , nums , current , subSets) ;        // Not taking the nxt element in the recursion call 
}
vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> subSets ;
    vector<int> current ;

    func(0 , nums , current , subSets) ;

    return subSets ;
}

// Return All SubSets / Power Set (Containg duplicate Elements) ->
void fun(int ind , vector<int>& nums , vector<int>& ds , vector<vector<int>>& ans){
    ans.push_back(ds) ;
    for(int i = ind ; i < nums.size() ; i++){
        if(i != ind && nums[i] == nums[i-1]) continue ; 
            ds.push_back(nums[i]) ;
            fun(i+1 , nums , ds , ans) ;
            ds.pop_back() ;
    }
}
vector<vector<int>> subsets2(vector<int>& nums){
    vector<vector<int>> ans ;
    vector<int> ds ;
    sort(nums.begin() , nums.end()) ;
    fun(0 , nums , ds , ans) ;
    return ans ;
}


int main(){

    // Power of a number ->
    // double x ;
    // cout << "Enter the base : " ;
    // cin >> x ;
    // int n ;
    // cout << "Enter the power : " ;
    // cin >> n ;
    // int ans = myPow(x ,n) ;
    // cout << x << " raised to power " << n << " is " << ans ;
    
    // Converting string into 32 Bit integer -> 
    // string s ;
    // cout << "Enter the string to be converted : " ;
    // getline(cin , s) ;
    // int ans = myAtoi(s) ;
    // cout << ans ;

    // Contains Duplicate ->
    // int n ;
    // cout << "Enter the number of elements in the array : " ;
    // cin >> n ;
    // vector<int> nums(n) ;
    // cout << "Enter the elements in the array : " << endl ;
    // for(int i = 0 ; i< n ; i++){
    //     cin >> nums[i] ;
    // }
    // if(containsDuplicate(nums) == true){
    //     cout << "Contains duplicate element" ;
    // }
    // else{
    //     cout << "Doesn't contains duplicate element " ;
    // }

    //  Generate all combinations of parenthesis ->
    // int n ;
    // cout << "Enter the number of parenthesis : " ;
    // cin >> n ;
    // vector<string> ans = generateParenthesis(n);
    // cout << "All valid combinations are:" << endl;
    // for (string s : ans) {
    //     cout << s << endl;
    // }

    // Power Set ->
    // string s ;
    // cout << "Enter the string : " ;
    // getline(cin , s) ;
    // vector<string> SubSequence = getSubSequences(s) ;
    // for(auto &subseq : SubSequence){
    //     cout << subseq << endl ;
    // }
    // return 0 ;

    // Combinational Sum / Combinational Sum 2 ->
    // int n ; 
    // cout << "Enter the number of elements in the array : "  ;
    // cin >> n ;
    // vector<int> nums(n) ;
    // cout << "Enter the elements in the array : " << endl ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> nums[i] ;
    // }
    // int target ; 
    // cout << "Enter the target value : " ;
    // cin >> target ;
    // // vector<vector<int>> ans = combinationalSum(nums , target) ;
    // vector<vector<int>> ans = combinationalSum2(nums , target) ;
    // cout << "Combinations are : " << endl ;
    // for(int i = 0 ; i < ans.size() ; i++){
    //     for(int j = 0 ; j < ans[i].size() ; j++){
    //         cout << ans[i][j] << " " ;
    //     }
    //     cout << endl ;
    // }

    // Combinational Sum 3 ->
    // int k , n ;
    // cout << "Enter the number of elements to be used : " ;
    // cin >> k ;
    // cout << "Enter the sum of elements : " ;
    // cin >> n ;
    // vector<vector<int>> result = combinationalSum3(k ,n) ;
    // cout << "Combinations are : " << endl ;
    // for(int i = 0 ; i < result.size() ; i++){
    //     for(int j = 0 ; j < result[i].size() ; j++){
    //         cout << result[i][j] << " " ;
    //     }
    //     cout << endl ;
    // }

    // All combinations of Subsets OR Power Set (I and II) ->
    // int n ;
    // cout << "Enter the number of elements : " ;
    // cin >> n ;
    // vector<int> nums(n) ;
    // cout << "Enter the elements in the array : " << endl ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> nums[i] ;
    // }
    // vector<vector<int>> ans = subsets(nums) ;
    // cout << "All subsets are:" << endl;
    // for (auto &subset : ans) {
    //     cout << "[ ";
    //     for (auto &element : subset) {
    //         cout << element << " ";
    //     }
    //     cout << "]" << endl;
    // }


    return 0 ;
    
}