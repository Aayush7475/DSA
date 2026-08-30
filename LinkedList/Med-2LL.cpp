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

// Deleting all Occurences of a key in DLL ->
Node* deleteOccurences(Node* head , int key){
    Node* temp = head ;
    while(temp != NULL){
        if(temp -> data == key){
            if(temp == head){
                head = temp -> next ;
            }
            Node* nextNode = temp -> next ;
            Node* prevNode = temp -> prev ;

            if(nextNode != NULL) nextNode -> prev = prevNode ;
            if(prevNode != NULL) prevNode -> next = nextNode ;
            
            free(temp) ;
            temp = nextNode ;
        }
        else{
            temp = temp -> next ;
        }
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

    // Deleting all Occurences of a key in DLL ->
    // int key ;
    // cout << "Enter the value of key : " ;
    // cin >> key ;
    // head = deleteOccurences(head , key) ;
    // print(head) ;

    
    return 0 ;
}