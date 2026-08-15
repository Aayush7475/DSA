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

Node* convertArr2LL(vector<int> &nums){
    Node* head = new Node(nums[0]) ;
    Node* mover = head ;

    for(int i = 1 ; i < nums.size() ; i++){
        Node* temp = new Node(nums[i]) ;
        mover -> next = temp ;
        mover = temp ;
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
    Node* head = convertArr2LL(nums);

    // Reversing the DLL ->
    head = reverseMethod1(head) ;
    print(head);


    return 0 ;
}