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


int main(){
    string s ;
    cout << "Enter the string  : " ;
    getline(cin , s) ;

    // int n;        // Taking number of strings and strings also
    // cout << "Enter number of strings: ";
    // cin >> n;
    // vector<string> s(n);
    // cout << "Enter the strings:\n";
    // for(int i = 0; i < n; i++){
    //     cin >> s[i];
    // }


    // cout << "After removing the outermost parenthesis given parenthesis is : " << removeOuterParentheses(s) ;

    // cout << "String in the reverse order is : " << reverseWords(s) ;

    // cout << "Largest odd number possible is : " << largestOddNumber(s) ;

    // cout << "Largest common string : " << largestCommonPrefix(s) ;
    
    return 0 ;
}