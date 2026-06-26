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

// 1 ITERATIVE APPROACH
void reverse(node *head){
    node *prev = NULL;
    node *curr = head;
   

    while(curr != NULL){
        node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}
 
// BY RECURSION

void reverse(node *&head,node *&prev
              ,node *&curr){

    if(curr == NULL){
        head = prev;
        return;
    }
     
    node *forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    
    reverse(head , prev , curr);
    

}

int main()
{
    
    
return 0;
}