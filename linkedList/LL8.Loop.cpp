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


// MAP METHOD

bool detectLoop(node *head){

    //empty list
    if(head == NULL){
        return false;
    }

    map<node* , bool> visited;
    node *temp = head;
    while(temp != NULL){
        if(visited[temp] == true){
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}


// FLOYED'S CYCLE DETECTION METHOD
bool detectLoop1(node *head){

    //empty list
    if(head == NULL){
        return false;
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
            return true;
        }
    }
    return false;
}

int main(){
    return 0;
}