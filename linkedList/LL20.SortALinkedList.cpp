#include<iostream>
using namespace std;

 // Definition for singly-linked list.
   struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
   };
 

class Solution {
public:
    ListNode *findMiddle(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head->next;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *mergeSort(ListNode *list1 , ListNode *list2){
        ListNode *l1 = list1;
        ListNode *l2 = list2;

        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while(l1 != NULL && l2 != NULL){
            if(l1->val > l2->val){
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
            else{
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }
        }

        if(l1 != NULL){
            temp->next = l1;
        }

        if(l2 != NULL){
            temp->next = l2;
        }

        temp = dummy->next;
        delete dummy;
        return temp;
    }


    // Main function
    ListNode* sortList(ListNode* head) {

        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode *middle = findMiddle(head);

        ListNode *leftHead = head;
        ListNode *rightHead = middle->next;

        middle->next = NULL;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return mergeSort(leftHead , rightHead);
    }
};