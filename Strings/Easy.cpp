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

int main(){
    string s ;
    cout << "Enter the string  : " ;
    getline(cin , s) ;



    // cout << "After removing the outermost parenthesis given parenthesis is : " << removeOuterParentheses(s) ;

    // cout << "String in the reverse order is : " << reverseWords(s) ;

    return 0 ;
}