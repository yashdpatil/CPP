
#include <iostream>

using namespace std;

class Node
{

public:
    int data;

    Node *next;

    Node(int val)
    {

        data = val;

        next = nullptr;
    }
};

void insertAtEnd(Node *&head, int data)
{

    Node *new_node = new Node(data);

    Node *temp = head;

    if (head == NULL)
    {

        head = new_node;

        return;
    }

    while (temp->next != NULL)

    {

        temp = temp->next;
    }

    temp->next = new_node;

    // while (head!=NULL)

    // {

    //     head = new_node;

    // }
}

// Given a head the ll determine if the ll cycle in it

bool detect_cycle(Node *&head)
{

    if (!head)
    {

        return false;
    }

    Node *slow = head;

    Node *fast = head;

    while (fast && fast->next)
    {

        slow = slow->next;

        fast = fast->next->next;

        if (slow == fast)
        {

            return true;
        }
    }

    return false;
}

void Middle_element(Node *&head)
{

    Node *slow = head;

    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {

        slow = slow->next;

        fast = fast->next->next;
    }

    cout << slow->data;
}

void Display(Node *&head)
{

    if (head == NULL)
    {

        return;
    }

    cout << head->data << endl;

    Display(head->next);
}

// GIven rotate the right list by k

void RemoveCycle(Node *&head)
{

    Node *slow = head;

    Node *fast = head;

    do
    {

        slow = slow->next;

        fast = fast->next->next;

    } while (slow != fast);

    fast = head;

    while (slow->next != fast->next)
    {

        slow = slow->next;

        fast = fast->next;
    }

    slow->next = NULL;
}

// linklist Palindrome or not

// 1.find the middle

// 2.break the  list in 2

// 3.reverse thr 2nd half of ll

// 4.compare with 1 st

bool ispalindrome(Node *head)
{

    Node *slow = head;

    Node *fast = head;

    while (fast && fast->next)
    {

        slow = slow->next;

        fast = fast->next->next;
    }

    //   2. break the middle

    Node *curr = slow->next;

    Node *prev = slow;

    slow->next = NULL;

    // reverse the second half of the list

    while (curr)
    {

        Node *nextNode = curr->next;

        curr->next = prev;

        prev = curr;

        curr = nextNode;
    }

    // chk the 2 llist are equal

    Node *head1 = head;

    Node *head2 = prev;

    while (head2)
    {

        if (head1->data != head2->data)
        {

            return false;
        }

        head1 = head1->next;

        head2 = head2->next;
    }

    return true;
}

// Rearrange of nodes in the list
//  GIven  the head of a llst, rotate the list to the right by k places

// void RotatebyK(Node *&head, int k)
// {
//     // find the length of ll
//     int n = 0;
//     // find the tail node
//     Node *tail = head;

//     while (tail->next)
//     {
//         n++;               // finding the length
//         tail = tail->next; // finding the tail node of list
//     }
//     n++; // far including last node
//     k = k % n;
//     if (k == 0)
//     {
//         cout << head;
//     }
//     tail->next = head;

//     // traverse the n-k node
//     Node *temp = head;
//     for (int i = 1; i < n - k; i++)
//     {
//         temp = temp->next;
//     }

//     //  temp is now pointing to (n-k)th node

//     Node *newhead = temp->next;
//     temp->next = NULL;
//     cout << newhead;
// }

void RotatebyK(Node *&head, int k)
{
    // Handle edge cases
    if (head == NULL || head->next == NULL || k == 0)
        return;

    // Find length and tail
    int n = 1;
    Node *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
        n++;
    }

    // Normalize k
    k = k % n;
    if (k == 0)
        return;

    // Make list circular
    tail->next = head;

    // Find new tail (n-k position)
    Node *temp = head;

    for (int i = 1; i < n - k; i++)
    {
        temp = temp->next;
    }

    // Break the circle
    head = temp->next; // Update head
    temp->next = NULL;
}

// given a list list swap every two adjust mode and return head you may not modify the values in the list

// int SwapAdjuscent(Node* &head){

// base case

// if (head == NULL || head.next == NULL){
//     return head;
// }
//     // recurssion cse
//     Node* SecondNode = head->next;
//     head->next = SwapAdjuscent(SecondNode->next);
//     SecondNode->next = head;// reverse the link between first and second node
//     return SecondNode;
// }

// At every step, you:

// Take two nodes.

// Swap them.

// Recursively do the same for the rest of the list.

// Attach the result back

void SwapAdjacent(Node *&head)
{
    // Base case
    if (head == NULL || head->next == NULL)
        return;

    Node *second = head->next;

    // Recursively swap rest
    Node *rest = second->next;
    SwapAdjacent(rest);

    // Swap current pair
    head->next = rest;
    second->next = head;

    // Update head
    head = second;
}

int main()
{

    Node *head = nullptr;

    insertAtEnd(head, 10);

    insertAtEnd(head, 20);

    insertAtEnd(head, 30);

    insertAtEnd(head, 40);

    insertAtEnd(head, 50);

    // insertAtEnd(head,60);

    // Display(head);

    // Middle_element(head);

    // Manually link the last node (60) back to the second node (20)

    // Node *temp = head;

    // while (temp->next != nullptr)
    // {

    //     temp = temp->next;
    // }

    // temp->next = head->next;

    // RemoveCycle(head);

    // std::cout << detect_cycle(head) << endl;

    // std::cout << ispalindrome(head) << endl;

    RotatebyK(head, 5);
    Display(head);

    return 0;
}
