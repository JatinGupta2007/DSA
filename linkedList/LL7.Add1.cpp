#include<iostream>
using namespace std;

//Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};


class Solution {
public:

    int rec(ListNode* temp){

        // base case
        if(temp == NULL){
            return 1;
        }

        int carry = rec(temp->next);

        temp->val = temp->val + carry;

        if(temp->val > 9){
            temp->val = 0;
            return 1;
        }
        return 0;
    }

    ListNode *addOne(ListNode *head) {

        ListNode *temp = head;
        int carry = rec(temp);

        if(carry != 0){
            ListNode *num = new ListNode(1);
            num->next = head;
            head = num;
        }
        return head;

    }
};