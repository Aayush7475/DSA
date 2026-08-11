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

// Searching element in a rotated array containing duplicates  ->
int Searching(vector<int>& nums , int target){
    int n = nums.size() ;
    int low = 0 ;
    int high = n-1 ;
    while(low <= high){
        int mid = (low + high) / 2 ;

        if(nums[mid] == target) return mid ;

        if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            low ++ ;
            high -- ;
            continue ;
        }
        
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

// Searching smallest element in the rotated array ->
int Smallest(vector<int>& nums){
    int n = nums.size() ;
    int low = 0 ; 
    int high = n-1 ;
    int ans = INT_MAX ;
    while(low < high){
        int mid = (low + high) / 2 ;

        if(nums[low] <= nums[mid]){
            ans = min(ans , nums[low]);
            low = mid + 1 ;
        }
        else{
            high = mid  ;
            ans = min(ans , nums[mid]);
        }
    }
    return ans ;
}

// Finding the number of times an array is rotated ->
int Rotated(vector<int>& nums){
    int n = nums.size() ;
    int low = 0 ; 
    int high = n-1 ;
    int ans = INT_MAX ;
    int index = -1 ;
    while(low <= high){
        int mid = (low + high) / 2 ;
        if(nums[low] <= nums[mid]){
            if(nums[low] < ans){
                index = low ;
                ans = nums[low] ;
            }
            low = mid + 1 ;
        }
        else{
            if(nums[mid] <= nums[high]){
                index = mid ;
                ans = nums[mid] ;
            }
            high = mid - 1 ;
        }
    }
    return index ;
}

// Finding Single element in the sorted array ->
int Single(vector<int> nums){
    int n = nums.size() ;
    int low = 1 ;
    int high = n-2 ;

    if(n == 1) return nums[0] ;
    if(nums[0] != nums[1]) return nums[0] ;
    if(nums[n-1] != nums[n-2]) return nums[n-1] ;

    while(low <= high){
        int mid = (low + high) / 2 ;

        if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
            return mid ;            // checking whether mid is the single element or not 
        }                          

        if((mid % 2 == 1  && nums[mid] != nums[mid-1]) || (mid % 2 == 0 && nums[mid] != nums[mid+1])){
            low = mid + 1 ;         // eliminate left half 
        }
        else{
            high = mid - 1 ;       // eliminate right half 
        }
    }
    return -1 ;
}

// Finding Peak element in the array ->
int peak(vector<int>& nums){
    int n = nums.size() ;
    int low = 1 ;
    int high = n-2 ;

    if(n == 1) return 0 ;
    if(nums[0] > nums[1]) return 0 ;
    if(nums[n-1] > nums[n-2]) return n-1 ;

    while(low <= high){
        int mid = (low + high) / 2 ;
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
            return mid ;
        }
        else if(nums[mid] > nums[mid-1]){
            low = mid + 1 ;
        }
        else if(nums[mid] > nums[mid+1]){
            high = mid - 1 ;
        }
        else{
            low = mid + 1 ;
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

    // int target ;
    // cout << "Enter the target element to be searched : ";
    // cin >> target ;

    // cout << "Searched element " << target << " is at : " << BS1(nums , target);
    
    // cout << "Searched element " << target << " is at : " << BS2(nums , target);

    // cout << "Lower Bound will be : " << LowerBound(nums , target);

    // cout << "Floor will be : " << floor(nums , target) ;

    // cout << "Index of the first and last occurence of the target element is : " ;
    // vector<int> result = Occurence(nums , target);
    // cout << result[0] << " & " << result[1] << endl;

    // int result = search(nums , target) ;
    // if(result != -1){
    //     cout << "Target found at index : " << result ;
    // }
    // else{
    //     cout << "Target not found" ;
    // }

    // int result = Searching(nums , target) ;
    // if(result != -1){
    //     cout << "Target found at index : " << result ;
    // }
    // else{
    //     cout << "Target not found" ;
    // }
    
    // int result = Smallest(nums) ;
    // cout << "Smallest element in the sorted rotated array is : " ;
    // cout << result ;

    // cout << "Number of times the arary is rotated is : " << Rotated(nums) ;

    // int result = Single(nums) ;
    // if(result != -1){
    //     cout << "Single element in the array is : " << result ; 
    // }
    // else{
    //     cout << "No single element in the array :" ; 
    // }
    
    // int result = peak(nums) ;
    // if(result != -1){
    //     cout << "Peak element in the array is : " << result ; 
    // }
    // else{
    //     cout << "No peak element in the array :" ; 
    // }

return 0 ;

}