#include<iostream>
using namespace std;

//Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next2;
    }
};

// WE ARE GIVEN A SPECIAL LINKED LIST HAVING A CHILD LINK OF EVERY NODE TOO
// ALL THE MAIN ELEMENTS HAVE CHILD LINKED LISTS ATTACHED TO THEM (THESE CHILD LL ARE SORTED IN NATURE)
// WE WILL GO AT END OF THE MAIN LINKED LIST , AND THEN MERGE THE LAST 2 SORTED VERTICAL CHILD LL
// THEN WE WILL MERGE THE 3RD LAST CHILD LL WITH THE MERGED CHILD LL OF LAST AND SECOND LAST
// WE WILL DO IT UNTIL WE COME AT HEAD AGAIN

// WE WILL USE RECURSION BACKTRACKING FOR THESE

class Solution {
public:

   // Merging two vertically sorted nodes
    ListNode *merge(ListNode *l1 , ListNode *l2){
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                temp->child = l1;
                temp = temp->child;
                l1 = l1->child;
            }
            else{
                temp->child = l2;
                temp = temp->child;
                l2 = l2->child;
            }
            temp->next = NULL;
        }
         
        if(l1 == NULL){
            temp->child = l2;
        }

        if(l2 == NULL){
            temp->child = l1;
        }

        return dummy->child;
    }

    // Recursive function 
    ListNode* flattenLinkedList(ListNode* &head) {

        // Base case and also checking edge cases
        // If we are at last we will just return head at that point
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode *mergedHead = flattenLinkedList(head->next);

        return merge(head , mergedHead);
    }
};