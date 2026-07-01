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


// REPLACING THE ACTUAL LIST (HALKA METHOD)
node* sortList(node *head){

    node *curr = head;
    int zero = 0 , one = 0, two = 0;
    while(curr != NULL){
        if(curr->data == 0){
            zero++;
        }
        else if(curr->data == 1){
            one++;
        }
        else if(curr->data == 2){
            two++;
        }
        curr = curr->next;
    }
    curr = head;
    while(curr != NULL){
        
        if(zero != 0){
            curr->data = 0;
            zero--;
        }
        else if(one != 0){
            curr->data = 1;
            one--;
        }
        else if(two != 0){
            curr->data = 2;
            two--;
        }
        curr = curr->next;
    }
    
    return head;
}



// NOT REPLACING THE ACTUAL LIST , FAKE NODES METHOD 
void insertAtTail(node *&tail , node *curr){
    tail->next = curr;
    tail = curr;
}
node* sortList2(node *head){
    
    node *zeroHead = new node(-1);
    node *zeroTail = zeroHead;
    node *oneHead = new node(-1);
    node *oneTail = oneHead;
    node *twoHead = new node(-1);
    node *twoTail = twoHead;

    node *curr = head;
    while(curr != NULL){
        if(curr->data == 0){
            insertAtTail(zeroTail , curr);
        }
        else if(curr->data == 1){
            insertAtTail(oneTail , curr);
        }
        else if(curr->data == 2){
            insertAtTail(twoTail , curr);
        }
        curr = curr->next;
    }

    zeroTail->next = oneHead->next;
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

// After the loop, you have 3 separate chains (with dummy nodes at the front of each):
// zeroHead(-1) → 0 → 0 → WE don't know
// oneHead(-1)  → 1 → 1 → We don't know
// twoHead(-1)  → 2 → NULL

int main(){
    return 0;
}