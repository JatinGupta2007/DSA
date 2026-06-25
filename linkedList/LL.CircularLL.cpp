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

void insertNode(node *&tail , int element ,int d ){

    // empty list
    if(tail == NULL){
        node *temp = new node(d);
        tail = temp;
        temp->next = temp;
        return;
    }

    node *curr = tail;
    while(curr->data != element){
        curr = curr->next;
    }

    //element found : curr is representing element wala node 
    node *temp = new node(d);
    temp->next = curr->next;
    curr->next = temp;

}

void deleteNode(node *&tail,int element){

    //empty list
    if(tail == NULL){
        cout<<"wtf"<<endl;
        return;
    }

    node *prev = tail;
    node *curr = prev->next;

    while(curr->data != element){
        prev = curr;
        curr = curr->next;
    }
    
    // Case when there is one node only
    if(curr == prev){
        tail = NULL;
    }
    
    // More than 1 node
    if(tail == curr){
        tail = prev;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void print(node *tail){
    
    node *temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != tail);
    cout << endl;
} 


int main()
{
    node *tail = NULL;              // start empty, not with a manually created node
    insertNode(tail, 5, 5);          // first insert creates the circular single node with data 5
    insertNode(tail, 5, 10);         // now insert 10 after 5
    insertNode(tail, 10 , 12);
    insertNode(tail, 10 , 15);
    print(tail);

    deleteNode(tail , 5);
    print(tail);

    return 0;
}