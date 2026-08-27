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


node* deleteHead(node* &head){
    if(head == NULL) return NULL;

    if(head->next == NULL){
        head = NULL;
        delete head;
        return NULL;
    }

    node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    return head;
}

node* deleteAtAnyPos(node* &head, int k){
    if(head == NULL) return NULL;

    if(k == 1){
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }

    int count = 1;
    node* curr = head;
    node* prev = NULL;

    while(curr != NULL && count != k){
        prev = curr;
        curr = curr->next;
        count++;
    }

    if(curr == NULL) return head;   // k out of bounds — nothing to delete

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    return head;
}

node* insertAtHead(node* &head , int d){
    
    node *temp = new node(d);
    temp->next = head;
    head = temp;
    return head;
}

node* insertAtAnyPos(node* &head , int d , int k){
    
    node* temp = new node(d);

    if(k == 1){
        temp->next = head;
        head = temp;
        return head;
    }

    int count = 1;
    node *curr = head;
    node *prev = NULL;

    while(curr != NULL && count < k){
        prev = curr;
        curr = curr->next;
        count++;
    }

    if(prev == NULL || count < k){
        delete temp;
        return head;
    }

    prev->next = temp;
    temp->next = curr;
    return head;
}