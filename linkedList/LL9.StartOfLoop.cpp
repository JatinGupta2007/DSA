#include<iostream>
#include<map>
using namespace std;

class node{

    public:
    int data;
    node *next;

    node(int d){
        data = d;
        next = NULL;
    }

    ~node(){
        int val = data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data " << val << endl;
    }
};


// FLOYED'S CYCLE DETECTION METHOD
node* intersection(node *head){

    //empty list
    if(head == NULL){
        return NULL;
    }

    
    node *fast = head;
    node *slow = head;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(fast == slow){
            return slow;
        }
    }
    return NULL;
}

node* startNode(node *head){

    node *fast = intersection(head);
    node *slow = head;

    if(fast == NULL){
        return NULL;
    }

    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main(){
    return 0;
}