#include<bits/stdc++.h>
using namespace std ;

class Node {
    public:
    int data ;
    Node* next ;

    public:
    Node(int data1 , Node* next1){
        data = data1 ;
        next = next1 ;
    }

    public:
    Node(int data1){
        data = data1 ;
        next = nullptr ;
    }
};

// Converting Array into LinkedList ->
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
    cout << "Enter the number of elements in the array : "   ;
    cin >> n ;

    vector<int> nums(n) ;

    cout << "Enter the elements in the array :" << endl;
    for(int i = 0 ; i < n ; i++){
        cin >> nums[i];
    }

    // Node* y = new Node{nums[0]} ;
    // cout << "First element is : " ;
    // cout << y -> data ;

    Node* head = convertArr2LL(nums) ;
    cout << "1st element in the LinkedList is : " ;
    cout << head -> data ;

    return 0 ;


} 