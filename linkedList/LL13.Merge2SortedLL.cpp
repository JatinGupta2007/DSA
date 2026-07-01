#include<iostream>
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


void insertAtTail(node *&tail , node *curr){
    tail->next = curr;
    tail = curr;
}
node* sortTwoLists(node* first, node* second)
{
    node *curr1 = first;
    node *curr2 = second;
    node *ans = new node(-1);
    node *temp = ans;

    while(curr1 != NULL && curr2 != NULL){
        if(curr1->data <= curr2->data){
            insertAtTail(temp , curr1);
            curr1 = curr1->next;
        }
        else if(curr1->data > curr2->data){
            insertAtTail(temp , curr2);
            curr2 = curr2->next;
        }
    }
    if(curr1 != NULL){
        temp->next = curr1;
    }
     if(curr2 != NULL){
        temp->next = curr2;
    }
    first = ans->next;
    ans->next = NULL;
    delete ans;
    return first;
}
int main(){
    return 0;
}