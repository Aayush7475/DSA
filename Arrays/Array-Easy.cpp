
#include<bits/stdc++.h>
using namespace std ;

// Largest Element in the array ->
void LE(int n , int arr[]){
    int largest = arr[0];
    for(int i = 1 ; i < n ; i++){
        if(arr[i] > largest){
            largest = arr[i] ;
        }
    }
    cout << "Largest Element in the array is : " << largest ;
}

// Second largest Element in the array - Method 1 ->
void SLE_1(int n , int arr[]){
    int largest = arr[0] ;
    for(int i = 1 ; i < n ; i++){
        if(arr[i] > largest){
            largest = arr[i] ;
        }
    }
    int S_largest = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > S_largest && arr[i] != largest){
            S_largest = arr[i];
        }
    }
    cout << "Second Largest element in the array is : " << S_largest;
}

//  Second largest Element in the array - Method 2 ->
void SLE_2(int n , int arr[]){
    int largest = arr[0];
    int S_largest = INT_MIN ;   // If there are negative number in the array , take S_largest element as INT_MIN 

    for(int i = 0 ; i < n ; i++){
        if(arr[i] > largest){
            S_largest = largest ;
            largest = arr[i]; 
        }
    }
    cout << "the second largest Element in the array is : " << S_largest ;
}

// Check whether given array is sorted or not ->
int Sorted(int n , int arr[]){
    for(int i = 1 ; i < n ; i++){
        if(arr[i] >= arr[i-1]){
        
        }
        else{
            return false;
        }
    }
    cout << " Array is sorted " ;
}

// Count number of unique elements and delete the duplicate ones - Method 1 ->
int unique_1(int n , int arr[]){
    set<int> st;

    for(int i = 0 ; i < n ; i++){
        st.insert(arr[i]);
    }
    cout << "Unique elements are : ";

    for(auto it : st){
        cout << it << " ";
    }

    cout << "\nNumber of unique elements are : " << st.size();

}

// Count number of unique elements and delete the duplicate ones - Method 2 ->
int unique_2(int n , int arr[]){
    int i = 0 ;
    
    for(int j = 1 ; j < n ; j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j] ;
            i++ ;
        }
    }
    return i+1 ;
}

// Rotating the array left by one step ->
int One_left(int n , int arr[]){
    int temp = arr[0];
    for(int i = 1 ; i < n ; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp ;
}

// Rotating the array by K steps ->
int K_left(int n , int arr[] , int k){

    int a = k%n ;
    int temp[a];

    for(int i = 0  ; i < n ; i++){
        temp[i] = arr[i];
    }

    for(int i = a ; i < n ; i++){
        arr[i-a] = arr[i];
    }

    for(int i = 0 ; i < n ; i++){
        arr[n-a+i] = temp[i];
    }

    cout << "Array after rotating k steps is : ";
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " ;
    }
}

// Putting all zeroes at the end - Method 1 ->
int Zeroes_1(int n , int arr[]){
        vector<int> temp ;
        
        for(int i = 0 ; i < n ; i++){
            if(arr[i] != 0){
                temp.push_back(arr[i]);
            }
        }
        
        for(int i = 0 ; i < temp.size() ; i++){
            arr[i] = temp[i] ;
        }
        
        int nz = temp.size();
        for(int i = nz ; i < n ; i++){
            arr[i] = 0;
        }
        
        for(int i = 0 ; i < n ; i++){
            cout << arr[i]<< " ";
        }
    }

// Putting all zeroes at the end - Method 2 ->
int Zeroes_2(int n , int arr[]){
    int i = 0 ;
    int j = -1 ;

    for(int i = 0 ; i < n ; i++){
        if(arr[i] == 0){
            j = i ;
            break ;
        }
    }

    for(int i = j+1 ; i < n ; i++){
        if(arr[i] != 0){
            swap(arr[i] , arr[j]);
            j++ ;
        }
    }

    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }

}

// Linear Search ->
int LS(int n, int arr[] , int num){
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == num){
            return i ;
        }
    }
    return -1;
}

// Union of two sorted arrays - Method 1 ->
vector<int> Union_1(int n1  , int n2 , int a[] , int b[]){
    set<int> st ;

    for(int i = 0 ; i < n1 ; i++){
        st.insert(a[i]) ;
    }
    for(int i = 0 ; i < n2 ; i++){
        st.insert(b[i]) ;
    }
    
   vector<int> uni ; 

   for(auto it : st){
    uni.push_back(it);
   }
   return uni ;

}

// Union of two sorted arrays - Method 2 ->
vector<int> Union_2(vector<int> a , vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    int i = 0 ;
    int j = 0 ;
    vector<int> UnionArr ;

    while(i < n1 && j < n2){
        if(a[i] <= b[j]){
            if(UnionArr.size() == 0 || UnionArr.back() != a[i]){
                UnionArr.push_back(a[i]);
            }
            i++ ;
        }
        else{
            if(UnionArr.size() == 0 || UnionArr.back() != b[j]){
                UnionArr.push_back(b[j]);
            }
            j++ ;
        }
    }

    while(i < n1){
        if(UnionArr.size() == 0 || UnionArr.back() != a[i]){
                UnionArr.push_back(a[i]);
            }
            i++ ;
    }

    while(j < n2){
        if(UnionArr.size() == 0 || UnionArr.back() != b[j]){
                UnionArr.push_back(b[j]);
            }
            j++ ;
    }
    return UnionArr ;
}

// Intersection of two sorted arrays - Method 1 -> 
vector<int> Intersection_1(int n1 , int n2 ,vector<int> &a , vector<int> &b){
    vector<int> ans ;
    int vis[n2] = {0};

    for(int i = 0 ; i < n1 ; i++){
        for(int j = 0 ; j < n2 ; j++){
            if(a[i] == b[j] && vis[j] == 0){
                ans.push_back(a[i]);
                vis[j] = 1 ;
                break ;
            }
            if(b[j] > a[i]){
                break ;
            }
        }
    }
    return ans ;

}

// Intersection of two sorted arrays - Method 1 -> 
vector<int> Intersection_2(int n1 , int n2 , vector<int> a , vector<int> b){
    int i = 0 ;
    int j = 0 ;
    vector<int> ans ;
    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            i++ ;
        }
        else if(a[i] > b[j]){
            j++ ;
        }
        else{
            ans.push_back(a[i]);
            i++ ;
            j++ ;
        }
    }
    return ans ;
}

// Finding Missing Number ->
int MissingNum(int n , int arr[]){
    int sum = (n*(n+1))/2;
    int Asum = 0;
    for(int i = 0 ; i < n-1 ; i++){
        Asum = Asum + arr[i] ;
    }
    int Missing_Number = sum - Asum ;
    return Missing_Number ;
}

// Maximum consecutive ones ->
int Ones(int n , int arr[]){
    int maxi = 0 ;
    int cnt = 0 ;
    for(int i = 0 ; i < n-1 ; i++){
        if(arr[i] == 1){
            cnt ++ ;
            maxi = max(maxi , cnt);
        }
        else{
            cnt = 0 ;
        }
    } 
    return maxi ;
} 

// Element appearing once in an array containing all elements twice ->
int Once(int n , int arr[]){
    for(int i = 0 ; i < n ; i++){
        int num = arr[i];
        int cnt = 0 ;
        for(int j = 0 ; j < n ; j++){
            if(arr[j] == num){
                cnt ++;
            }
        }
        if(cnt == 1){
            return num ; 
        }
    }
}

// Longest Sub Array with sum -> 
int LongestSubArray(vector<int> arr , long long k ){
    map<long long , int> PreSumMap ;
    long long sum = 0 ;
    int maxLen = 0 ;

    for(int i = 0 ; i < arr.size() ; i++){
        sum = sum + arr[i] ;

        if(sum == k){
            maxLen = max(maxLen , i+1);
        }

        long long rem = sum - k ;

        if(PreSumMap.find(rem) != PreSumMap.end()){
            int len = i - PreSumMap[rem];
            maxLen = max(maxLen , len);
        }

        if(PreSumMap.find(sum) == PreSumMap.end()){
            PreSumMap[sum] = i ;
        }
    }
    return maxLen ;
}

// 2 sum problem and returning numbers ->
bool S_1(int n , int target , vector<int> arr){
    sort(arr.begin() , arr.end());
    int left = 0 ;
    int right = n-1 ;
    while(left < right){
        if(arr[left] + arr[right] == target){
         cout << arr[left] << " + " << arr[right] << " = " << target ;
         return true ;
        }
        else if(arr[left] + arr[right] < target) left ++ ;
        else right -- ;
    }
    return false ;
}

// 2 sum problem and returning indices ->
vector<int> S_2(int n , int target , vector<int> arr){
    map<int , int> mpp;
    for(int i = 0 ; i < n ; i++){
        int a = arr[i];
        int more = target - a ;
        if(mpp.find(more) != mpp.end()){
            cout << mpp[more] << " & " << i ;
        }
        mpp[a] = i ;
    }
    return {-1 , 1};
}

// Adding 1 to the largest number formed by the array ->
vector<int> plusOne(vector<int>& arr){
    for(int i = arr.size() - 1 ; i >= 0 ; i--){
        if(arr[i] < 9){
            arr[i]++ ;
            return arr ;
        }
        arr[i] = 0 ;
    }
    arr.insert(arr.begin() , 1) ;
    return arr ;
}


// NORMAL :-

int main(){
    int n ; 
    cout << "Enter the number of elements in the array : ";
    cin >> n ;
    vector<int> arr(n);
    // int arr[n] ;
    cout << "Enter the elements in the array : " << endl ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << endl ;
    
    // LE(n , arr);
    
    // SLE_1(n , arr);
    // SLE_2(n , arr);
    
    // Sorted(n , arr);
    
    // unique_1(n , arr);
    
    // int k = unique_2(n , arr);
    // cout << "Unique elements are : ";
    // for(int i = 0; i < k; i++){
        //     cout << arr[i] << " ";
        // }
        // cout << "\nNumber of unique elements are : " << k ;
        
    // One_left(n, arr);
    // for(int i = 0 ; i < n ; i++){
        //     cout << arr[i] << " ";
        // }
            
    // int k ;
    // cout << "Enter the numbers of steps the array should be rotated : ";
    // cin >> k;
    // K_left(n , arr , k);
                    
    // Zeroes_1(n , arr);
    // Zeroes_2(n , arr);
            
    // int num ; 
    // cout << "Enter the number to be searched : ";
    // cin >> num ;     // int index = LS(n, arr, num);
    // if(index != -1){
            //     cout << "Element found at index: " << index;
            // }
        // else{
            //     cout << "Element not found";
            // }
        
    // cout << "Missing Number is : " << MissingNum(n , arr) << " " ;
        
    // cout << "Maximum number of consecutive ones are : " << Ones(n , arr);
        
    // cout << "Element appearing once is : " << Once(n , arr);
        
    // long long k ;
    // cout << "Enter the target sum : ";
    // cin >> k ;
    // cout << "Length of longest SubArray is : " << LongestSubArray(arr , k); 

    // int target ;
    // cout << "Enter the target element : ";
    // cin >> target ;
    // S_1(n , target , arr);
    // S_2(n , target , arr);

    //  Adding 1 to the largest number formed by the array 
    // vector<int> ans = plusOne(arr);
    // cout << "After adding 1: ";
    // for(int i = 0; i < ans.size(); i++) {
    //     cout << ans[i] << " ";
    // }

    // return 0 ;
        
    }

    // UNION & INTERSECTION :-
    // int main(){
    //     int n1 ; 
    //     int n2 ;
    //     cout << "Enter the number of elements in the 1st array : "  ;
    //     cin >> n1 ;
    //     cout << "Enter the number of elements in the 2nd array : "  ;
    //     cin >> n2 ;
    //     int a[n1];
    //     int b[n2];
    //     cout << "Enter the elements in the 1st array : " << endl;
    //     for(int i = 0 ; i < n1 ; i++){
    //         cin >> a[i];
    //     }
    //     cout << "Enter the elements in the 2nd array : " << endl;
    //     for(int i = 0 ; i < n2 ; i++){
    //         cin >> b[i];
    //     }
    //     // vector<int> result = Union_1(n1 , n2 , a , b);
    //     // vector<int> v1(a, a + n1);
    //     // vector<int> v2(b, b + n2);
    //     // vector<int> result = Union_2(v1, v2);
    //     // vector<int> v1(a, a + n1);
    //     // vector<int> v2(b, b + n2);
    //     // vector<int> result = Intersection_1(n1 , n2 , v1 , v2);
    //     // vector<int> v1(a, a + n1);
    //     // vector<int> v2(b, b + n2);
    //     // vector<int> result = Intersection_2(n1 , n2 , v1 , v2);
    //     for(int x : result){
    //         cout << x << " ";
    //     }
    //     return 0 ;