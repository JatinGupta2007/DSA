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

// Just checking we again reach the head (optimised soln)
bool isCircular(node* head){

    if(head == NULL){
        return true;
    }
    
    node *temp = head;
    do{
        if(temp == NULL){
            return false;
        }
        temp = temp->next;
    }while(temp != head);
        return true;
}

// Marking all the nodes we have visited , if we again visit the marked node , yes circular

// Not optimised
bool isCircular1(node* head){
    if(head == NULL) return true;     // empty list is circular by definition

    map<node*, bool> visited;
    node *temp = head;

    while(temp != NULL){
        if(visited[temp] == true){
            // we've seen this node before — cycle detected
            return true;   // circular only if cycle returns to head
        }
        visited[temp] = true;
        temp = temp->next;
    }

    // reached NULL — proper end, not circular
    return false;
}
int main(){
    return 0;
}
