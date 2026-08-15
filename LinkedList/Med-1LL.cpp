#include<bits/stdc++.h>
using namespace std ;

class Node{
    public:
    int data ;
    Node* next ;
    Node* back ;

    public:
    Node(int data1 , Node* next1 , Node* back1){
        data = data1 ;
        next = next1 ;
        back = back1 ; 
    }

    public:
    Node(int data1){
        data = data1 ;
        next = nullptr ;
        back = nullptr ;
    }
};

void print(Node* head){
    Node* temp = head ;

    while(temp != NULL){
        cout << temp -> data << " " ;
        temp = temp -> next ;
    }
    cout << endl  ;
}

Node* convertArr2DLL(vector<int> &nums){
    Node* head = new Node(nums[0]) ;
    Node* prev = head ;
    for(int i = 1 ; i < nums.size() ; i++){
        Node* temp = new Node(nums[i] , nullptr , prev) ;
        prev -> next = temp ;
        prev = temp ;
    } 
    return head ;
}

// Reversing a DLL method 1->
Node* reverseMethod1(Node* head){
   stack<int> st ;

   Node* temp = head ;
   while(temp != NULL){
    st.push(temp -> data);
    temp = temp -> next ;
   } 
   temp = head ;
   while(temp != NULL){
    temp -> data = st.top() ;
    st.pop() ;
    temp = temp -> next ;
   }
   return head ;
}

int main(){
    int n ; 
    cout << "Enter the number of elements in the array : ";
    cin >> n ;

    vector<int> nums(n) ;

    cout << "Enter the elements in the array :" << endl;
    for(int i = 0 ; i < n ; i++){
        cin >> nums[i];
    }

    // Converting array into DLL ->
    Node* head = convertArr2DLL(nums);

    // Reversing the DLL ->
    head = reverseMethod1(head) ;
    print(head);


    return 0 ;
}