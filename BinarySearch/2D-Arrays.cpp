#include<bits/stdc++.h>
using namespace std ; 

// Finding the row number containing maximum number of 1s
int lowerBound(vector<int>& nums , int x ){
    int n = nums.size() ;
    int low = 0 ;
    int high = n-1 ;
    int ans = n ;
    while(low <= high){
        int mid = low + (high - low) / 2 ;
        if(nums[mid] >= x){
            ans = mid ;
            high = mid - 1 ;
        }
        else{
            low = mid + 1 ;
        }
    }
    return ans ;
}
int rowWithMax_1s(vector<vector<int>>& matrix , int n , int m ){
    int cnt_max = 0 ;
    int index = -1 ;
    for(int i = 0 ; i < n ; i++){
        int lb = lowerBound(matrix[i], 1);
        int cnt_1s = m - lb ;

    cout << "Row " << i
    << " LowerBound = " << lb
    << " Ones = " << cnt_1s << endl;

    if(cnt_1s > cnt_max){
        cnt_max = cnt_1s ;
        index = i ;
        }
    }
    return index ;
}

// Finding the target value in the matrix having sorted rows 
bool searchMatrix(vector<vector<int>>& matrix , int target){
    if(matrix.size() == 0) return false ;

    int n = matrix.size() ;
    int m = matrix[0].size() ;

    int low = 0 ;
    int high = (n*m)-1 ;

    while(low <= high){
        int mid = low + (high - low) / 2 ;
        if(matrix[mid / m][mid % m] == target){
            return true ;
        }
        else if(matrix[mid / m][mid % m] < target){
            low = mid + 1 ;
        }
        else{
            high = mid - 1 ;
        }
    }
    return false ;
}

// Finding the target value in the matrix having sorted rows nd columns
bool SearchMatrix(vector<vector<int>>& matrix , int target){
     int n = matrix.size() ;
     int m = matrix[0].size() ;

     int row = 0 ;
     int column = m-1 ;

     while(row < n && column >= 0){
        if(matrix[row][column] == target) return true ;
        if(matrix[row][column] > target) column-- ;
        else row++ ;
     } 
     return false ;  
}

// Finding the peak element 
int FindMaxIndex(vector<vector<int>>& matrix , int n , int m , int col){
    int maxValue = INT_MIN ;
    int index = -1 ;

    for(int i = 0 ; i < n ; i++){
        if(matrix[i][col] > maxValue){
            maxValue = matrix[i][col] ;
            index = i ;
        }
    }
    return index ;
}
vector<int> peak(vector<vector<int>>& matrix ){
    int n = matrix.size() ;
    int m = matrix[0].size() ;
    int low = 0 ;
    int high = m-1 ;
    while(low <= high){
        int mid = low + (high - low) / 2 ;
        int maxRowIndex = FindMaxIndex(matrix , n , m , mid) ;
        int left = mid - 1 >= 0 ? matrix[maxRowIndex][mid - 1] : -1 ;
        int right = mid + 1 < m ? matrix[maxRowIndex][mid + 1] : -1 ;
        if(matrix[maxRowIndex][mid] > left && matrix[maxRowIndex][mid] > right){
            return {maxRowIndex , mid} ;
        }
        else if (matrix[maxRowIndex][mid] < left){
            high = mid - 1 ;
        }
        else{
            low = mid + 1 ;
        }
    }
    return {-1 , -1} ;
}

// Finding the median of a matrix  
int upperBound(vector<int>& nums , int x ,int n){
    int low = 0 ;
    int high = n-1 ; 
    int ans = n ;
    while(low <= high){
        int mid = (low + high) / 2 ;
        if(nums[mid] > x){
            ans = mid ;
            high = mid - 1 ;
        }
        else{
            low = mid + 1 ;
        }
    }
    return ans ;
} 
int countSmallEqual(vector<vector<int>>& matrix , int n , int m , int x){
    int cnt = 0 ;
    for(int i = 0 ; i < n ; i++){
        cnt += upperBound(matrix[i] , x , m) ;
    }
    return cnt ;
}
int median(vector<vector<int>>& matrix ){
    int n = matrix.size() ;
    int m = matrix[0].size() ;
    int low = matrix[0][0] ;
    int high = matrix[0][m-1] ;

    while(low < high){
        int mid = low + (high - low) / 2 ;
        int count = countSmallEqual(matrix , n , m , mid) ;
        if(count < (n*m + 1) / 2)
             low = mid + 1 ;
        else 
            high = mid ;
    } 
    return low ;
}





int main(){
    int n;
    cout << "Enter the number of rows in the array : ";
    cin >> n;

    int m;
    cout << "Enter the number of columns in the array : ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter the elements in the array :" << endl;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << "Enter the element at [" << i << "][" << j << "] : ";
            cin >> matrix[i][j];
        }
    }
    cout << endl ;
    
    // int target ;         // Searching element in the matrix 
    // cout << "Enter the number of be searched in the matrix : " ;
    // cin >> target ;


    // cout << "Row with maximum number of ones is : " << rowWithMax_1s(matrix , n , m) ;

    // bool result = searchMatrix(matrix , target) ;
    // if(result == true){
    //     cout << "Searched element exists in the matrix " ;
    // }
    // else{
    //     cout << "Searched element is not in the matrix " ;
    // }

    // bool result = SearchMatrix(matrix , target) ;
    // if(result == true ){
    //     cout << "Searched element exists in the matrix " ;
    // }
    // else{
    //     cout << "Searched element is not in the matrix " ;
    // }

    // vector<int> ans = peak(matrix) ;
    // cout << "Peak element occurs at : " << ans[0] << " , " << ans[1] ;

    // cout << "The Median of the given Matrix is : " << median(matrix) ;

    return 0 ;
}