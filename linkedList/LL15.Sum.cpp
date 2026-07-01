#include<iostream>
#include<vector>
using namespace std;

class node{

    public:
    int data;
    node *next;

    node(){

    }
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

    node *reverse(node *head){
    node *curr = head;
    node *prev = NULL;
    node *forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

   void insertAtTail(node *&head , node *&tail, int d)
{

    // IF NODE IS Null
    if (tail == NULL)
    {
        node *temp = new node(d);
        tail = temp;
        head = temp;
        return;
    }

    
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

    node *addTwoLists(node *first , node *second){

        // STEP 1 -> Reverse both the input LL so that we can add last elements with each other
        node *curr1 = reverse(first);
        node *curr2 = reverse(second);

        // Step 2 -> MAKING a ans LL
        node *ansTail = NULL;
        node *ansHead = NULL;
        int carry = 0;


        // Step 3 -> add 2 LL

        while(curr1 != NULL || curr2 != NULL || carry != 0){

            int sum = 0;

            if(curr1 != NULL && curr2 != NULL){
                sum = curr1->data + curr2->data + carry;
            }

            else if(curr1 != NULL){
                sum = curr1->data + carry;
            }
             else if(curr2 != NULL){
                sum = curr2->data + carry;
            }
            else if(carry != 0){
                sum = carry;
            }

            int digit = sum%10;
            insertAtTail(ansHead , ansTail , digit);
            

            carry = sum/10;

            if(curr1 != NULL){
            curr1 = curr1->next;
            }

            if(curr2 != NULL){
            curr2 = curr2->next;
            }
    }

        // Step 4 -> Reversing the added LL

    node *ans = reverse(ansHead);
    return ans;
}

int main(){
    return 0;
}