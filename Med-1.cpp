#include<bits/stdc++.h>
using namespace std ;

// Sorting array containing 0 , 1 , 2 by DUTCH NATIONAL FLAG ALGORITHM ->
void SortArray(vector<int> &arr , int n){
    int low = 0 ;
    int mid = 0 ; 
    int high = n-1 ;

    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low] , arr[mid]);
            low ++ ;
            mid ++ ;
        }
        else if(arr[mid] == 1){
            mid ++ ;
        }
        else{
            swap(arr[mid] , arr[high]);
            high -- ;
        }
    }
}

// Majority Element (Element > N/2) ->
int ME_1(vector<int> arr){
    map<int , int> mpp;
    for(int i = 0 ; i < arr.size() ; i++){
        mpp[arr[i]]++ ;
    }
    for(auto it : mpp){
        if(it.second > (arr.size()/2)){
            return it.first ;
        }
    }
    return -1 ;
}

// Majority Element (Element > N/2) by MOORE'S VOTING ALGORITHM -> 
int ME_2(vector<int> arr){
    int cnt = 0 ;
    int el ;
    for(int i = 0 ; i < arr.size() ; i++){
        if(cnt == 0){
            cnt = 1  ;
            el = arr[i] ;
        }
        else if(arr[i] == el){
            cnt ++ ;
        }
        else{
            cnt -- ;
        }
    }
    int cnt_1 = 0 ;
    for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i] == el){
            cnt_1 ++ ;
        }
        if(cnt_1 > arr.size()/2){
            return el ;
        }
    }
    return -1 ;
}

// Maximum SubArray Sum ->
int Max_1(int n , vector<int> arr){
    int maxi = INT_MIN ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            int sum = 0 ;
            for(int k = i ; k <= j ; i++){
                sum = sum + arr[k];
            }
            maxi = max(maxi , sum);
        }
    }
    return maxi ;
}

// Maximum SubArray Sum ->
int Max_2(int n , vector<int> arr){
    int sum = 0 ; 
    int maxi = INT_MIN ;

    for(int i = 0 ; i < n ; i++){
        sum = sum + arr[i];
        maxi = max(maxi , sum);
        if(sum < 0){
            sum = 0 ;
        }
    }
    return maxi ;
}

// Buy and Sell Stocks -> 
int BS(int n , vector<int> arr){
    int profit = 0;
    int mini = arr[0];
    for(int i = 0 ; i < n ; i++){
        int cost = arr[i]-mini ;
        profit = max(profit , cost);
        mini = min(mini , arr[i]);
    }
    return profit;
}

// Re-arranging array elements (equal in number) by signs ->
vector<int> Arrange(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n,0);
    int PosIndex = 0 ;
    int NegIndex = 1 ;

    for(int i = 0 ; i < n ; i++){
        if(arr[i] < 0){
            ans[NegIndex] = arr[i];
            NegIndex += 2 ;
        }
        else{
            ans[PosIndex] = arr[i];
            PosIndex += 2 ;
        }
    }
    return ans ; 
}

// Re-arranging array elements (unequal in number) by signs ->
vector<int> ReArrange(vector<int> arr){
    vector<int> pos ;
    vector<int> neg ;

    for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i] > 0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }

    if(pos.size() > neg.size()){
        for(int i = 0 ; i < neg.size() ; i++){
            arr[2*i] = pos[i] ;
            arr[2*i+1] = neg[i];
        }

        int index = neg.size() * 2 ;
        for(int i = neg.size() ; i < pos.size() ; i++){
            arr[index] = pos[i];
            index ++ ;
        }
    }

    else{
        for(int i = 0 ; i < pos.size() ; i++){
            arr[2*i] = pos[i] ;
            arr[2*i+1] = neg[i];
        }

        int index = pos.size() * 2 ;
        for(int i = pos.size() ; i < neg.size() ; i++){
            arr[index] = neg[i];
            index ++ ;
        }
    }
    return arr ;
}

// Returning next permutation using STL ->
vector<int> NxtPermutation(vector<int> arr){
    next_permutation(arr.begin() , arr.end());
    return arr ;
}

// Returning next permutation ->
vector<int> NextPermutation(vector<int> arr){
    int index = -1 ;
    int n = arr.size() ;
    for(int i = n-2 ; i >= 0 ;  i--){
        if(arr[i] < arr[i+1]){
            index = i ; 
            break ; 
        }
    }
    if(index == -1){
        reverse(arr.begin() , arr.end());
        return arr ;
    }
    for(int i = n-1 ; i > index; i--){
        if(arr[i] > arr[index]){
            swap(arr[i] , arr[index]);
            break ;
        }
    }
    reverse(arr.begin() + index + 1 , arr.end());
    return arr ;
}

// Returning leaders(those elements whose rhs is smaller than them) ->
vector<int> Leader(vector<int> arr){
    vector<int> result ;
    for(int i = 0 ; i < arr.size() ; i++){
        bool leader = true ; 
        for(int j = i+1 ; j < arr.size() ; j++){
            if(arr[j] > arr[i]){
                leader = false ;
                break ;
            }
        }
        if(leader == true){
            result.push_back(arr[i]);
        }
    }
    sort(result.begin() , result.end());
    return result ;
}

// Longest Consecutive SubArray ->
int Longest(vector<int> arr){
    sort(arr.begin() , arr.end());
    int n = arr.size();
    int cnt = 0 ;
    int largest = 1 ; 
    int lastSmallest = INT_MIN ;
    for(int i = 0 ; i < n ; i++){
        if(arr[i]-1 == lastSmallest){
            cnt = cnt + 1;
            lastSmallest = arr[i] ;
        }
        else if(lastSmallest != arr[i]){
            cnt = 1 ;
            lastSmallest = arr[i] ;
        }
        largest = max(largest , cnt) ;
    }
    return largest ;
}

// Counting SubArray sum equal to k ->
int SubArraySum(vector<int> arr , int k){
    map<int,int> mpp;
    mpp[0] = 1 ;
    int PreSum = 0 ;
    int cnt = 0 ;

    for(int i = 0 ; i < arr.size() ; i++){
        PreSum += arr[i];
        int remove = PreSum - k ;
        cnt += mpp[remove] ;
        mpp[PreSum] += 1 ;
    }
    return cnt ;
}





int main(){
    int n ;
    cout << "Enter the number of elements in the array : ";
    cin >> n ;

    vector<int> arr(n);
    cout << "Enter the elements in the array : " << endl;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }

    // SortArray(arr , n);
    // for(int i = 0 ; i < n ; i++){
    //     cout << arr[i] << " ";
    // }
    
    // int ans = ME_1(arr);
    // if(ans != -1){
    //     cout << "Majority Element: " << ans << endl;
    // }
    // else{
    //     cout << "No Majority Element Found" << endl;
    // }

    // int ans = ME_2(arr);
    // if(ans != -1){
    //     cout << "Majority Element : " << ans << endl;
    // }
    // else{
    //     cout << "No Majority Element Found" << endl;
    // }

    // int ans = Max_1(n , arr);
    // cout << " Maximum Sub Array Sum = " << ans ;

    // int ans = Max_2(n , arr);
    // cout << "Maximum Sub Array Sum = " << ans ;

    // int ans = BS(n , arr);
    // cout << "Maximum profit is " << ans ;

    // vector<int> result = Arrange(arr);
    // cout << "Array after arranging will be : ";
    // for(int i = 0; i < result.size(); i++){
    //     cout << result[i] << " ";
    // }

    // vector<int> result = ReArrange(arr);
    // cout << "Array after arranging will be : ";
    // for(int i = 0; i < result.size(); i++){
    //     cout << result[i] << " ";
    // }

    // vector<int> result = NxtPermutation(arr);
    // cout << "Next Pemutation will be : " ;
    // for(int i=0 ; i < result.size() ; i++){
    //     cout << result[i] << " " ;
    // }

    // vector<int> result = NextPermutation(arr);
    // cout << "Next Pemutation will be : " ;
    // for(int i=0 ; i < result.size() ; i++){
    //     cout << result[i] << " " ;
    // }

    // vector<int> result = Leader(arr);
    // cout << "Leaders are : " ;
    // for(int i = 0 ; i < result.size() ; i++){
    //     cout << result[i] << " " ;
    // }

    // int ans = Longest(arr);
    // cout << "Longest Consecutive Sub Array : " << ans ;
    
    int k ;
    cout << "Enter the value of K : ";
    cin >> k ;
    int ans = SubArraySum(arr , k );
    cout << "Number of Sub Arrays with sum k is : " << ans;

    return 0 ;
}