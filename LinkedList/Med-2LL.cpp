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

// Returning all Pairs with given sum in DLL ->
vector<pair<int,int>> sumPairs(Node* head , int sum){
    Node* t1 = head ;
    Node* t2 ;
    vector<pair<int,int>> ds ;

    while(t1 != NULL){
        t2 = t1 -> next ;
        while(t2 != NULL && t1->data + t2->data <= sum){
            if(t1->data + t2->data == sum){
                ds.push_back({t1->data , t2->data}) ;
            }
            t2 = t2 -> next ;
        }
        t1 = t1 -> next ;
    }
    return ds ;
}

// Removing duplicates from the sorted DLL ->
Node* duplicates(Node* head){
    Node* temp = head ;
    while(temp != NULL && temp -> next != NULL){
        Node* nextNode = temp -> next ;
        while(nextNode != NULL && nextNode -> data == temp -> data){
            nextNode = nextNode -> next ;
        }
        temp -> next = nextNode ;
        if(nextNode != NULL) nextNode -> prev = temp ;
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

    // Deleting all Occurences of a key in DLL ->
    // int key ;
    // cout << "Enter the value of key : " ;
    // cin >> key ;
    // head = deleteOccurences(head , key) ;
    // print(head) ;

    // Returning all Pairs with given sum in DLL ->
    // int sum ;
    // cout << "Enter the sum of the pairs : ";
    // cin >> sum ;
    // vector<pair<int,int>> ans = sumPairs(head, sum);
    // for(auto it : ans){
    //     cout << "(" << it.first << " , " <<  it.second << ")" << endl ;
    // }

    // Removing duplicates from the sorted DLL ->
    // head = duplicates(head) ;
    // print(head) ;


    return 0 ;
}