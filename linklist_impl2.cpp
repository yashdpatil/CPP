// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node *next;
    
    Node(int data){
        val = data;
        next = NULL;
    }
    
};
void InsertAThead(Node* &head,int data){
  
    Node* n1 = new Node(data);
        n1->next = head;
    head = n1;
    //head = n1;
    
}

void DeleteAThead(Node* &head){
  Node *temp = head;
  head = head->next;
  free(temp);
}


void DeleteAtEnd(Node* &head){
  Node *temp = head;
  
  while(temp->next->next != NULL){
    temp = temp->next;
    
  }
  
  Node *del = temp->next;
  temp->next= NULL;
  free(del);
}
void UpdateATNode(Node* &head,int k,int val){
  Node* temp = head;
  int pos = 0;
  while(pos != k){
    temp = temp->next;
    pos++;
  }
  temp->val = val;
}

void InsertATEnd(Node* &head,int data){
    Node *temp = head;
    Node* n1 = new Node(data);
    if(head == NULL){
    head = n1;
    return;
  }
    while(temp->next!= NULL){
      temp = temp->next;
    }
    temp->next = n1;
    
}

void InsertATMiddle(Node* &head,int data,int k){
    Node *temp = head;
    Node* n1 = new Node(data);
    int pos = 0;
    while(pos != k-1){
      temp = temp->next;
      pos++;
      
    }
    n1->next=temp->next;
    temp->next= n1;
    
}
void Kdelete(Node* &head,int k){
  Node*temp = head;
  // Node*curr_index = head;
   int pos = 0;
   while(pos != k-1){
     temp = temp->next;
     pos++;
   }
   Node*curr_index = temp->next;
   temp->next = temp->next->next;
   free(curr_index);
  
}

void Alternative(Node* &head){
  Node* temp = head;
  while(temp != NULL && temp->next!=NULL){
    Node* del = temp->next;
    temp->next = temp->next->next;
    free(del);
    temp = temp->next;
  }
  
}

// void reversing_a_lin_list(Node* &head){
//   Node* prevptr =NULL;
//   Node* currtr =head;
  
//   //currptr->nxt =prevptr;
//   //move all 3 pointrs by one step InsertAThead
  
//   while(currptr!=NULL){
//     Node* next_ptr = currptr->next;
//     currptr->next = prevptr;
//     prevptr=currptr;
//     currptr= next_ptr;
//   }
  
//   // when the llops end prevptr pointing to mylat node which is ne whead
//   Node* new_head = prevptr;
//   cout<<new_head-
// }



void reversing_a_lin_list(Node* &head) {
    Node* prevptr = nullptr; // Modern C++ uses nullptr
    Node* currptr = head;    // Fixed spelling: currtr -> currptr

    while (currptr != nullptr) {
        Node* next_ptr = currptr->next; // Temporarily store next node
        currptr->next = prevptr;       // Reverse the link
        
        // Move all pointers one step forward
        prevptr = currptr;
        currptr = next_ptr;
    }

    // Update the head reference to point to the new start (old tail)
    head = prevptr; 
    
    // Optional: Print the new head's data
    if (head != nullptr) {
        std::cout << "New Head Data: " << head->val << std::endl;
    }
}



void Display(Node* &head){
    if(head == NULL){
        return;
    }
    
   // cout<<"inside head pointer"<<head->val <<" next"<<head->next<<endl;
    
       cout<<head->val<<endl;
    Display(head->next);
     

}

// void Duplicate_sorted_data(Node* &head){
//   Node *temp = head;
//   while(temp){
//     while(temp->next!= NULL && temp->val == temp->next->val){
//       Node* &del = temp->next;
//       temp->next = temp->next->next;
//       free(del);
//     }
//     temp = temp->next;
//   }
// }

void Duplicate_sorted_data(Node* &head) {
    if (head == nullptr) return; // Edge case: empty list

    Node* temp = head;
    while (temp->next != nullptr) {
        if (temp->val == temp->next->val) {
            // Fix 1: Store the duplicate node to be deleted
            Node* toDelete = temp->next;
            
            // Fix 2: Bypass the duplicate node
            temp->next = temp->next->next;
            
            // Fix 3: Use 'delete' for 'new' nodes (not free)
            delete toDelete; 
            
            // Note: Do NOT move temp here; check the NEW temp->next next loop
        } else {
            // Only move forward if no deletion occurred
            temp = temp->next;
        }
    }
}

Node* reverseRecursive(Node* head) {
    // Base Case: empty list or only one node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Recursive Step: Reverse the rest of the list
    Node* newHead = reverseRecursive(head->next);

    // Rewire the pointers
    head->next->next = head; // Make the next node point back to current
    head->next = nullptr;    // Set current's next to null to break old link

    return newHead;
}

// // Given the head of a linklist reverse the nodes of tje list k at a time and return the modified list

// void reversell(Node* &head,int k){
//   Node* prevptr = NULL;
//   Node* currptr = head;
//   int counter = 0; // for counting first k nodes
  
//   while(currptr != NULL && counter<k){ //reverse the first k nodes
//     Node*  next_ptr = currptr ->next;
//     currptr->next = prevptr;
//     prevptr = currptr;
//     currptr = next_ptr;
//     counter++;
//   }
//   //currptr will give us (k+1)th Node
//   if(currptr != NULL){
//     Node* newHead =reversell(currptr,k);
//     head->next = newHead;
//   }
//   return prevptr; // give the new head of connected linklist
// }


void reversell(Node* &head, int k) {
    if (head == nullptr || k <= 1) return;

    // 1. Safety check: Do we have k nodes? 
    // (Optional: remove this if you want to reverse even partial groups)
    Node* check = head;
    for (int i = 0; i < k; i++) {
        if (!check) return; 
        check = check->next;
    }

    Node* prevptr = nullptr;
    Node* currptr = head;
    Node* next_ptr = nullptr;
    int counter = 0;

    // 2. Reverse first k nodes
    while (currptr != nullptr && counter < k) {
        next_ptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = next_ptr;
        counter++;
    }

    // 3. Prepare for recursion
    // At this point:
    // 'head' is the tail of the current reversed segment.
    // 'next_ptr' is the start of the remaining list.
    // 'prevptr' is the new head of the current reversed segment.

    if (next_ptr != nullptr) {
        // Create a temporary pointer to the next segment
        Node* nextSegmentHead = next_ptr;
        
        // Recursive call updates 'nextSegmentHead' to its new reversed head
        reversell(nextSegmentHead, k);
        
        // Link the current segment's tail (original head) to the next segment's new head
        head->next = nextSegmentHead;
    }

    // 4. Final Step: Update the reference 'head' to the new head of this segment
    head = prevptr;
}

int main() {
   
    Node *head = NULL;
    // InsertAThead(head,10);
    // InsertAThead(head,20);
    // InsertAThead(head,30);
    // InsertAThead(head,40);
    // InsertAThead(head,50);
    // InsertATMiddle(head,25,3);
    // UpdateATNode(head,3,27);
  // DeleteAThead(head);
       InsertATEnd(head,10);
       InsertATEnd(head,10);
       InsertATEnd(head,20);
       InsertATEnd(head,30);
       InsertATEnd(head,50);
      // Display(head);
  //DeleteAtEnd(head);
  //Kdelete(head,3);
//  Alternative(head);
Duplicate_sorted_data(head);
    Display(head);
    
   // reversing_a_lin_list(head);
   reversell(head,2);

     Display(head);
    
    // Write C++ code here
    std::cout << "Try programiz.pro";
    

    return 0;
}