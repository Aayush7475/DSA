#include<bits/stdc++.h>
using namespace std ;

// Searching X in the array ITERATIVE METHOD ->
int BS1(vector<int>& nums ,  int target){
    int n = nums.size() ;
    int low = 0 ;
    int high = n-1 ;
    while(low <= high){
        int mid = (low + high) / 2 ;
        if(nums[mid] == target) return mid ;
        else if(nums[mid] < target) low = mid + 1 ;
        else high = mid - 1 ;
    }
    return -1;
}

// Searching X in the array RECURSIVE METHOD ->
int search(vector<int>& nums , int low , int high , int target){
    if(low > high) return -1 ;
    int mid = (low + high) / 2 ;
    if(nums[mid] == target){
        return mid ;
    }
    else if(nums[mid] < target){
        return search(nums , mid+1 , high , target);
    }
    else{
        return search(nums , low , mid-1 , target);
    }
}
int BS2(vector<int>& nums , int target){
    return search(nums , 0 , nums.size()-1 , target);
}
    
// Lower Bound (Upper bound me sirf ">" index hoga ">=" nhi)->
int LowerBound(vector<int>& nums , int target){
    sort(nums.begin() , nums.end());
    int n = nums.size();
    int low = 0 ; 
    int high = n-1 ;
    int ans = n ;
    while(low < high){
        int mid = (low + high) / 2 ;
        if(nums[mid] >= target){
            ans = nums[mid] ;
            high = mid - 1 ;   // Look for more smaller index 
        }
        else{
            low = mid + 1 ;
        }
    }
    return ans ;
}

// Floor -> Largest element <= target 
// Ceil -> Smallest element >= target [LOWER BOUND]
int floor(vector<int>& nums , int target){
    sort(nums.begin() , nums.end());
    int n = nums.size() ;
    int low = 0 ;
    int high = n-1 ;
    int ans = -1 ;
    while(low <= high){
        int mid = (low + high) / 2 ;
        if(nums[mid] <= target){
            ans = nums[mid] ;
            low = mid + 1 ;
        }
        else{
            high = mid - 1 ;
        }
    }
    return ans ;
}

// Returning index of the first and the last occurence ->
int LowerBound(vector<int>& nums , int target){
    int n = nums.size() ;
    int low = 0 ; 
    int high = n-1 ;
    int ans = n ;
    while(low <= high){
        int mid = (low + high) / 2 ;
        if(nums[mid] >= target){
            ans = mid ;
            high = mid - 1 ;
        }
        else{
            low = mid + 1 ;
        }
    }
    return ans ;
}
int UpperBound(vector<int>& nums , int target){
    int n = nums.size() ;
    int low = 0 ; 
    int high = n-1 ;
    int ans = n ;
    while(low <= high){
        int mid = (low + high) / 2 ;
        if(nums[mid] > target){
            ans = mid ;
            high = mid - 1 ;
        }
        else{
            low = mid + 1 ;
        }
    }
    return ans ;
}
vector<int> Occurence(vector<int>& nums , int target){
    int lb = LowerBound(nums , target) ;
    if(lb == nums.size() || nums[lb] != target){
        return {-1 , -1};
    }
    else{
        return  {lb , UpperBound(nums , target) - 1 };
    }
}

// Searching element in a rotated array ->
int search(vector<int>& nums , int target){
    int n = nums.size() ;
    int low = 0 ;
    int high = n-1 ;
    while(low <= high){
        int mid = (low + high) / 2 ;
        if(nums[mid] == target) return mid ;
        
        if(nums[low] < nums[mid]){
            if(target >= nums[low] && target <= nums[mid]){
                high = mid - 1 ;
            }
            else{
                low = mid + 1 ;
            }
        }
        else{
            if(target >= nums[mid] && target <= nums[high]){
                low = mid + 1 ;
            }
            else{
                high = mid - 1 ;
            }
        }
    }
    return -1 ;
}



int main(){
    int n ;
    cout << "Enter the number of elements in the array : "  ;
    cin >> n ;

    vector<int> nums(n);
    cout << "Enter the elements in the array : " << endl ;
    for(int i = 0 ; i < n ; i++){
        cin >> nums[i]  ;
    }

    int target ;
    cout << "Enter the target element to be searched : ";
    cin >> target ;

    // cout << "Searched element " << target << " is at : " << BS1(nums , target);
    
    // cout << "Searched element " << target << " is at : " << BS2(nums , target);

    // cout << "Lower Bound will be : " << LowerBound(nums , target);

    // cout << "Floor will be : " << floor(nums , target) ;

    // cout << "Index of the first and last occurence of the target element is : " ;
    // vector<int> result = Occurence(nums , target);
    // cout << result[0] << " & " << result[1] << endl;


return 0 ;
}