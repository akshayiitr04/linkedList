//@kshaycodes
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // Constructor
    Node(int d)
    {
        this->data = d;

        // both pointers are set to be NULL
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data: " << value << endl;
    }
};

// traversing a linked list
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// gives the lenght of Linked List
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

//  by reference pass krna kabhi bhi value ko
void insertAtHead(Node *&tail, Node *&head, int d)
{
    // if empty list
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {

        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&tail, Node *&head, int d)
{

    // if empty list ho then if wala statement
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        // new node create
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = tail->next; // or tail = temp; kyunki jo "temp" hai vo "tail next" ke barabar hai
    }
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d) // 'd' is the data to be inserted.......
{
    //  INSERT AT START

    // agr insert at start pr kam na kre then then use  below four lines of code

    if (position == 1)
    {
        insertAtHead(tail, head, d);
        return;
    }

    // insert new node at the middle
    Node *temp = head;

    int cnt = 1; // jidhr se position of node start ho rhi hai....

    while (cnt < position - 1) // (n-1) node tak jayenge....
    {
        temp = temp->next;
        cnt++;
    }

    // Inserting at Last Position

    if (temp->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }

    //  creating a node for d--data to insert in the middle,,,
    Node *nodeToInsert = new Node(d);

    // sare pointers ko sahi jagah pr la diya --code to tab bhi kam krta but pointers must be asssigned at right place
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int position, Node *&head, Node *&tail)
{
    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next; // head ko aage point kra diya
        temp->next = NULL;
        // memeory free start node
        delete temp; // ---write destructor for this in node class---
    }
    // else if(tail == NULL)
    // {
    //     Node *temp = tail;

    //     temp->prev->next = NULL; // head ko aage point kra diya
    //     temp = temp->prev;
    //     temp->prev = NULL;
    //     // memeory free start node
    //     delete temp; // ---write destructor for this in node class---
    // }
    else
    { // start main head node pr tha and then prev. tk gya and then point kr diya

        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            // har iteration main curr and prev(make equal to ex curr.) ko aage badha do
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        // current wale ko bhi free kr diya
        delete curr;
    }
}

int main()
{
    // Node *node1 = new Node(20);
    // Node *head = node1;
    // Node *tail = node1;

    // if agr starting main empty list ho then
    Node *head = NULL;
    Node *tail = NULL;

    // print(head);

    // insertAtHead(head, 40);
    // insertAtHead(head, 65);
    // insertAtHead(head, 85);

    insertAtTail(tail, head, 40);
    insertAtTail(tail, head, 65);
    insertAtTail(tail, head, 85);

    print(head);
    insertAtPosition(tail, head, 2, 29);
    insertAtPosition(tail, head, 5, 99);
    print(head);
    cout << "Size of list is: " << getLength(head) << endl;

    deleteNode(5, head, tail);
    print(head);
    cout << "Size of list is: " << getLength(head) << endl;

    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    return 0;
}