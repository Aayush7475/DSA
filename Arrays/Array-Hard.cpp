#include<bits/stdc++.h>
using namespace std ;

// Majority Element(Element > N/3) by MOORE'S VOTING ALGORITHM ->
vector<int> majorityElement2(vector<int> nums){
    int cnt1 = 0 ;
    int cnt2 = 0 ;
    int el1 = INT_MIN ;
    int el2 = INT_MIN ;
 
    for(int i = 0 ; i < nums.size() ; i++){
        if(cnt1 == 0 && nums[i] != el2){
            cnt1 = 1 ;
            el1 = nums[i] ;
        }
        else if(cnt2 == 0 && nums[i] != el1){
            cnt2 = 1 ;
            el2 = nums[i] ;
        }
        else if(nums[i] == el1){
            cnt1 ++ ;
        }
        else if(nums[i] == el2){
            cnt2 ++ ;
        }
        else{
            cnt1 -- , cnt2 -- ;
        }
    }

    vector<int> ls ;
    cnt1 = 0 , cnt2 = 0 ;

    for(int i = 0 ; i < nums.size() ; i++){
        if(el1 == nums[i]){
            cnt1 ++ ;
        }
        if(el2 == nums[i]){
            cnt2 ++ ;
        }
    }

    int mini = (int)(nums.size() / 3) + 1 ;
    if(cnt1 >= mini){
        ls.push_back(el1);
    }
    if(cnt2 >= mini){
        ls.push_back(el2);
    }
    sort(ls.begin() , ls.end()) ;
    return ls ;
}

// 3 Sum Problem Method 1 ->
vector<vector<int>> triplet(int n, vector<int> &nums) {
    set<vector<int>> st;

    for(int i = 0; i < n; i++) {
        unordered_set<int> hashset;

        for(int j = i + 1; j < n; j++) {
            int third = -(nums[i] + nums[j]);

            if(hashset.find(third) != hashset.end()) {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            hashset.insert(nums[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// 3 Sum Problem Method 2 ->
vector<vector<int>> triplets(int n , vector<int> nums){
    vector<vector<int>> ans;
    sort(nums.begin() , nums.end());
    for(int i = 0 ; i < n ; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue ;
        int j = i + 1 ;
        int k = n - 1 ;
        while(j<k){
            int sum = nums[i] + nums[j] + nums[k] ;
            if(sum < 0){
                j++ ;
            }
            else if(sum > 0){
                k-- ;
            }
            else{
                vector<int> temp = {nums[i] , nums[j] , nums[k]};
                ans.push_back(temp);
                j++ ;
                k-- ;
                while(nums[j] == nums[j-1]){
                    j++ ;
                }
                while(nums[k] == nums[k+1]){
                    k-- ;
                }
            }
        }
    }
    return ans ;
}

// 3 Sum closet ->
int ClosetSum(vector<int> nums , int target){
    sort(nums.begin() , nums.end());

    int n = nums.size() ;
    int closetSum = nums[0] + nums[1] + nums[2] ;

    for(int i = 0 ; i < n-2 ; i++){
        int left = i+1 ;
        int right = n-1 ;

        while(left < right){
            int currentSum = nums[i] + nums[left] + nums[right] ;

            if(abs(currentSum - target) < abs(closetSum - target)){
                closetSum = currentSum ;
            }

            if(currentSum == target) return currentSum ;

            else if(currentSum < target) left ++ ;

            else right -- ;
        }
    }
    return closetSum ;
}



// 4 Sum Problem Method 1 ->
vector<vector<int>> fourth(int target , vector<int> nums){
    set<vector<int>> st ;
    int n = nums.size() ;

    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            set<long long> hashset ;
            for(int k = j+1 ; k < n ; k++){
                long long sum = (long long) nums[i] + nums[j] + nums[k] ;
                long long fourth = target - sum ;
                if(hashset.find(fourth) != hashset.end()){
                    vector<int> temp = {nums[i] , nums[j] , nums[k] , (int) fourth} ;
                    sort(temp.begin() , temp.end());
                    st.insert(temp) ;
                }
                hashset.insert(nums[k]);
            }
        } 
    }
    vector<vector<int>> ans(st.begin() , st.end()); 
    return ans ;
} 

// 4 Sum Problem Method 2 ->
vector<vector<int>> forth(int target , vector<int> nums){
    vector<vector<int>> ans ;
    int n = nums.size() ;
    sort(nums.begin() , nums.end());

    for(int i = 0 ; i < n ; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue ;
        for(int j = i+1 ; j < n ; j++){
            if(j != (i+1) && nums[j] == nums[j-1]) continue ;
            int k = j+1 ;
            int l = n-1 ;
            while(k<l){
                long long sum = nums[i] + nums[j] + nums[k] + nums[l] ;
                if(sum == target){
                    vector<int> temp = {nums[i] , nums[j] , nums[k] ,nums[l]};
                    ans.push_back(temp);
                    k++ ;
                    l-- ;
                    while(k < l && nums[k] == nums[k-1]) k++; 
                    while(k < l && nums[l] == nums[l+1]) l--; 
                }
                else if(sum < 0){
                    k++ ;
                }
                else{
                    l-- ;
                }
            }
        }
    }
    return ans ;
}

// Longest SubArray with sum equals to Zero ->
int SubArray(int n , vector<int> nums){
    map<int , int> mpp ;
    int maxi = 0 ;
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        sum = sum + nums[i] ;
        if(sum == 0){
            maxi = i+1 ;
        }
        else{
            if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi , i-mpp[sum]);
            }
            else{
                mpp[sum] ;
            }
        }
    }
    return maxi ;
}

// Number of SubArray with XOR equal to K ->
int XOR(int k , vector<int> nums){
    int cnt = 0 ;
    int xr = 0 ;
    map<int , int> mpp;
    mpp[xr]++ ;
    for(int i = 0 ; i < nums.size() ; i++){
        xr = xr^nums[i];
        int x = xr^k;
        cnt += mpp[x] ;
        mpp[xr]++ ;
    }
    return cnt ;
}

// Merge OverLapping Intervals Method 1 ->
vector<vector<int>> Merge(vector<vector<int>> arr){
    sort(arr.begin() , arr.end());
    int n = arr.size();
    vector<vector<int>> ans ;

    for(int i =  0 ; i < n ; i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(! ans.empty() && end <= ans.back()[1]){
            continue ;
        }
        for(int j = i+1 ; j < n ; j++){
            if(arr[j][0] <= end){
                end = max(end , arr[j][1]);
            }
            else{
                break ;
            }
        }
        ans.push_back({start,end}) ;
    }
    return ans ;
}

// Merge OverLapping Intervals Method 2 ->
vector<vector<int>> OverLapping(vector<vector<int>> arr){
    sort(arr.begin() , arr.end());
    int n = arr.size() ;
    vector<vector<int>> ans ;

    for(int i = 0 ; i < n ; i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1] ,arr[i][1]);
        }
    }
    return ans ;
}

// Merge Soretd Arrays By SHELL SORTING METHOD ->
void swapIfGreater(int arr1[] ,int arr2[] , int ind1 , int ind2){
    if(arr1[ind1] > arr2[ind2]){
        swap(arr1[ind1] ,arr2[ind2]);
    }
}
void Merging(int arr1[] , int arr2[] , int n , int m){
    int len = (n+m);
    int gap =  (len / 2) + (len % 2);
    while(gap > 0){
        int left = 0 ;
        int right = left + gap ;
        while(right < len){
            // arr1 and arr2 -
            if(left < n && right >= n){
                swapIfGreater(arr1 , arr2 , left , right-n);
            }
            // arr2 and arr2 -
            else if( left >= n){
                swapIfGreater(arr2 , arr2 , left-n , right-n);
            }
            // arr1 and arr1 -
            else{
                swapIfGreater(arr1 ,arr1 , left , right);
            }
            left ++ ;
            right ++ ;
        }
        if(gap == 1) break ;
        gap = (gap / 2) + (gap % 2);
    }
}

// Finding the missing and repeating number Method 1 ->
vector<int> MissingRepeating(vector<int> nums){
    int n = nums.size() ;
    int hash[n+1] = {0} ;
    for(int i = 0 ; i < n ; i++){
        hash[nums[i]]++ ;
    }
    int repeating = -1 , missing = -1 ;
    for(int i = 1 ; i <= n ; i++){
        if(hash[i] == 2){
            repeating = i ;
        }
        else if(hash[i] == 0){
            missing = i ;
        }
        if(repeating != -1 && missing != -1){
            break ;
        }
    }
    cout << "Repeating and Missing Elements are : ";
    return {repeating , missing} ;
}

// Finding the Repeating and Missing number Method 2 ->
vector<int> Finding(vector<int> nums){
    long long n = nums.size() ;
    long long S ;  // x
    long long S2 ; // x^2
    long long SN = (n * (n+1)) / 2 ;                // y
    long long SN2 = (n * (n+1) * (2*n+1)) / 6 ;     // y^2

    for(int i = 0 ; i < n ; i++){
        S += nums[i] ;
        S2 += (long long) nums[i] * (long long) nums[i] ;
    }

    long long val1 = S - SN ;     // x - y
    long long val2 = S2 - SN2 ;   // x^2 - y^2 = (x+y)(x-y)
    val2 = val2 / val1 ;    // x + y 

    long long x = (val1 + val2) / 2 ;
    long long y = x - val1 ;

    return {(int) x , (int) y} ;
}

// Finding the numbers of Reverse Pairs ->
void Merge(vector<int> &nums , int low , int mid , int high){
    int left = low;
    int right = mid+1 ;
    vector<int> temp ;

    while(left <= mid && right <= high){
        if(nums[left] < nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i = low ; i <= high ; i++){
        nums[i] = temp[i-low];
    }
}
int countPairs(vector<int> &nums , int low , int mid , int high){
    int right = mid + 1 ;
    int cnt = 0 ;
    for(int i = low ; i <= mid ; i++){
        while(right <= high && (long long)nums[i] > 2LL*nums[right]){
            right ++ ;
        }
        cnt = cnt + (right - (mid+1)) ;
    }
    return cnt ;
}
int MS(vector<int> &nums , int low , int high ){
    int cnt = 0 ;
    if( low >= high ) return cnt ;

    int mid = (low + high)/2 ;

    cnt += MS(nums, low, mid);
    cnt += MS(nums, mid+1, high);
    cnt += countPairs(nums ,low , mid ,high);
    Merge(nums, low, mid, high);
    return cnt ; 
}
int mergeSort(vector<int> &nums , int n){
    return MS(nums , 0 , n-1);
}







// NORMAL ->
int main(){
    int n ; 
    cout << "Enter the number of elements in the array : ";
    cin >> n ;
    
    vector<int> nums(n);
    cout << "Enter the elements in the array : " << endl;
    for(int i = 0 ; i < n ; i++){
        cin >> nums[i] ;
    }


    // vector<int> result = majorityElement2(nums);
    // cout << "Majority Element is : ";
    // for(int x : result){
    //     cout << x << " ";
    // }

    // vector<vector<int>> result = triplet(n , nums);
    // cout << "Triplets are : " << endl ;
    // for(auto &output :  result){
    //     for(int x : output){
    //         cout << x << " ";
    //     }
    //     cout << endl ;
    // }

    // vector<vector<int>> result = triplets(n , nums);
    // cout << "Triplets are : " << endl ;
    // for(auto &output :  result){
    //     for(int x : output){
    //         cout << x << " ";
    //     }
    //     cout << endl ;
    // }

    // int target ;
    // cout << "Enter the target element : ";
    // cin >> target ;
    // vector<vector<int>> result = fourth(target , nums);
    // cout << "Quads are : " << endl ;
    // for(auto &output :  result){
    //     for(int x : output){
    //         cout << x << " ";
    //     }
    //     cout << endl ;
    // }
    
    // int target ;
    // cout << "Enter the target element : ";
    // cin >> target ;
    // vector<vector<int>> result = forth(target , nums);
    // cout << "Quads are : " << endl ;
    // for(auto &output :  result){
        //     for(int x : output){
            //         cout << x << " ";
            //     }
            //     cout << endl ;
            // }
    // SubArray(n , nums) ;
            
    // int k ;
    // cout << "Enter the value of k : ";
    // cin >> k ;
    // int ans = XOR(k, nums);
    // cout << "Number of subarrays = " << ans << endl;
    
    // vector<int> result = MissingRepeating(nums);
    // for(int x : result){
    //     cout << x << " ";
    // }

    // int cnt = mergeSort(nums, n);
    // cout << "The number of reverse pair is: " << cnt << endl;

    // int target ;
    // cout << "Enter the target element to be searched : " ;
    // cin >> target ;
    // int ans = ClosetSum(nums , target) ;
    // cout << "Closet Sum is : " << ans << endl ;
    

    return 0;

}


// MERGE OVECRLAPPING INTERVALS ->
// int main() {
//     int n;
//     cout << "Enter the number of intervals: ";
//     cin >> n;
//     vector<vector<int>> arr(n, vector<int>(2));
//     cout << "Enter the intervals (start end):\n";
//     for(int i = 0; i < n; i++){
//         cin >> arr[i][0] >> arr[i][1];
//     }
//     vector<vector<int>> result = Merge(arr);
//     vector<vector<int>> result = OverLapping(arr);
//     cout << "Merged intervals:\n";
//     for(auto &interval : result){
//         cout << interval[0] << " " << interval[1] << endl;
//     }
//     return 0;
// }

// MERGE SORTED ARRAYS ->
// int main(){
//     int n ; 
//     cout << "Enter the number of elements in the array 1 : ";
//     cin >> n ;
//     int arr1[n];
//     cout << "Enter the elements in the array 1 : " << endl;
//     for(int i = 0 ; i < n ; i++){
//         cin >> arr1[i] ;
//     }
//     int m ; 
//     cout << "Enter the number of elements in the array 2 : ";
//     cin >> m ;
//     int arr2[m];
//     cout << "Enter the elements in the array 2 : " << endl;
//     for(int i = 0 ; i < m ; i++){
//         cin >> arr2[i] ;
//     }
//     Merging(arr1 , arr2 , n , m) ;
//     cout << "Array 1 : ";
//     for(int i = 0; i < n; i++)
//         cout << arr1[i] << " ";
//     cout << "\nArray 2 : ";
//     for(int i = 0; i < m; i++)
//         cout << arr2[i] << " ";
//     return 0 ;
// }