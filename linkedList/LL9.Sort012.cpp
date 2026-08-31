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




// NOT REPLACING THE ACTUAL LIST , DUMMY NODES METHOD (OPTIMISED SOLN)

class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};


class Solution {
    public:
        ListNode* sortList(ListNode* &head) {
            if(head == NULL || head->next == NULL){
                return head;
            }

            ListNode *curr = head;

            ListNode *temp1 = new ListNode(-1);
            ListNode *temp2 = new ListNode(-1);
            ListNode *temp3 = new ListNode(-1);

            ListNode *t1 = temp1;
            ListNode *t2 = temp2;
            ListNode *t3 = temp3;

            while(curr != NULL){

                if(curr->data == 0){
                    temp1->next = curr;
                    temp1 = temp1->next;
                }
                else if(curr->data == 1){
                    temp2->next = curr;
                    temp2 = temp2->next;
                }
                else{
                    temp3->next = curr;
                    temp3 = temp3->next;
                }
                curr = curr->next;
            }

            temp1->next = (t2->next != NULL) ? t2->next : t3->next;
            temp2->next = t3->next;
            temp3->next = NULL;

            ListNode *newHead = t1->next;
            delete t1;
            delete t2;
            delete t3;
            return newHead;
        }
};

// After the loop, you have 3 separate chains (with dummy nodes at the front of each):
// zeroHead(-1) → 0 → 0 → WE don't know
// oneHead(-1)  → 1 → 1 → We don't know
// twoHead(-1)  → 2 → NULL


int main(){
    return 0;
}