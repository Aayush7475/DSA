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

// Deleting given Node in DLL ->
void NodeDeletion(Node* temp){
    if (temp->back == NULL) {
        cout << "Cannot delete head using this function.\n";
        return;
    }

    Node* prev = temp -> back ;
    Node* front = temp -> next ;

    if(front == NULL){
        prev -> next = nullptr ;
        temp -> back = nullptr ;
        free(temp) ;
        return ;
    }
    prev -> next = front ;
    front -> back = prev ;

    temp -> next = nullptr ;
    temp -> back = nullptr ;
    delete temp ;

}

// Inserting before Head in DLL ->
Node* insertBeforeHead(Node* head , int val){
    Node* newHead = new Node(val , head , nullptr);
    head -> back = newHead ;
    return newHead ;
}

// Inserting before Tail in DLL ->
Node* insertBeforeTail(Node* head , int val){
    if(head == NULL){
        return new Node(val , NULL ,NULL) ;
    }
    if(head -> next == NULL){
        return insertBeforeTail(head , val) ;
    }
    Node* tail = head ;
    while(tail-> next != NULL){
        tail = tail -> next ;
    }
    Node* prev = tail -> back ;
    Node* newNode = new Node(val , tail , prev);
    prev -> next = newNode ;
    tail -> back = newNode ; 

    return head ;
}

// Inserting before Kth element in DLL ->
Node* insertBeforeKthElement(Node* head , int k , int val){
    if(k == 1){
        return insertBeforeHead(head , val) ;
    }
    Node* temp = head ;
    int cnt = 0 ;
    while(temp != NULL){
        cnt ++ ;
        if(cnt == k) break ;
        temp = temp -> next ;
    }
    Node* prev = temp -> back ;
    Node* newNode = new Node(val , temp , prev) ;
    prev -> next = newNode ;
    temp -> back = newNode ;

    return head ;
}

// Inserting before given Node in DLL ->
void insertBeforeNode(Node* node , int val){
    Node* prev = node -> back ;
    Node* newNode = new Node (val , node , prev) ;

    prev -> next = newNode ;
    node -> back = newNode ;
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

// Reversing a DLL method 2 ->
Node* reverseMethod2(Node* head){
    if(head == NULL ||  head -> next == NULL){
        return NULL ;
    }
    Node* prev = NULL ;
    Node* current = head ;

    while(current != NULL){
        prev = current -> back ;

        current -> back = current -> next ;
        current -> next = prev ;

        current = current -> back ;
    }    
    return prev -> back ;
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

    // Deleting given Node in DLL ->
    // Node* temp = head->next->next->next ; // next is used to reach to the index of the node which we want to delete 
    // NodeDeletion(temp);
    // print(head) ;

    // Inserting Before Head in DLL ->
    // int val ;
    // cout << "Enter the value to be inserted : ";
    // cin >> val ;
    // head = insertBeforeHead(head , val);
    // print(head);

    // Inserting Before Tail in DLL ->
    // int val ;
    // cout <<"Enter the value to be inserted :  " ;
    // cin >> val ;
    // head = insertBeforeTail(head , val);
    // print(head) ;

    // Inserting Before Kth element in DLL ->
    // int k ; 
    // cout << "Enter the index before which the element to be inserted : ";
    // cin >> k ;
    // int val ;
    // cout << "Enter the value to be inserted : " ;
    // cin >> val ;
    // head = insertBeforeKthElement(head , k , val) ;
    // print(head) ;

    // Inserting Before given Node in DLL ->
    // int val ;
    // cout << "Enter the value to be inserted : " ;
    // cin >> val ;
    // insertBeforeNode(head->next , val) ;     // next is used to reach to the index of the node where we want to insert 
    // print(head) ;

    // Reversing DLL Method 1 ->
    // cout << "Reversed DLL is : " ;
    // head = reverseMethod1(head) ;
    // print(head) ;

    // reversing DLL Method 2 ->
    // cout << "Reversed DLL is : " ;
    // head = reverseMethod2(head) ;
    // print(head) ;

    return 0 ;
}