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

// Length of a LinkedList ->
int Length(Node* head){
    int cnt = 0 ;
    Node* temp = head ;
    while(temp){
        cnt ++ ;
        temp = temp -> next ;
    }
    return cnt ;
}

// Searching a element in LL ->
int Search(Node* head , int value){
    Node* temp = head  ;
    while(temp){
        if(temp -> data == value) return 1 ;
        temp = temp -> next ;
    }
    return 0 ;
}

void print(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";   // Space after each element
        temp = temp->next;
    }
    cout << endl;
}

// Head deletion in LL ->
Node* removeHead(Node* head){
    if(head == NULL) return head ;
    Node* temp = head ;
    head = head -> next ;
    delete temp ;
    return head ;
}

// Tail deletion in LL ->
Node* removeTail(Node* head){
    if(head == NULL || head -> next == NULL) return NULL ;
    Node* temp = head ;
    while(temp -> next -> next != NULL){
        temp = temp -> next ;
    }
    delete temp -> next ;
    temp -> next = nullptr ;

    return head ;
}

// Deleting given Kth element in LL ->
Node* removeK(Node* head , int k){
    if(head == NULL) return head ;
    if (k == 1){
        Node* temp = head ;
        head = head -> next ;
        free(temp) ;
        return head ;
    }
    int cnt = 0 ;
    Node* temp = head ;
    Node* prev = NULL ;
    while(temp != NULL){
        cnt ++ ;
        if(cnt == k){
            prev -> next = prev -> next -> next ;
            free(temp) ;
            break ;
        }
        prev = temp ;
        temp = temp -> next ; 
    }
    return head ;
}

// Deleting given value in LL ->
Node* removeValue(Node* head , int value){
    if(head == NULL) return head ;
    if (head -> data == 1){
        Node* temp = head ;
        head = head -> next ;
        free(temp) ;
        return head ;
    }
    Node* temp = head ;
    Node* prev = NULL ;
    while(temp != NULL){
        
        if(temp -> data == value){
            prev -> next = prev -> next -> next ;
            free(temp) ;
            break ;
        }
        prev = temp ;
        temp = temp -> next ; 
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

    // First Element of LL ->
    // Node* y = new Node{nums[0]} ;
    // cout << "First element is : " ;
    // cout << y -> data ;

    // Array into LL ->
    // Node* head = convertArr2LL(nums) ;
    // cout << "1st element in the LinkedList is : " ;
    // cout << head -> data ;

    // Traversal in LL ->
    // Node* head = convertArr2LL(nums) ;
    // Node* temp = head ;
    // while(temp){
    //     cout << temp -> data  << " " ;
    //     temp = temp -> next ;
    // }

    // Length of LL ->
    // Node* head = convertArr2LL(nums) ;
    // cout << "Length of the LinkedList is : " ;
    // cout << Length(head) ;
 
    // Searching an element in LL ->
    // int value ;
    // cout << "Enter the value to be searched : ";
    // cin >> value ;
    // Node* head = convertArr2LL(nums) ;
    // int result = Search(head , value);
    // if(result == 1){
    //     cout << "Searched element is found " ; 
    // }
    // else{
    //     cout << "Searched element is not found " ;
    // }
    
    // Deleting the head of LL ->
    // Node* head = convertArr2LL(nums) ;
    // head = removeHead(head) ;
    // print(head) ;

    // Deleteing the tail of LL ->
    // Node* head = convertArr2LL(nums) ;
    // head = removeTail(head) ;
    // print(head);

    // Deleteing the Kth element of LL ->
    // int k ; 
    // cout << "Enter the index to be deleted : ";
    // cin >> k;
    // Node* head = convertArr2LL(nums) ;
    // head = removeK(head , k) ;
    // print(head);

    // Deleting the given element in LL ->
    int value ;
    cout << "Enter the element to be deleted : ";
    cin >> value ;
    Node* head = convertArr2LL(nums) ;
    head = removeValue(head , value);
    print(head) ;

    return 0 ;



} 