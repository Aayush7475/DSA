#include<bits/stdc++.h>
using namespace std;










int main() {

    int n;
    cout << "Enter the number of rows in the array : ";
    cin >> n;

    int m;
    cout << "Enter the number of columns in the array : ";
    cin >> m;

    vector<vector<int>> nums(n, vector<int>(m));

    cout << "Enter the elements in the array :" << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << "Enter the element at [" << i << "][" << j << "] : ";
            cin >> nums[i][j];
        }
    }

    cout << "\n Array is: \n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}