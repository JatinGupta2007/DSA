#include<iostream>
using namespace std;

// REMOVE ALL OCCURENCES OF A KEY IN A DOUBLY LINKED LIST

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


class Solution {
public:
    ListNode * deleteAllOccurrences(ListNode* head, int target) {

        ListNode* temp = head;

        while(temp != NULL){
            if(temp->val == target){

                if(temp == head){
                    head = head->next;
                }

                ListNode *forward = temp->next;
                ListNode *back = temp->prev;

                if(forward != NULL){
                    forward->prev = back;
                }

                if(back != NULL){
                    back->next = forward;
                }
                delete temp;
                temp = forward;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};