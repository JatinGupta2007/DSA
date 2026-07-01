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


// SORTED LIST KE LIYE
node * removeDuplicates(node *head)
{
    node *temp = head;

    while(temp != NULL && temp->next != NULL){

        if(temp->data == temp->next->data){
            node *duplicate = temp->next;
            temp->next = temp->next->next;
            delete duplicate;
        }
        else{
            temp = temp->next;
        }
    }

    return head;
}


// UNSORTED LIST KE LIYE (BRUTE FORCE)
node *removeDuplicates(node *head)
{
    if(head == NULL){
        return NULL;
    }
    node *temp = head;
    while(temp != NULL && temp->next != NULL){
        node *curr = temp->next;
        while(curr != NULL && curr->next != NULL){
            if(curr->next->data == temp->data){
               node *duplicate = curr->next;
               curr->next = curr->next->next;
               delete duplicate;
            }
            else{
                curr = curr->next;
            }
        }
        temp = temp->next;
    }
    return head;
}

// MAP METHOD
node *removeDuplicates(node *head)
{
    if(head == NULL){
        return NULL;
    }
    map<int , bool> visited;
    node *temp = head;
    visited[temp->data] = true;
    while(temp->next != NULL){
        if(visited[temp->next->data] == true){
               node *duplicate = temp->next;
               temp->next = temp->next->next;
               delete duplicate;
        }
        else{
            visited[temp->next->data] = true;
        }
        temp = temp->next;
    }
    return head;

}

int main(){
    return 0;
}