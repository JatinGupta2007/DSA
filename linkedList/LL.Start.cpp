#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }

    // destructor
    ~node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};


// INSERTING AT HEAD OF LL
void insertAtHead(node *&head, int d)
{

    // IF NODE IS NULL
    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
        return;
    }

    node *temp = new node(d);
    temp->next = head;
    head = temp;
}


// INSERTING AT TAIL OF LL
void insertAtTail(node *&tail, int d)
{

    // IF NODE IS Null
    if (tail == NULL)
    {
        node *temp = new node(d);
        tail = temp;
        return;
    }


    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}


// INSERTING AT ANY POSITION OF LL

void insertAtPosition(node *&head, node *&tail, int position, int d)
{
    // Insert at start
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    node *temp = head;
    int count = 1;

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // Insert at end
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    node *nodeToInsert = new node(d);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}



// DELETION OF LL
void deleteNode(int position, node *&head)
{

    // deleting first or start node
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        // memory free start node
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        node *curr = head;
        node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


// TRANSVERSING THE LL
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *node1 = new node(5);
    node *head = node1;
    node *tail = node1;
    print(head);

    // INSERTING AT HEAD
    insertAtHead(head, 15);
    insertAtHead(head, 20);
    print(head);

    // INSERTING AT TAIL
    insertAtTail(tail, 15);
    insertAtTail(tail, 20);
    print(head);

    // INSERTING AT A PARTICULAR POSITION
    insertAtPosition(head, tail, 6, 69);
    print(head);

    deleteNode(6, head);
    print(head);

    return 0;
}