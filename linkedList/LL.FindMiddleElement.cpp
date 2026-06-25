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


// METHOD 1 BRUTE FORCE
node *findMiddle(node *head) {
    
    int count = 0;
    node *temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }

    int  ans = count/2;
    count = 0;
    while(count < ans){
        head = head->next;
        count++;
    }
    return head;
    }



    // METHOD 2   SMART BRAIN 
    node *findMiddle(node *head) {

    node *fast = head->next;
    node *slow = head;

    while(fast!=NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

int main()
{
    
    
return 0;
}


