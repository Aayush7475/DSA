#include<bits/stdc++.h>
using namespace std ;

// Removing outermost parenthesis 
string removeOuterParentheses(string s){
       string result = "" ;
       int level = 0 ;
       for(char ch : s){
            if(ch == '(' ){
                if(level > 0) result += ch ;
                level ++ ;
            }
            else if(ch == ')' ){
                level -- ;
                if(level > 0) result += ch ;
            }
        }
        return result ; 
}

// Returning the string in reverse order with only single space b/w the words
string reverseWords(string s){
    vector<string> words ;
    string word = "" ;
    for(char ch : s){
        if(ch != ' '){
            word += ch ;
        }
        else{
            if(!word.empty()){
                words.push_back(word) ;
                word = "" ;
            }
        }
    }
    if (! word.empty()){
        words.push_back(word) ;
    }
    string ans = "" ;
    for(int i = words.size() - 1 ; i>= 0 ; i--){
        ans += words[i] ;
        if(i != 0) ans += " " ;
    }
    return ans ;
}

// Returning the largest odd number(sub-string) 
string largestOddNumber(string s){
    int n = s.length() ;
    int index = -1 ;

    for(int i = n-1 ; i >= 0 ; i--){
        if((s[i] - '0') % 2 == 1){
            index = i ;
            break ;
        }
    }
    int i = 0 ;
    while(i < index && s[i] == '0') i++ ;

    return s.substr(i , index - i + 1) ;
}

// Returning the largest common prefix 
string largestCommonPrefix(vector<string>& s){
    if(s.empty()) return "";
    sort(s.begin() , s.end()) ;

    string first = s[0] ;
    string last = s[s.size() - 1] ;

    string ans = "" ;

    int minLength = min(first.size() , last.size()) ;

    for(int i = 0 ; i < minLength ; i++){
        if(first[i] != last[i]){
            break ;
        }
        ans += first[i] ;
    }
    return ans ;
}

// Isomorphic Stings 
bool Isomorphic(string s , string t){
    if(s.length() != t.length()) return false ;
    int m1[256] = {0} ;
    int m2[256] = {0} ;
    int n = s.size() ;

    for(int i = 0 ; i < n ; i++){
        if(m1[s[i]] != m2[t[i]]) return false ;
        m1[s[i]] = i+1 ;
        m2[t[i]] = i+1 ;
    }
    return true ;
}

// Checking if one string is rotation of another 
bool Rotation(string s , string goal){
    if(s.length() != goal.length()){
        return false ;
    }
    for(int i = 0 ; i < s.length() ; i++){
        string rotated = s.substr(i) + s.substr(0 , i) ;
        if(goal == rotated){
            return true ;
        }
    }
    return false ;
}

// Checking whether an string is Anagram or not 
bool isAnagram(string str1 , string str2){
    if(str1.length() != str2.length()) return false ;

    sort(str1.begin() , str1.end()) ;
    sort(str2.begin() , str2.end()) ;

    for(int i = 0 ; i < str1.length() ; i++){
        if(str1[i] != str2[i]){
            return false ;
        }
    }
    return false ;
}

// Sorting characters by firstly frequency and if frequency is same then by alphabetical order 
string frequencySort(string s) {
    unordered_map<char,int> freq ;

    for(char ch : s){
        freq[ch] ++ ;
    }

    vector<pair<char , int>> v ;
    for(auto &it : freq){
        v.push_back({it.first , it.second}) ;
    }

    sort(v.begin() , v.end() , [](pair<char , int> a , pair<char , int> b){
        if(a.second != b.second){
            return a.second > b.second ;
        }
        else{
            return a.first < b.first ;
        }
    });

     string ans;

    for (auto &it : v) {
        ans += it.first;
    }

    return ans ;
}

// Returing the highest depth of parenthesis 
int maxDepth(string s){
    int ans = 0 ;
    int count = 0 ;
    for(char x : s){
        if(x == '(' ){
            count ++ ;
            ans = max(ans , count) ;
        }
        else if(x == ')' ){
            count -- ;
        }
    }
    return ans ;
} 

// Converting Roman to integers 
int RomantoInt(string s){
    unordered_map<char , int> mp{
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    } ;
    int ans = 0 ;
    for(int i = 0 ; i < s.length() ; i++){
        if(i+1 < s.length() && mp[s[i]] < mp[s[i+1]]){
            ans -= mp[s[i]] ;
        }
        else{
            ans += mp[s[i]] ;
        }
    }
    return ans ;
}

// Recursive implementation of ATOI( ASCII VAlue into Integer )
int Myatoi(string s){
    int i = 0  ;
    int n = s.length() ;

    while(i < n && s[i] == ' '){
        i++ ;
    }

    int sign = 1 ;

    if(i < n && (s[i] == '+' || s[i] == '-')){
        if(s[i] == '-'){
            sign = -1 ;
        }
        i++ ;
    }

    long long num = 0;

    while(i < n && isdigit(s[i])){
        int digit = s[i] - '0' ;

        if(num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > (sign == 1 ? 7 : 8))){
            return sign == 1 ? INT_MAX : INT_MIN ;
        }
        
        num = num * 10 + digit ;
        i++ ;
    }
    return sign * num ;

}

// Longest palindromic substring 
string PalindromicSubstring(string s){
    if(s.length() < 1){
        return s ;
    }
    string LPS = "" ;

    for(int i = 0 ; i < s.length() ; i++){

        // Even 
        int low = i ;
        int high = i ;
        while(low >= 0 && high <= s.length() && s[low] == s[high]){
            low -- ;
            high ++ ;
        }
        string palindrome = s.substr(low+1 , high-low-1) ;
        if(palindrome.length() > LPS.length()){
            LPS = palindrome ;
        }

        // Odd
        low = i ;
        high = i+1 ;
        while(low >= 0 && high <= s.length() && s[low] == s[high]){
            low -- ;
            high ++ ;
        }
        palindrome = s.substr(low+1 , high-low-1);
        if(palindrome.length() > LPS.length()){
            LPS = palindrome ;
        }
    }
    return LPS ;
}

// Return difference between the frequency of the most frequent character and the least frequent character
int BeautySum(string s){
    int n = s.length() ;
    int ans = 0 ;

    for(int i = 0 ; i < n ; i++){
        vector<int> freq(26,0) ;
        
        for(int j = i ; j < n ; j++){
            freq[s[j] - 'a'] ++ ;

            int maxi = 0 ;
            int mini = INT_MAX ;

            for(int k = 0 ; k < 26 ; k++){
                if(freq[k] > 0){
                    maxi = max(maxi , freq[k]) ;
                    mini = min(mini , freq[k]) ;
                }
            }
            ans += (maxi - mini) ;
        }
    }
    return ans ;
}

// Return the index of the first occurrence 
int Occurence(string haystack , string needle){
    int n = haystack.size() ;
    int m = needle.size() ;

    for(int i = 0 ; i < n-m ; i++){
        bool match = true ;
        for(int j = 0 ; j < m ; j++){
            if(haystack[i+j] != needle[j]){
                match = false ;
                break ;
            }
        }
        if(match){
            return i ;
        }
        return -1 ;
    }
}

int main(){
    string s ;
    cout << "Enter the string  : " ;
    getline(cin , s) ;

    // int n;               // Taking number of strings and strings also
    // cout << "Enter number of strings: ";
    // cin >> n;
    // vector<string> s(n);
    // cout << "Enter the strings:\n";
    // for(int i = 0; i < n; i++){
    //     cin >> s[i];
    // }

    // string str1 ;        // Taking the strings to chk whether it's Anagram or not 
    // cout << "Enter the string  : " ;
    // cin >> str1 ;
    // string str2 ;
    // cout << "Enter the string  : " ;
    // cin >> str2 ;
    


    // cout << "After removing the outermost parenthesis given parenthesis is : " << removeOuterParentheses(s) ;

    // cout << "String in the reverse order is : " << reverseWords(s) ;

    // cout << "Largest odd number possible is : " << largestOddNumber(s) ;

    // cout << "Largest common string : " << largestCommonPrefix(s) ;
    
    // int result = Isomorphic(s , t) ;
    // if(result = true){
    //     cout << "Given strings are isomorphic" ; 
    // }
    // else{
    //     cout << "Given strings are not isomorphic" ;
    // }

    // int result = Rotation(s , goal);
    // if(result = true){
    //     cout << "Entered string can be achieved by rotating  " ;
    // }
    // else{
    //     cout << "Entered string cannot be achieved by rotating " ;
    // }

    // int result = isAnagram(str1 , str2);
    // if(result = true){
    //     cout << "Entered string is an anagram " ;
    // }
    // else{
    //     cout << "Entered string is not an anagram " ;
    // }

    // string result = frequencySort(s) ;
    // cout << "Output is :" << result ;

    // cout<< "Max depth of teh parenthesis is : " << maxDepth(s) ;

    // cout << "Roman number in integer is :  " << RomantoInt(s) ;

    // cout << s << " in Integer is : " << Myatoi(s) ;

    // cout << "Longest Palindromic Substring is : " << PalindromicSubstring(s) ;   

    // cout << "Beauty sum is : " << BeautySum(s) ;

    
    return 0 ;
}