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

// Deleting head in DLL ->
Node* HeadDeletion(Node* head){
    if(head == NULL || head -> next == NULL){
        return NULL ;
    }
    Node* prev = head ;
    head = head -> next ;
    head -> back = nullptr ;
    prev -> next = nullptr ;

    delete prev ;
    return head ;
}

// Deleting tail in DLL ->
Node* TailDeletion(Node* head){
    if(head == NULL || head -> next == NULL){
        return head ;
    }
    Node* tail = head ;
    while(tail -> next != NULL){
        tail = tail -> next ;
    }
    Node* newTail = tail -> back ;
    newTail -> next = nullptr ;
    tail -> back = nullptr ;
    delete tail ;

    return head ;
}

// Deleting given Kth element in DLL ->
Node* KthDeletion(Node* head , int k){
      if(head == NULL){
        return NULL ;
      }
      int cnt = 0 ;
      Node* KNode = head ;
      while(KNode != NULL){
        cnt ++ ;
        if(cnt == k){
           break ; 
        }
        KNode = KNode -> next ;
      }
      Node* prev = KNode -> back ;
      Node* front = KNode -> next ;

      if(prev == NULL && front == NULL){
        return NULL ;
      }

      else if(prev == NULL){
        return HeadDeletion(head);
      }

      else if(front == NULL){
        return TailDeletion(NULL);
      }
      
      prev -> next = front ;
      front -> back = prev ;

      KNode -> next = nullptr ;
      KNode -> back = nullptr ;

      delete KNode ;
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

    // Deleting head in DLL ->
    // head = HeadDeletion(head) ;
    // print(head) ;

    // Deleting tail in DLL ->
    // head = TailDeletion(head) ;
    // print(head) ;

    // Deleting Kth element in DLL ->
    // int k ;
    // cout << "Enter the index to be deleted : ";
    // cin >> k ;
    // head = KthDeletion(head , k) ;
    // print(head) ;

    return 0 ;
}