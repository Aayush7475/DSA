#include<bits/stdc++.h>
using namespace std ; 

class Node{
    public : 
    int data ; 
    Node* next ; 
    Node* prev ;

    public : 
    Node(int data1 , Node* next1 , Node* prev1){
        data = data1 ;
        next = next1 ;
        prev = prev1 ;
    }
    public :
    Node(int data1){
        data = data1 ;
        next = nullptr ;
        prev = nullptr ;
    }
};

void print(Node* head){
    Node* temp = head ;

    while(temp != NULL){
        cout << temp->data << " " ;
        temp = temp->next ;
    }
    cout << endl ;
}

// Converting array into Doubley LL ->
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

// Reversing Nodes in K Group ->
Node* reverse(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* prev = NULL;
    Node* current = head;

    while(current != NULL) {
        Node* temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    return prev;
}
Node* getKthNode(Node* temp , int k){
    k -= 1 ;
    while(temp != NULL && k > 0){
        k-- ;
        temp = temp -> next ;
    }
    return temp ;
}
Node* reverseKGroup(Node* head, int k){
    Node* temp = head ;
    Node* prevLast = NULL ;

    while(temp != NULL){
        Node* KthNode = getKthNode(temp , k) ;
        if(KthNode == NULL){
            if(prevLast) prevLast -> next = temp ;
            break ;
        }

        Node* nextNode = KthNode -> next ;
        KthNode -> next = NULL ;

        reverse(temp) ;

        if(temp == head) head = KthNode ;
        else prevLast -> next = KthNode ;

        prevLast = temp ;
        temp = nextNode ;
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

    // Reversing Nodes in K Group ->
    // int k ;
    // cout << "Enter the number to be grouped : " ;
    // cin >> k ;
    // head = reverseKGroup(head , k) ;
    // cout << "After reversing in K groups: ";
    // print(head);

    return 0 ;
}