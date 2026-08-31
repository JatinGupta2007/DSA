#include<iostream>
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
};

node* kReverse(node* head, int k) {


    // BASE CASE
    if(head == NULL){
        return NULL;
    }

    // CHECKING IF THE REMAINING PORTION IS LESS THEN K
    // IF IT IS LESS THAN K DON'T REVERSE IT , JUST RETURN SAME HEAD
    node *temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    if(k > count){
        return head;
    }
    
    
    // REVERSING THE FIRST K ELEMENTS OF THE LINKED LIST
    node *prev = NULL;
    node *curr = head;
    node *forward = NULL;
    int i = 0;
    while(curr != NULL && i < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        i++;
    }

    // RECURSIVELY REVERSING ALL THE OTHER PARTS
    // ATTACHING THE PARTS WITH ABOVE REVERSED LIST
    if(forward != NULL){
    head->next = kReverse(forward , k);
    }

    // PREV IS THE HEAD OF NEW REVERSED LIST
    return prev;
}
int main(){
    return 0;
}