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

// Checking whether LL is a loop (Tortoise and Hare Algo) ->
bool Loop(Node* head){
    Node* slow = head ;
    Node* fast = head ;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next ;
        fast = fast -> next -> next ;
        
        if(slow == fast) return true ;
    }
    return false ;
}

// Find the starting point of the Loop (Method 1)->
Node* cycle(Node* head){
    map< Node* , int > mpp ;
    Node* temp = head ;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            return temp ;
        }
        mpp[temp] = 1 ;
        temp = temp -> next ;
    }
    return NULL ;
}

// Find the starting point of the Loop (Tortoise and Hare Algo) ->
Node* detectCycle(Node* head){
    Node* slow = head ;
    Node* fast = head ;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next ;
        fast = fast -> next -> next ;

        if(slow == fast){
            slow = head ;
            while(slow != fast){
                slow = slow -> next ;
                fast = fast -> next ;
            }
            return slow ;
        }
    }
    return NULL ;
}

// Find the length of the Loop (Method 1)->
int lenLoop(Node* head){
    map<Node* , int> mpp ;
    Node* temp = head ;
    int timer = 1 ;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            int value = mpp[temp] ;
            return timer-value ;
        }
        mpp[temp] = timer ;
        timer++ ;
        temp = temp -> next ;
    }
    return 0 ;
}

// Find the length of the Loop (Tortoise and Hare Algo) ->
int findLength(Node* slow , Node* fast){
    int count = 1 ;
    fast = fast -> next ;
    while(fast != slow){
        count ++ ;
        fast = fast -> next ;
    }
    return count ;
}
int LengthLoop(Node* head){
    Node* slow = head ;
    Node* fast = head ;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next ;
        fast = fast -> next -> next ;
        if(fast == slow) return findLength(slow , fast);
    }
    return false ;
}

// Check whether the LL is Palindrome (Method 1) ->
bool palindrome(Node* head){
    stack<int> st ;
    Node* temp = head ;
    while(temp != NULL){
        st.push(temp -> data) ;
        temp = temp -> next ;
    }
    temp = head ;
    while(temp != NULL){
        if(temp -> data != st.top()) return false ;
        temp = temp -> next ;
        st.pop() ;
    }
        return true ;
}

// Check whether the LL is Palindrome (Method 2) ->
bool isPalindrome(Node* head){
    if(head == NULL || head -> next == NULL) return true ;

    Node* slow = head ;
    Node* fast = head ;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next ; 
        fast = fast -> next -> next ;
    }

    Node* newHead = reverse(slow -> next) ;

    Node* first = head ;
    Node* second = newHead ;
    
    while(second != NULL){
        if(first -> data != second -> data){
            reverse(newHead) ;
            return false ;
        }
        first = first -> next ;
        second = second -> next ;
    }
    reverse(newHead) ;
    return true ;
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

    // Reversing a LL (Method 2) ->
    // cout << "Reversed LL is : " ;
    // head = reverse2(head)  ;
    // print(head) ;

    // Checking the LL is Loop or not (Always give not a loop) ->
    // if(Loop(head)) {
    //     cout << "Entered LL is a Loop";
    // }
    // else {
    //     cout << "Entered LL is not a Loop";
    // }

    // Checking the LL is Loop or not (Creating a loop) ->
    // Node* temp = head;
    // Node* second = head->next;
    // while(temp->next != NULL) {
    //     temp = temp->next;
    // }
    // temp->next = second ;
    // if(Loop(head)) {
    //     cout << "Entered LL is a Loop";
    // }
    // else {
    //     cout << "Entered LL is not a Loop";
    // }
    
    // Length of the Loop ->
    // cout << "The length of the Loop is : " << endl ;
    // cout << lenLoop(head) ;

    // Length of the Loop (Tortoise And Hare Algo) ->
    // cout << "The length of the Loop is : " << endl ;
    // cout << LengthLoop(head) ;

    // Checking if the LL is palindrome ->
    // if(palindrome(head) == true){
    //     cout << "Entered LL is palindrome " ;
    // }
    // else{
    //     cout << "Entered LL is not a palindrome " ;
    // }

    return 0 ;
}