#include <bits/stdc++.h>
using namespace std;

// Function to set entire row and column to 0 if an element in the matrix is 0 - Method 1 ->
void setZeroes_1(vector<vector<int>> &matrix){

    int m = matrix.size();    // rows
    int n = matrix[0].size(); // columns

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (matrix[i][j] == 0)
            {
                for (int col = 0; col < n; col++)
                {
                    if (matrix[i][col] != 0)
                        matrix[i][col] = -1;
                }
                for (int row = 0; row < m; row++)
                {
                    if (matrix[row][j] != 0)
                        matrix[row][j] = -1;
                }
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 0;
        }
    }
}

// Function to set entire row and column to 0 if an element in the matrix is 0 - Method 2 ->
void setZeroes_2(vector<vector<int>> &matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> row(m, 0);
    vector<int> col(n, 0);

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (row[i] || col[j]){
                matrix[i][j] = 0;
            }
        }
    }
}

// Rotating Array by 90 degree ->
void Rotating(vector<vector<int>> &matrix){
    int n = matrix.size();
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = i+1 ; j < n ; j++){
            swap(matrix[i][j] , matrix[j][i]);
        }
    }
    for(int i = 0 ; i < n ; i++){
        reverse(matrix[i].begin() , matrix[i].end());
    }
}

// Spiral Order Matrix ->
vector<int> Spiral(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int left = 0 , right = m-1 ;
    int top = 0 , bottom = n-1 ;
    vector<int> ans ;

    while(left <= right && top <= bottom){

        for(int i = left ; i <= right ; i++){
            ans.push_back(matrix[top][i]);
        }
        top ++ ;

        for(int i = top ; i <= bottom ; i++){
            ans.push_back(matrix[i][right]);
        }
        right -- ;

        if(top <= bottom){
            for(int i = right ; i >= left ; i++){
                ans.push_back(matrix[bottom][i]);
            }
            bottom -- ;
        }

        if(left <= right){
            for(int i = bottom ; i >= top ; i++){
                ans.push_back(matrix[i][left]);
            }
            left ++ ;
        }
    }
    return ans ;
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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Enter the element at [" << i << "][" << j << "] : ";
            cin >> matrix[i][j];
        }
    }
    cout << endl ;

    // setZeroes_1(nums);

    // setZeroes_2(nums);

    // Rotating(matrix);


    cout << "Array is: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}