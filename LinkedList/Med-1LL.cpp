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

// Reversing a LL (Iterative Method)->
Node* reverse(Node* head){
    Node* temp = head ;
    Node* prev = NULL ;
    while(temp != NULL){
        Node* front = temp -> next ;
        temp -> next = prev ;
        prev = temp ;
        temp = front ;
    }
    return prev ;
}

// Reversing a LL (Recursive Method) ->
Node* reverse2(Node* head){
    if(head == NULL || head -> next == NULL){
        return head ;
    }
    Node* newHead = reverse2(head -> next) ;
    Node* front = head -> next ; 
    front -> next = head ;
    head -> next = NULL ;

    return newHead ;
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

    // Converting array into LL ->
    Node* head = convertArr2LL(nums);

    // Reversing a LL (Method 1) ->
    // cout << "Reversed LL is : " ;
    // head = reverse(head) ;
    // print(head) ;

    // reversing a LL (Method 2) ->
    // cout << "Reversed LL is : " ;
    // head = reverse2(head)  ;
    // print(head) ;


    return 0 ;
}