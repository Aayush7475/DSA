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
    Node* fast = head -> next ;
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

// Placing Odd & Even Nodes in order (Method 1)->
Node* Odd_Even(Node* head){
    if(head == NULL || head -> next == NULL) return head ;

    Node* temp = head ;
    int nums[100] ;
    int i = 0 ;
   
    while(temp != NULL && temp -> next != NULL){
     nums[i++] = (temp->data) ;
     temp = temp -> next -> next ;
    }
    if(temp != NULL) nums[i++] = (temp->data) ;

    temp = head -> next ;

    while(temp != NULL && temp -> next != NULL){
     nums[i++] = (temp->data) ;
     temp = temp -> next -> next ;
    }
    if(temp != NULL) nums[i++] = (temp->data) ;

    i = 0 ;
    temp = head ;
    while(temp != NULL){
        temp -> data = nums[i++] ;
        temp = temp -> next ;
    }
    return head ;
}

// Placing Odd & Even Nodes in order (Method 2)->
Node* OddEven(Node* head){
    if(head == NULL || head -> next == NULL) return head ;

    Node* odd = head ; 
    Node* even = head -> next ;
    Node* evenHead = head -> next ;

    while(even != NULL && even->next != NULL){
        odd -> next = odd -> next -> next ;
        even -> next = even -> next -> next ;

        odd = odd -> next ;
        even = even -> next ;
    }
    odd -> next = evenHead ;
    return head ;
}

// Removing the Nth node from the end of LL (Method 1)->
Node*  removeNthFromEnd(Node* head , int N){
    int count = 0 ;
    Node* temp = head ;
    while(temp != NULL){
        count ++ ;
        temp = temp -> next ;
    }
    if(count == N){
        Node* newHead = head -> next ;
        free(head) ;
        return newHead ;
    }
    int result = count - N ; 
    temp = head ;
    while(temp != NULL){
        result -- ;
        if(result == 0){
            break ;
        }
        temp = temp -> next ;
    }
    Node* delNode = temp -> next ;
    temp -> next = temp -> next -> next ;
    free(delNode) ;

    return head ;
}

// Removing the Nth node from the end of LL (Method 2)->
Node* removeNthNodeFromEnd(Node* head , int N){
    Node* slow = head ;
    Node* fast = head ;
    for(int i = 0 ; i < N ; i++){
        fast = fast -> next ;
    }
    while(fast -> next != NULL){
        slow = slow -> next ;
        fast = fast -> next ;
    }
    Node* delNode = slow -> next ;
    slow -> next = slow -> next -> next ;
    free(delNode) ;

    return head ;
}

// Removing the Middle node of the LL (Method 1) ->
Node* removeMiddleNode(Node* head){
    if(head == NULL || head -> next == NULL) return NULL ;

    Node* temp = head ;
    int n = 0 ;
    while(temp != NULL){
        n++ ;
        temp = temp -> next ;
    }
    int res = n/2 ;
    temp = head ;
    while(temp != NULL){
        res -- ;
        if(res == 0){
            Node* middle = temp->next ;
            temp -> next = temp -> next -> next ;
            free(middle) ;
            break ;
        }
        temp = temp -> next ;
    }
    return head ;
}

// Removing the Middle node of the LL (Method 2) ->
Node* RemoveMiddleNode(Node* head){
    Node* slow = head ;
    Node* fast = head ;
    fast = fast -> next -> next ; 
    while(fast != NULL && fast -> next != NULL){
       slow = slow -> next ; 
       fast = fast -> next -> next ;
    }
    Node* middle = slow -> next ;
    slow -> next = slow -> next -> next ;
    free(middle) ;
    return head ;
}

// Sorting the LL (Method 1) ->
Node* Sort(Node* head){
    vector<int> arr ;
    Node* temp = head ;
    while(temp != NULL){
        arr.push_back(temp -> data) ;
        temp = temp -> next ;
    }
    sort(arr.begin() , arr.end()) ;
    int i = 0 ;
    temp = head ;
    while(temp != NULL){
        temp->data = arr[i] ;
        i++ ;
        temp = temp -> next ;
    }
    return head ;
}

// Sorting the LL (Method 2) ->
Node* mergeTwoLL(Node* list1 , Node* list2){
    Node* dummyNode = new Node(-1) ;
    Node* temp = dummyNode ;
    while(list1 != NULL && list2 != NULL){
        if(list1 -> data < list2 -> data){
            temp -> next = list1 ;
            temp = list1 ;
            list1 = list1 -> next ;
        }
        else{
            temp -> next = list2 ;
            temp = list2 ;
            list2 = list2 -> next ;
        }
    }
    if(list1) temp -> next = list1 ;
    else temp -> next = list2 ;

    return dummyNode -> next ;
}
Node* middleNode(Node* head) {
    Node* slow = head ;
    Node* fast = head -> next ;
    while(fast != NULL && fast-> next != NULL){
        slow = slow -> next ;
        fast = fast -> next -> next ;
    }
    return slow ;
}
Node* Sorting(Node* head){
    if(head == NULL || head->next == NULL) return head ;

    Node* middle = middleNode(head) ;
    Node* leftHead = head ;
    Node* rightHead = middle->next ;
    middle -> next = NULL ;

    leftHead = Sorting(leftHead) ;
    rightHead = Sorting(rightHead) ;

    return mergeTwoLL(leftHead , rightHead) ;
}

// Sorting a LL containing 0 , 1 , 2 (Method 1) ->
Node* Sort_1(Node* head){
    Node* temp = head ; 
    int cnt0 = 0 ;
    int cnt1 = 0 ;
    int cnt2 = 0 ;
    while(temp != NULL){
        if(temp -> data == 0) cnt0 ++ ;
        else if(temp -> data == 1) cnt1 ++ ;
        else cnt2 ++ ;

        temp = temp -> next ;
    }
    temp = head ;
    while(temp != NULL){
        if(cnt0){
            temp -> data = 0 ;
            cnt0 -- ;
        }
        else if(cnt1){
            temp -> data = 1 ;
            cnt1 -- ;
        }
        else if(cnt2){
            temp -> data = 2 ;
            cnt2 -- ;
        }
        temp = temp -> next ;
    }
    return head ;
}

// Sorting a LL containing 0 , 1 , 2 (Method 2) ->
Node* Sort_2(Node* head){
    if(head == NULL || head -> next == NULL) return head ;

    Node* zeroHead = new Node(-1) ;
    Node* oneHead = new Node(-1) ;
    Node* twoHead = new Node(-1) ;

    Node* zero = zeroHead ;
    Node* one = oneHead ;
    Node* two = twoHead ;

    Node* temp = head ;

    while(temp != NULL){
        if(temp -> data == 0){
            zero->next = temp ;
            zero = temp ;
        }
        else if(temp -> data == 1){
            one->next = temp ;
            one = temp ;
        }
        else{
            two->next = temp ;
            two = temp ;
        }
        temp = temp -> next ;
    }
    zero -> next = (oneHead -> next) ? oneHead -> next : twoHead -> next ;
    one -> next = twoHead -> next ;
    two -> next = NULL ;

    Node* newHead = zeroHead -> next ;
    
    delete zeroHead ;
    delete oneHead ;
    delete twoHead ;

    return newHead ;
}

// Finding the Intersection point of Y LL (Method 1) ->
Node* getIntersectionNode_1(Node* headA , Node* headB){
    map<Node* , int> mpp ;
    Node* temp = headA ;
    while(temp != NULL){
        mpp[temp] = 1 ;
        temp = temp -> next ;
    }
    temp = headB ;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            return temp ;
        }
        temp  = temp -> next ;
    }
    return NULL ;
}

// Finding the Intersection point of Y LL (Method 2) ->
Node* collisionPoint(Node* t1 , Node* t2 , int d){
    while(d){
        d-- ;
        t2 = t2 -> next ;
    }
    while(t1 != t2){
        t1 = t1 -> next ;
        t2 = t2 -> next ;
    }
    return t1 ;
}
Node* getIntersectionNode_2(Node* headA , Node* headB){
    Node* t1 = headA ;
    int n1 = 0 ;

    while(t1 != NULL){
        n1 ++ ;
        t1 = t1 -> next ;
    }

    Node* t2 = headB ;
    int n2 = 0 ;

    while(t2 != NULL){
        n2 ++ ;
        t2 = t2 -> next ;
    }

    if(n1 < n2){
        return collisionPoint(headA , headB , n2-n1) ;
    }
    else{
        return collisionPoint(headB , headA , n1-n2) ;
    }
}

// Finding the Intersection point of Y LL (Method 3) ->
Node* getIntersectionNode_3(Node* headA , Node* headB){
    if(headA == NULL || headB == NULL) return NULL ;
    Node* t1 = headA ;
    Node* t2 = headB ;

    while(t1 != t2){
        t1 = t1 -> next ;
        t2 = t2 -> next ;

        if(t1 == t2) return t1 ;
        if(t1 == NULL) t1 = headB ;
        if(t2 == NULL) t2 = headA ;
    }
    return t1 ;
}

// Add 1 to a number represented by LL (Method 1) ->
Node*  Adding_1(Node* head){
    head = reverse(head) ;
    Node* temp = head ;
    int carry = 1 ;

    while(temp != NULL){
        temp->data = temp->data + carry ;
        if(temp -> data < 10){
            carry = 0 ;
            break ;
        }
        else{
            temp -> data = 0 ;
            carry = 1 ;
        }
        temp = temp -> next ;
    }
    if(carry == 1){
        Node* newNode = new Node(1) ;
        head = reverse(head) ;
        newNode -> next = head ;
        return newNode ;
    }
    head = reverse(head) ;
    return head ;
}

// Add 1 to a number represented by LL (Method 2)->
int helper(Node* temp){
    if(temp == NULL) return 1 ;

    int carry = helper(temp -> next) ;
    temp -> data += carry ;
    
    if(temp -> data < 10) return 0 ;
    temp -> data = 0 ;
    return 1 ;
}
Node* Adding_2(Node* head){
    int carry = helper(head) ;
    if(carry == 1){
        Node* newNode = new Node(1) ;
        newNode -> next = head ;
        head = newNode ;
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

    // Putting the Odd and Even Nodes in consecutive order (Method 1)->
    // cout << "Ararnged Linkedlist is : " ;
    // head = Odd_Even(head) ;
    // print(head) ;

    // Putting the Odd and Even Nodes in consecutive order (Method 2)->
    // cout << "Ararnged Linkedlist is : " ;
    // head = OddEven(head) ;
    // print(head) ;

    // Removing the Nth node from the end of LL (Method 1)->
    // int N ;
    // cout << "Enter the number of the node to be deleted : " ;
    // cin >> N ;
    // head = removeNthFromEnd(head , N) ;
    // print(head) ;

    // Removing the Nth node from the end of LL (Method 2)->
    // int N ;
    // cout << "Enter the number of the node to be deleted : " ;
    // cin >> N ;
    // head = removeNthNodeFromEnd(head , N) ;
    // print(head) ;

    // Removing the middle node of the LL (Method 1) -> 
    // head = removeMiddleNode(head) ;
    // print(head) ;

    // Removing the middle node of the LL (Method 1) -> 
    // head = RemoveMiddleNode(head) ;
    // print(head) ;

    // Sorting the LL (Method 1) ->
    // head = Sort(head) ;
    // print(head) ;

    // Sorting the LL (Method 2) ->
    // head = Sorting(head) ;
    // print(head) ;

    // Sorting the LL containing 0 , 1 , 2 (Method 1) ->
    // head = Sort_1(head) ;
    // print(head) ;

    // Sorting the LL containing 0 , 1 , 2 (Method 2) ->
    // head = Sort_2(head) ;
    // print(head) ;

    // Adding 1 to the numerical value of LL (Method 1) ->
    // head = Adding_1(head) ;
    // print(head) ;

    // Adding 1 to the numerical value of LL (Method 2) ->
    // head = Adding_2(head) ;
    // print(head) ;

    return 0 ;
}