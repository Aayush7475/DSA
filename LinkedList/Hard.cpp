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
class Node{     // For Flattening of LL 
    public : 
    int data ; 
    Node* next ; 
    Node* child ;

    public : 
    Node(int data1 , Node* next1 , Node* prev1){
        data = data1 ;
        next = next1 ;
        child = next1 ;
    }
    public :
    Node(int data1){
        this->data = data1 ;
        next = nullptr ;
        child = nullptr ;
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

void printChild(Node* head){
    while(head != NULL){
        cout << head -> data << " " ;
        head = head -> child ;
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

// Rotating a LL by k steps ->
Node* findNthNode(Node* temp , int k){
    int cnt = 1 ;
    while(temp != NULL){
        if(cnt == k) return temp ;
        cnt ++ ;
        temp = temp -> next ;
    }
    return temp ;
}
Node* Rotating(Node* head , int k){
    if(head == NULL || k == 0) return head ;

    Node* tail = head ;
    int len = 1 ;

    while(tail -> next != NULL){
        len ++ ;
        tail = tail -> next ;
    }

    if(k % len == 0 ) return head ;
    k = k  % len ;

    tail -> next = head ;

    Node* newLastNode = findNthNode(head , len - k) ;
    head = newLastNode -> next ;
    newLastNode -> next = NULL ;

    return head ;
}

// Flattening a LL (Method 1) ->
Node* convert(vector<int> &nums){
    if(nums.size() == 0) return NULL ;
    Node* head = new Node(nums[0]) ;
    Node* temp = head ;
    for(int i = 1 ; i < nums.size() ; i++){
        Node* newNode = new Node(nums[i]) ;
        temp -> child = newNode ;
        temp = temp -> child ;
    }
    return head ;
}
Node* Flattening(Node* head ){
    vector<int> nums ;
    Node* temp = head ;
    while(temp != NULL){
        Node* t2 = temp ;
        while(t2 != NULL){
            nums.push_back(t2 -> data) ;
            t2 = t2 -> child ;
        }
        temp = temp -> next ;
    }
    sort(nums.begin() , nums.end()) ;
    head = convert(nums) ;
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

    // Rotating a LL ->
    // int k ;
    // cout << "Enter the number to which the LL will be rotated : " ;
    // cin >> k ;
    // head = Rotating(head , k) ;
    // print(head) ;

    return 0 ;
}

// int main(){     // For Flattening of LL 
//     int n;
//     cout << "Enter number of nodes in main level: ";
//     cin >> n;
//     if(n == 0) return NULL;
//     Node* head = NULL;
//     Node* temp = NULL;
//     for(int i = 0; i < n; i++) {
//         int x;
//         cout << "Enter value: ";
//         cin >> x;
//         Node* newNode = new Node(x);
//         if(head == NULL) {
//             head = newNode;
//             temp = head;
//         }
//         else {
//             temp->next = newNode;
//             temp = newNode;
//         }
//     }
//     // Add child lists
//     temp = head;
//     while(temp != NULL) {
//         char choice;
//         cout << "Do you want to add child to " << temp->data << "? (y/n): ";
//         cin >> choice;
//         if(choice == 'y') {
//             int m;
//             cout << "Enter number of child nodes: ";
//             cin >> m;
//             Node* childHead = NULL;
//             Node* childTemp = NULL;
//             for(int i = 0; i < m; i++) {
//                 int x;
//                 cout << "Enter child value: ";
//                 cin >> x;
//                 Node* newNode = new Node(x);
//                 if(childHead == NULL) {
//                     childHead = newNode;
//                     childTemp = newNode;
//                 }
//                 else {
//                     childTemp->next = newNode;
//                     childTemp = newNode;
//                 }
//             }
//             temp->child = childHead;
//         }
//         temp = temp->next;
//     }
//     head = Flattening(head) ;
//     printChild(head) ;
//     return 0 ;
// }