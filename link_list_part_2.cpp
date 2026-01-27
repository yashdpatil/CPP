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
        next = NULL;
    }
};

// given the head of a ll,remove the k-th node from thr end of the list
// and return its head
// 1,2,3,4,5 k = 2 ans =4

// 1.find the length
// 2.nth n-k+1

// 2 approch
// with use of 2 pointer

void removeKthnodefromend(Node *&head, int k)
{
    Node *ptr1 = head;
    Node *ptr2 = head;

    // move the ptr2 by k step ahead
    int count = k;
    while (count--)
    {
        ptr2 = ptr2->next;
    }
    while (ptr2 == NULL)
    { // K is equal to length of ll
        // we have to delete head node
        Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    // now ptr2 is k step ahead of ptr1
    // when ptr2 is at null (end of list),ptr1 will be at node to be deleted
    while (ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // now ptr1 is pointing to the node before kth node from end
    // node to be deleted is ptr1->next

    Node *temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    free(temp);
}

// given 2 sorted ll merge them into 1 singly ll such that the result list also sorted

void Addtohead(Node *&head, int val)
{
    Node *n1 = new Node(val);
    n1->next = head;
    head = n1;
}
// two pointer approched
// Given 2 link list Tell if they are equal or not, 2 linklist are equal if they
// have the same data and the arrangement of data is also same
bool checkequal_lst(Node *&head1, Node *&head2)
{
    Node *ptr1 = head1;
    Node *ptr2 = head2;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data != ptr2->data)
        {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return true;
}

void Display(Node *&head)
{

    Node *temp = head;

    if (temp == NULL)
    {
        return;
    }
    cout << temp->data << " ";

    Display(temp->next);
}
// GIven the head of two singly linklist headA and headB, return the node at which the two lists intersects.
// if the two link list have no intersactions at all, return null.

int main()
{
    Node *head1 = NULL;
    Addtohead(head1, 10);
    Addtohead(head1, 20);
    Addtohead(head1, 30);
    Addtohead(head1, 40);
    Addtohead(head1, 50);
    cout << " \n";
    removeKthnodefromend(head1, 5);
    Display(head1);

    Node *head2 = NULL;
    Addtohead(head2, 10);
    Addtohead(head2, 20);
    Addtohead(head2, 30);
    Addtohead(head2, 40);
    Addtohead(head2, 5);

    if (checkequal_lst(head1, head2))
    {
        std::cout << true;
    }
    else
    {
        std::cout << false;
    }

    return 0;
}