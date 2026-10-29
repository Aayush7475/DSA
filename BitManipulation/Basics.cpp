#include<bits/stdc++.h>
using namespace std ;

// Addition of two binary numbers ->
string addBinary(string a , string b){
    int i = a.size() - 1 ;
    int j = b.size() - 1 ;
    int carry = 0 ;
    string ans = "" ;

    while(i >= 0 || j >= 0 || carry){
        int sum = carry ;

        if(i >= 0){
            sum += (a[i] - '0') ;
            i-- ;
        }
        if(j >= 0){
            sum += (b[j] - '0') ;
            j-- ;
        }

        ans += (sum % 2) + '0' ;
        carry = sum / 2 ; 
    }
    reverse(ans.begin() , ans.end()) ;
    return ans ;
}

// Finding non duplicate element / Single Number I ->
int nonDuplicate(vector<int>& nums){
    int ans = 0 ;
    for(auto x : nums){
        ans ^= x ;
    }
    return ans ;
}

// Number is power of two ->
bool isPowerOfTwo(int n){
    if(n <= 0) return false ;
    if((n & (n-1)) == 0) return true ;
    return false ;
}

// Number of set bits (Mehtod 1) ->
int setBits(int n){
    int cnt = 0 ;
    while(n > 0){
        if(n % 2 == 1) cnt++ ;
        n = n / 2 ;
    }
    return cnt ; 
}

// Number of set bits (Brian Kernighan's algorithm) - (Method 2) ->
int hammingWeight(int n){
    int cnt = 0 ;
    while(n > 0){
        n = n & (n-1) ;
        cnt ++ ;
    }
    return cnt ;
}

// Minimum bit flip to convert a number ->
int minBitFlips(int start, int goal){
    int ans = start ^ goal ;
    int cnt = 0 ;
    while(ans > 0){
        if(ans % 2 == 1){
            cnt = cnt + 1 ;
        }
        ans = ans / 2 ;
    }
    return cnt ;
}

// Single Number II ->
int singleNumber(vector<int>& nums){
    int ans = 0 ;
    for(int i = 0 ; i < 32 ; i++){
        int cnt = 0 ;

        for(auto num : nums){
            if((static_cast<unsigned int>(num) >> i) & 1U){
                cnt ++ ;
            }
        }
        if(cnt % 3 != 0){
            ans |= (1U << i) ;
        }
    }
    return ans ;
}

// Single Number III (Method 1) ->
vector<int> singleNumber3(vector<int>& nums){
    int n = nums.size() ;
    map<int , int> mpp ;
    
    for(int i = 0 ; i < n ; i++){
        mpp[nums[i]] ++ ;
    }
    vector<int> ans ;

    for(auto it : mpp){
        if(it.second == 1){
            ans.push_back(it.first) ;
        }
    }
    return ans ;
}

// Single Number III (Method 2) ->
vector<int> singlenumber3_2(vector<int>& nums){
    long long xorr = 0 ;
    for(int i = 0 ; i < nums.size() ; i++){
        xorr = xorr ^ nums[i] ;
    }

    int rightmost = (xorr & xorr-1) & xorr ;
    int b1 = 0 , b2 = 0 ;

    for(int i = 0 ; i < nums.size()-1 ; i++){
        if(nums[i] & rightmost) b1 = b1 ^ nums[i] ;
        else b2 = b2 ^ nums[i] ;
    }
    return {b1 , b2} ;
}

// Divide 2 Numbers ->
int divide(int dividend , int divisor){
    bool sign = true ; 
    if(dividend == divisor) return false ;
    if(dividend >= 0 && divisor < 0) return sign == false ;
    if(dividend < 0 && divisor > 0) return sign == false ;

    long n = abs(dividend) ;
    long d = abs(divisor) ;
    long ans = 0 ;

    while(n >= d){
        int cnt = 0 ;
        while(n >= d << (cnt+1)){
            cnt ++ ;
        }
        ans += (1 << cnt) ;
        n -= (d << cnt) ;
    }
    if(ans == (1 << 31) && sign) return INT_MAX ;
    if(ans == (1 << 31) && sign) return INT_MIN ;
    
    return sign ? ans : -ans ;
}

// Reverse 32 Bits ->
int reverseBits(int n){
    int ans = 0 ;
    for(int i = 0 ; i < 32 ; i++){
        ans = (ans << 1) | (n & 1) ;
        n >>= 1 ;
    }
    return ans ;
}

// Counting Bits ->
vector<int> countBits(int n){
    vector<int> ans(n+1 , 0) ;
    for(int i = 0 ; i <= n ; i++){
        ans[i] = ans[i >> 1] + (i & 1) ;
    }
    return ans ;
}

// Find Target Index After Sorting ->
vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }

// Power of 4 ->
bool isPowerOfFour(int n){
    if(n > 0 && (n & (n-1)) == 0 && (n & 0x55555555)){
        return true ;
    }
    return false ;
    
}

// Binary Watch ->
int countSetBits(int n) {
    int cnt = 0;
    while (n > 0) {
        cnt += (n & 1);
        n >>= 1;
    }

    return cnt;
}
vector<string> watch(int turnedOn){
    vector<string> ans ;
    for(int hour = 0 ; hour < 12 ; hour ++){
        for(int min = 0 ; min < 60 ; min ++){
            int cnt = countSetBits(hour) + countSetBits(min) ;
            if(cnt == turnedOn){
                string formattedtime = to_string(hour) + ":" ;
                if(min < 10){
                    formattedtime += "0" ;
                }
                formattedtime += to_string(min) ;
                ans.push_back(formattedtime) ;
            }
        }
    }
    return ans ;
}

// Converting Binary to Gray Code (Method 1) ->
vector<int> grayCode(int n){
    vector<int> ans = {0} ;
    for(int i = 1 ; i <= n ; i++){
        int add = 1 << (i - 1) ;
        for(int j = ans.size()-1 ; j >= 0 ; j--){
            ans.push_back(ans[j] + add) ;
        }
    }
    return ans ;
}

// Converting Binary to Gray Code (Method 2) ->
vector<int> grayCode2(int n){
    vector<int> ans ;
    for(int i = 0 ; i < (1 << n) ; i++){
        ans.push_back(i ^ (i >> 1)) ;
    }
    return ans ;
}

// Converting Number to Hexadecimal ->
string toHex(int num){
    string hex = "0123456789abcdef" ;
    string ans = "" ;
    unsigned int n = num ;
    while(n != 0){
        int digit = n & 15 ;
        ans += hex[digit] ;
        n >>= 4 ;
    }
    reverse(ans.begin() , ans.end()) ;
    return ans ;
}

// Hamming Distance ->
int hammingDistance(int x , int y){
    int n = x ^ y ;
    int count = 0 ;
    while(n > 0){
        count += n & 1 ;
        n >>= 1 ;
    }
    return count ;
}

// Complement Of Number ->
int findComplement(int num){
    if(num == 0) return 1 ;

    int mask = 0 ;
    int temp = num ;

    while(temp > 0){
        mask = (mask << 1)| 1 ;
        temp >>= 1 ;
    }
    return num ^ mask ;
}

// Total Hamming Distance (Method 1) ->
int totalHammingDistance(vector<int> nums){
    int n = nums.size() ;
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            int x = nums[i] ^ nums[j] ;
            sum += countSetBits(x) ;
        }
    }
    return sum ;
}

// Total Hamming Distance (Method 2) ->
int totalHammingDistance(vector<int> nums){
    int n = nums.size() ;
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        int ones = 0 ;
        for(int num : nums){
            if((num >> i) & 1){
                ones ++ ;
            }
        }
        sum += ones * (n - ones) ;
    }
    return sum ;
}
 
int main(){
    
    // Binary Addition ->
    // string a ; 
    // string b ;
    // cout << "Enter the first binary numbers : " ;
    // getline(cin , a) ;
    // cout << "Enter the second binary number : " ;
    // getline(cin , b) ;
    // cout << addBinary(a , b) ;

    // Single Number ->
    // int n ; 
    // cout << "Enter the number of elements in the array : " ;
    // cin >> n ;
    // vector<int> nums(n) ;
    // cout << "Enter the elements in the array : " << endl ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> nums[i] ;
    // }
    // cout << "Non Duplicate element in the given array is : " ;
    // cout << nonDuplicate(nums) ;

    // Power of two ->
    // int n ;
    // cout << "Enter the number to be checked : " ;
    // cin >> n ;
    // int result = isPowerOfTwo(n) ;
    // if(result){
    //     cout << "Number is power of 2 " ;
    // }
    // else{
    //     cout << "Number is not a power of 2 " ;
    // }

    // Number of set bits (M1 and M2) ->
    // int n ;
    // cout << "Enter the number : " ;
    // cin >> n ;
    // cout << "Number of set bits in the number is : " << setBits(n) ;
    // cout << "Number is set bits in the number is : " << hammingWeight(n) ;

    // Minimum bit flip to convert a number ->
    // int start , goal ;
    // cout << "Enter the number to be converted : " ;
    // cin >> start ;
    // cout << "Enter the target in which the number wiil be converted : " ;
    // cin >> goal ;
    // cout << "Minimum bits required to be converted to change the number is : " << minBitFlips(start , goal) ;

    // Single Number II ->
    // int n ;
    // cout << "Enter the number of elements in the array : " ;
    // cin >> n ; 
    // vector<int> nums(n) ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> nums[i] ;
    // } 
    // cout << "Number which is appearing only once is : " << singleNumber(nums) ;

    // Single Number III (M1 and M2) ->
    // int n ;
    // cout << "Enter the number of elementrs in the array : " ;
    // cin >> n ;
    // vector<int> nums(n) ;
    // cout << "Enter the elements in the array : " << endl ;
    // for(int i = 0 ; i < n ; i++){
    //     cin >> nums[i] ;
    // }
    // cout << "Required numbers are : " ;
    // vector<int> result = singleNumber3(nums) ;
    // for(int i = 0 ; i < result.size() ; i++){
    //     cout << result[i] << " " ;
    // }
    
    // Divide 2 numbers ->
    // int dividend ;
    // cout << "Enter the Dividend : " ;
    // cin >> dividend ;
    // int divisor ;
    // cout << "Enter the Divisor : " ;
    // cin >> divisor ;
    // cout << "Integer value of Quotient is : " ;
    // cout << divide(dividend , divisor) ;

    // Reverse 32 Bits number ->
    // int n ;
    // cout << "Enter a 32 bit number to be reversed : " ;
    // cin >> n ;
    // cout << "Reversed Number is : " << reverseBits(n) ;

    // Counting Bits ->
    // int n ;
    // cout << "Enter the number : " ;
    // cin >> n ;
    // cout << "Number of One's in all the preceding numbers before " << n << " are : " << endl  ;
    // vector<int> result = countBits(n) ;
    // for(int i = 0 ; i < result.size() ; i++){
    //     cout << result[i] << " " ;
    // }

    // Find Target Index After Sorting ->
    // int n, target;
    // cout << "Enter the number of elements in the array : ";
    // cin >> n ;
    // vector<int> nums(n) ;
    // cout << "Enter the elements in the array : " << endl ;
    // for (int i = 0; i < n; i++) {
    //     cin >> nums[i] ;
    // }
    // cout << "Enter the target element : " ;
    // cin >> target ;
    // vector<int> ans = targetIndices(nums, target) ;
    // cout << "Target indices after sorting are : " ;
    // for (int i = 0; i < ans.size(); i++) {
    //     cout << ans[i] << " " ;
    // }
    // cout << endl ;

    // Power of Four ->
    // int n ; 
    // cout << "Enter the number of be checked : " ;
    // cin >> n ;
    // bool answer = isPowerOfFour(n) ;
    // if(answer == true ){
    //     cout << n << " is power of 4 " ;
    // }
    // else{
    //     cout << n << " is not a power of 4 " ;
    // }

    // Binary Watch ->
    // int turnedOn ;
    // cout << "Enter the number of set bits : " ;
    // cin >> turnedOn ;
    // cout << "All possible time that can be showed using " << turnedOn << "bits is : " ;
    // vector<string> result = watch(turnedOn) ;
    // for(int i = 0 ; i < result.size() ; i++){
    //     cout << result[i] << "  " ;
    // } 

    // Gray Code (M1 and M2)->
    // int n ; 
    // cout << "Enter the Binary to be converted to Gray Code : " ;
    // cin >> n ;
    // cout << "Gray Code will be : " ;
    // // vector<int> result = grayCode(n) ;
    // vector<int> result = grayCode2(n) ;
    // for(int i = 0 ; i < result.size() ; i++){
    //     cout << result[i] << " "  ;
    // }

    // Converting Number to HexaDecimal ->
    // int num ;
    // cout << "Enter the HexaDecimal Number : " ;
    // cin >> num ;
    // cout << "Required Hexadecimal Number is : " ;
    // cout << toHex(num) ;

    // Hamming Distance ->
    // int x , y ;
    // cout << "Enter the number of x : " ;
    // cin >> x ;
    // cout << "Enter the number of y : " ;
    // cin >> y ;
    // cout << "Hamming Distance is : " ;
    // cout << hammingDistance(x , y) ;

    // Complement of Number ->
    // int num ;
    // cout << "Enter the number : " ;
    // cin >> num ;
    // cout << "Complement of the " << num << " is : " ;
    // cout << findComplement(num) ;
     
    // Total Hamming Distance ->
    int n ;
    cout << "Enter the number of elments in the array : " ;
    cin >> n ;
    vector<int> nums(n) ;
    cout << "Enter the elements in the array : " << endl ;
    for(int i = 0 ; i < n ; i++){
        cin >> nums[i] ;
    }
    cout << "Total Hamming Distance is : " ;
    cout << totalHammingDistance(nums) ;

    return 0 ;
}