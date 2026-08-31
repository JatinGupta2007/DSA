#include<iostream>
using namespace std;
//Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

// REMOVING DUPLICATES IN  A SORTED DOUBLY LINKED LIST

class Solution {
public:
    ListNode * removeDuplicates(ListNode *head) {

        ListNode *temp = head;

        while(temp != NULL && temp->next != NULL){
            ListNode *forward = temp->next;

            while(forward != NULL && forward->val == temp->val){
                ListNode *duplicate = forward;
                forward = forward->next;
                delete duplicate;
            }

            temp->next = forward;
            if(forward != NULL){
                forward->prev = temp;
            }
            temp = forward;
        }
        return head;

    }
};