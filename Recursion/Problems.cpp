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

// Letter Combination of a phone ->
void combo(int index , string& digits , string current , vector<string>& ans , vector<string>& mapping){
    if(index == digits.length()){
        ans.push_back(current) ;
        return ;
    }
    string letters = mapping[digits[index] - '0'] ;

    for(char ch : letters){
        current.push_back(ch) ;
        combo(index + 1 , digits , current , ans , mapping) ;
        current.pop_back() ;
    }
}
vector<string> lettercombination(string digits){
    vector<string> mapping{
        "" ,        // 0
        "" ,        // 1
        "abc" ,     // 2
        "def" ,     // 3
        "ghi" ,     // 4
        "jkl" ,     // 5
        "mno" ,     // 6
        "pqrs" ,    // 7
        "tuv" ,     // 8
        "wxyz"      // 9
        
    };

    vector<string> ans ;
    string current ;

    combo(0 , digits , current , ans , mapping) ;

    return ans ;
}

// Word Search ->
bool dfs(vector<vector<char>> board , string& word , int row , int column , int index){
    if(index == word.length()) return true ;

    if(row < 0 || row >= board.size() || column < 0 || column >= board[0].size()) return false ;

    if(board[row][column] != word[index]) return false ;

    char temp = board[row][column] ;
    board[row][column] = '#' ;

    bool found = dfs(board , word , row-1 , column , index + 1) ||
                 dfs(board , word , row+1 , column , index + 1) ||
                 dfs(board , word , row , column-1 , index + 1) ||
                 dfs(board , word , row , column+1 , index + 1) ;

                 board[row][column] = temp ;
                 return found ;
}
bool exist(vector<vector<char>>& board , string word){
    int m = board.size() ;
    int n = board[0].size() ;

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(dfs(board , word , i , j , 0)){
                return true ;
            }
        }
    }
    return false ;
}

// Palindrome Partioning ->
bool isPalindrome(int i , int j , string& s){
    while(i < j){
        if(s[i] != s[j]) return false ;
        i++ ;
        j-- ;
    }
    return true ;
}
void f(int i , string& s , vector<string>& path , vector<vector<string>>& ans){
    if(i == s.size()){
        ans.push_back(path) ;
        return ;
    }

    for(int j = i ; j < s.size() ; j++){
        if(isPalindrome(i , j , s)){
            path.push_back(s.substr(i ,  j-i+1)) ;
            f(j+1 , s , path , ans) ;
            path.pop_back() ;
        }
    }
}
vector<vector<string>> partition(string s){
    vector<vector<string>> ans ;
    vector<string> path ;
    f(0 , s , path , ans) ;
    return ans ;
}

// Sukodu Solving ->
bool isValid(vector<vector<char>>& board , int row , int col , char c){
        for(int i = 0 ; i < 9 ; i++){
            if(board[row][i] == c){
                return false ;
            }
            else if(board[i][col] == c){
                return false ;
            }
            else if(board[3 * (row / 3) + i/3][3 * (col / 3) + i%3] == c){
                return false ;
            }
        }
        return true ;
    }
bool solve(vector<vector<char>>& board){
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] == '.'){
                    for(char c = '1' ; c <= '9' ; c++){
                        if(isValid(board , i , j , c)){
                            board[i][j] = c ;
                            if(solve(board) == true) return true ;
                            else board[i][j] = '.' ;
                        }
                    }
                    return false ;
                }
            }
        }
        return true ;    
    }
void sudoku(vector<vector<char>>& board){
    solve(board) ;
}

// N Queens placing in ChessBoard (Method 1) ->
bool isSafe(int row , int col , vector<string> board , int n){
    int duprow = row ;
    int dupcol = col ;

    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q') return false ;
        row -- ;
        col -- ;
    }

    row = duprow ;
    col = dupcol ;
    while(col >= 0){
        if(board[row][col] == 'Q') return false ;
        col -- ;
    }

    row = duprow ;
    col = dupcol ;
    while(row < n && col >= 0){
        if(board[row][col] == 'Q') return false ;
        row ++ ;
        col -- ;
    }
    return true ;
}
void solve(int col , vector<string>& board , vector<vector<string>>& ans , int n){
    if(col == n){
        ans.push_back(board) ;
        return ;
    }
    for(int row = 0 ; row < n ; row++){
        if(isSafe(row , col , board , n)){
            board[row][col] = 'Q' ;
            solve(col+1 , board , ans , n) ;
            board[row][col] = '.' ;
        }
    }
}
vector<vector<string>> solveQueens(int n){
    vector<vector<string>> ans ;
    vector<string> board(n) ;
    string s(n , '.') ;
    for(int i = 0 ; i < n ; i++){
        board[i] = s ;
    }
    solve(0 , board , ans , n) ;
    return ans ;

}

// N Queens placing in ChessBoard (Method 2) ->
void solving(int col , vector<string>& board , vector<vector<string>>& ans , vector<bool>& row , vector<bool>& upperDiagonal , vector<bool>& lowerDiagonal , int n){
    if(col == n){
        ans.push_back(board) ;
        return ;
    }
    for(int r = 0 ; r < n ; r++){
        if(row[r] || lowerDiagonal[r+col] || upperDiagonal[n-1+col-r]) continue ;
        board[r][col] = 'Q' ;

        row[r] = true ;
        lowerDiagonal[r+col] = true ;
        upperDiagonal[n-1+col-r] = true ;

        solving(col+1 , board , ans , row , upperDiagonal , lowerDiagonal , n) ;
        board[r][col] = '.' ;

        row[r] = false ;
        lowerDiagonal[r+col] = false ;
        upperDiagonal[n-1+col-r] = false ;
    }
}
vector<vector<string>> solvingQueens(int n){
    vector<vector<string>> ans ;
    vector<string> board(n) ;
    string s(n , '.') ;

    vector<bool> row(n , false) ;
    vector<bool> lowerDiagonal(2*n-1 , false) ;
    vector<bool> upperDiagonal(2*n-1 , false) ;

    for(int i = 0 ; i < n ; i++){
        board[i] = s ;
    }

    solving(0 , board , ans , row , upperDiagonal , lowerDiagonal , n) ;
    return ans ;

}

// Rat in Maze (Method 1) ->
void solved(int i , int j , vector<vector<int>> &a , int n , vector<string>& ans , string move , vector<vector<int>> &vis){
    if(i == n-1 && j == n-1){
        ans.push_back(move) ;
        return ;
    }
    // downwards 
    if(i+1 < n &&  !vis[i+1][j] && a[i+1][j] == 1){
        vis[i][j] = 1 ;
        solved(i+1 , j , a , n , ans , move + 'D' , vis) ;
        vis[i][j] = 0 ;
    }

    // left
    if(j-1  >= 0 &&  !vis[i][j-1] && a[i][j-1] == 1){
        vis[i][j] = 1 ;
        solved(i , j-1 , a , n , ans , move + 'L' , vis) ;
        vis[i][j] = 0 ;
    }

    // right  
    if(j+1 < n &&  !vis[i][j+1] && a[i][j+1] == 1){
        vis[i][j] = 1 ;
        solved(i , j+1 , a , n , ans , move + 'R' , vis) ;
        vis[i][j] = 0 ;
    }
    // upwards 
    if(i-1 >= 0 &&  !vis[i-1][j] && a[i-1][j] == 1){
        vis[i][j] = 1 ;
        solved(i-1 , j , a , n , ans , move + 'U' , vis) ;
        vis[i][j] = 0 ;
    }
}
vector<string> pathSearch(vector<vector<int>> &m , int n){
        vector<vector<int>> vis(n , vector<int>(n,0)) ;
        vector<string> ans ;
        if(m[0][0] == 1) solved(0 , 0 , m , n , ans , "" ,  vis) ;
        return ans ;
}

// Rat in Maze (Method 2) ->
void solved2(int i , int j , vector<vector<int>> &a , int n , vector<string>& ans , string move , vector<vector<int>> &vis , int di[] , int dj[]){
    if(i == n-1 && j == n-1){
        ans.push_back(move) ;
        return ;
    }

    string dir = "DLRU" ;
    for(int ind = 0 ; ind < 4 ; ind++){
        int nexti = i + di[ind] ;
        int nextj = j + dj[ind] ;
        if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1){
            vis[i][j] = 1 ;
            solved2(nexti , nextj , a , n , ans , move+dir[ind] , vis , di ,dj) ;
            vis[i][j] = 0 ;
        }

    }
}
vector<string> pathSearch2(vector<vector<int>> &m , int n){
        vector<vector<int>> vis(n , vector<int>(n,0)) ;
        vector<string> ans ;
        int di[] = {1 , 0 , 0 , -1} ;
        int dj[] = {0 , -1 , 1 , 0} ;
        if(m[0][0] == 1) solved2(0 , 0 , m , n , ans , "" ,  vis , di , dj) ;
        return ans ;
}

// M Color Problem ->
bool isSafe(int node , int color[] , bool graph[101][101] , int n , int col){
    for(int k = 0 ; k < n ; k++){
        if(k != node && graph[k][node] == 1 && color[k] == col){
            return false ;
        }
    }
    return true ;
}
bool solve(int node , int color[] , bool graph[101][101] , int m , int N){
    if(node == N){
        return true ;
    }

    for(int i = 1 ; i <= m ; i++){
        if(isSafe(node , color , graph , N , i)){
            color[node] = i ;
            if(solve(node + 1 , color , graph , m , N)) return true ;
            color[node] = 0 ;
        }
    }
    return false ;
}
bool graphColoring(bool graph[101][101] , int m , int N){
    int color[N] = {0} ;
    if(solve(0 , color , graph , m , N)) return true ;
    return false ;
}

// Expression Add Operator ->
void reduce(int index , long long value , long long last , string path , string& nums , long long target , vector<string>& ans){
    if(index == nums.size()){
        if(value == target){
            ans.push_back(path) ;
            return ;
        }
    }

    long long current = 0 ;

    for(int i = index ; i < nums.size() ; i++){
        if(i > index && nums[index] == '0'){
            break ;
        }

        current = current * 10 + (nums[i] - '0') ;

        string currentStr = nums.substr(index , i-index+1) ;

        if(index == 0){
            reduce(i+1 , current , current , currentStr , nums , target , ans) ;
        }
        else{
            reduce(i+1 , value + current , current , path + "+" + currentStr , nums , target , ans) ;
            reduce(i+1 , value - current , -current , path + "-" + currentStr , nums , target , ans ) ;
            reduce(i+1 , value - last + (last * current) , current , path + "*" + currentStr , nums , target , ans) ;
        }
   }
}
vector<string> addOperators(string nums , long long target){
    vector<string> ans ;
    reduce(0 , 0 , 0 , "" , nums , target , ans) ;
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

    // Generate all combinations of parenthesis ->
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

    // Letter Combination of a phone ->
    // string digits ;
    // cout << "Enter the number : " ;
    // getline(cin , digits) ;
    // cout << "All possible combinations are : " << endl ;
    // vector<string> result = lettercombination(digits) ;
    // for(string digits : result){
    //     cout <<  digits << endl ;
    // }
    
    // Word Search ->
    // vector<vector<char>> board = {
    //     {'A', 'B', 'C', 'E'},
    //     {'S', 'F', 'C', 'S'},
    //     {'A', 'D', 'E', 'E'}
    // };
    // string word = "ABCCED";
    // if(exist(board, word)) {
    //     cout << "Word exists in the board." << endl;
    // }
    // else {
    //     cout << "Word does not exist in the board." << endl;
    // }

    // Palindrome Partioning ->
    // string s ;
    // cout << "Enter the string : " ;
    // getline(cin , s) ;
    // vector<vector<string>> result = partition(s) ;
    // cout << "All Partition Palindromes are:" << endl;
    // for (auto &partition : result) {
    //     cout << "[ ";
    //     for (auto &element : partition) {
    //         cout << element << " ";
    //     }
    //     cout << "]" << endl;
    // }

    // Sudoku Solving ->
    // vector<vector<char>> board(9, vector<char>(9));
    // cout << "Enter Sudoku (use . for empty cells) : \n";
    // // Taking input
    // for (int i = 0 ; i < 9 ; i++) {
    //     for (int j = 0 ; j < 9 ; j++) {
    //         cin >> board[i][j] ;
    //     }
    // }
    // // Solve Sudoku
    // sudoku(board) ;
    // // Print solved Sudoku
    // cout << "\nSolved Sudoku :\n" ;
    // for (int i = 0 ; i < 9 ; i++) {
    //     for (int j = 0 ; j < 9 ; j++) {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // N Queens placing in ChessBoard (M1 and M2) ->
    // int n ;
    // cout << "Enter the number of queens in the N x N ChessBoard : " ;
    // cin >> n ;
    // vector<vector<string>> result = solveQueens(n) ;
    // vector<vector<string>> result = solvingQueens(n) ;
    // cout << "All possible Sl+olutions are : \n " ;
    // for(auto &board : result){
    //     for(auto &row : board){
    //         cout << row << endl ;
    //     }
    //     cout << endl ;
    // }

    // Rat in Maze (M1 and M2) ->
    // int n ; 
    // cout << "Enter the no. of rowws / columns in the Maze : " ;
    // cin >> n ;
    // vector<vector<int>> maze(n , vector<int>(n)) ;
    // cout << "Enter the maze (0 = blocked &  1 = open) \n "; 
    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < n ; j++){
    //         cin >> maze[i][j] ;
    //     }
    // } 
    // vector<string> ans = pathSearch(maze , n) ;
    // if(ans.empty()){
    //     cout << "No path exists" << endl ;
    // }
    // else{
    //     cout << "All possible paths are " << endl  ;
    // }
    // for(string path : ans){
    //     cout << path << endl ;
    // }
    
    // M Color Problem ->
    // int N ; 
    // cout << "Enter the number of vertices : " ;
    // cin >> N ;
    // int m ;
    // cout << "Enter the number of colors : " ;
    // cin >> m ;
    // bool graph[101][101] ;
    // cout << "Enter adjacency matrix : \n" ;
    // for(int i = 0 ; i < N ; i++){
    //     for(int j = 0 ; j < N ; j++){
    //         cin >> graph[i][j] ;
    //     }
    // }
    // if (graphColoring(graph, m, N)) {
    //     cout << "Graph can be colored using " << m << " colors \n";
    // }
    // else {
    //     cout << "Graph cannot be colored using " << m << " colors \n";
    // }

    // Expression Add Operator ->
    // string nums ;
    // cout << "Enter the expression to be evaluated : " ;
    // getline(cin , nums) ;
    // long long target ;
    // cout << "Enter the target u Waana achieve : " ;
    // cin >> target ;
    // vector<string> result = addOperators(nums , target) ;
    // for(int i  = 0 ; i < result.size() ; i++){
    //     cout << result[i] << endl ;
    // }
    

    return 0 ;
    
}