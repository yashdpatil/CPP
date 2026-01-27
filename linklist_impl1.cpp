#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};
void InsertAtHead(Node *&head, int data) // -->o(N)
{

    Node *n = new Node(data);
    n->next = head;
    head = n;
}
void InsertAtpos(Node *&head, int val, int pos)
{
    Node *n = new Node(val);
    if (pos == 0)
    {
        InsertAtHead(head, val);
        return;
    }

    Node *temp = head;
    int curr_pos = 0;
    while (curr_pos != pos - 1)
    {
        temp = temp->next;
        curr_pos++;
    }
    n->next = temp->next;
    temp->next = n;
    // temp is pointing to node at pos-1
}
void InsertAtEnd(Node *&head, int data) //-- > o(N) of i have tail pointer o(1)
{
    Node *temp = head;
    Node *n = new Node(data);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    // n->next = NULL;
}

void updateAtpos(Node *&head, int k, int val) //-->O[k]
{
    Node *temp = head;
    int curr_poss = 0;
    while (curr_poss != k)
    {
        temp = temp->next;
        curr_poss++;
    }
    // temp will be pointing to the kth nOde
    temp->val = val;
}

void deleteeathead(Node *&head) // 0(1)
{
    Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteelast(Node *&head)
{
    Node *second_last = head;
    while (second_last->next->next != NULL)
    {
        second_last = second_last->next;
        /* code */
    }
    // now second last points to theaecond last node
    Node *temp = second_last->next; // node to be deleted
    second_last->next = NULL;
    free(temp);
}
void kdelete(Node *&head, int pos)
{
    if (pos == 0)
    {
        deleteeathead(head);
        return;
    }
    int curr_pos = 0;
    Node *prev = head;
    while (curr_pos != pos - 1)
    {
        prev = prev->next;
        curr_pos++;
    }
    Node *temp = prev->next;
    prev->next = prev->next->next;
    free(temp);
}
void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

void deleteduplicate_Sort_list(Node *&head)
{ /// o(n)
    Node *curr_node = head;
    while (curr_node)
    {
        while (curr_node->next != NULL && curr_node->val == curr_node->next->val)

        {
            // delete curr_node->next
            /* code */
            Node *temp = curr_node->next;
            curr_node->next = curr_node->next->next;
            free(temp);
        }

        // this loop ends when curr node and next node value are differenet;
        // or ll ends
        curr_node = curr_node->next;
    }
}

void AlternativeDelete(Node *&head)
{
    Node *curr_ele = head;
    while (curr_ele != NULL && curr_ele->next != NULL)
    {
        Node *temp = curr_ele->next; // to delete
        curr_ele->next = curr_ele->next->next;
        free(temp);
        curr_ele = curr_ele->next;
    }
}

void Reverse_order(Node *head)
{
    if (head == NULL)
    {
        return;
        /* code */
    }

    Reverse_order(head->next);
    cout << head->val;
}

// reversing a linklist

int main()
{
    // Node *n = new Node(1); 1st method to add make a node class and call this
    // cout << n->val << " " << n->next << endl;
    Node *head = NULL;
    InsertAtHead(head, 10);
    InsertAtHead(head, 20);
    InsertAtHead(head, 30);
    InsertAtHead(head, 30);
    InsertAtHead(head, 30);
    InsertAtHead(head, 40);
    InsertAtEnd(head, 100);
    InsertAtpos(head, 50, 4);

    display(head);
    cout << endl;
    updateAtpos(head, 3, 25);
    display(head);

    /// delete
    cout << "delte cases" << endl;
    deleteeathead(head);
    display(head);
    deleteelast(head);
    display(head);
    cout << "at pos" << endl;
    kdelete(head, 2);
    cout << endl;
    display(head);
    cout << endl;

    AlternativeDelete(head);
    display(head);

    // delete
    deleteduplicate_Sort_list(head);
    display(head);
    cout << endl;

    cout << "reverse" << endl;
    Reverse_order(head);

    return 0;
}