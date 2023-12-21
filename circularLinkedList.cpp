
// this is my first repo of code
//@kshaycodes
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int d)
    {
        this->data = d; // this ka data means current object ka data
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        int value = this->data;

        // when destructor is called for current object;
        if (this->next != NULL) // if memory is not equal to NULL then delete it
        {                       // jo memory hai next main usko delete krke NULL rakh do;
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data: " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int d)
{

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non - empty list
        // // assuming element is present in the list

        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        //   element found now current is remprsenting element wala node

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node *tail)
{
    Node *temp = tail; // not valid for single node--- so use do while loop
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;

    } while (tail != temp);

    cout << endl;
}
void deleteNode(Node *&tail, int value)
{
    // emptylist
    if (tail == NULL)
    {
        cout << "List is empty, check again" << endl;
        return;
    }
    else
    {
        // non - empty
        //    assuming that value is present in the linked list
        Node *prev = tail;
        Node *curr = prev->next; // curr ek aage hai prev ke

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 Node linked list
        if (curr == prev)
        {
            tail = NULL;
        }

        // >=2 Node linked list
        else if (tail == curr)
        {
            tail = prev;
            //  starting ka element delete krne  pr segementaion fault islia aa rha tha bcoz  "tail==prev" krdia tha
        }
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *tail = NULL; // start  aur end wali logical nahi hoti idhr

    // empty list me insert krna

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

     insertNode(tail, 5, 6);
     print(tail);

     insertNode(tail, 6, 7);
     print(tail);

    insertNode(tail, 7, 9);
    print(tail);

     insertNode(tail, 9, 10);
     print(tail);

     insertNode(tail, 3, 4);
     print(tail);

    deleteNode(tail, 3);
    print(tail);
    deleteNode(tail, 10);
    print(tail);
    deleteNode(tail, 4);
    print(tail);
    

    return 0;
}
