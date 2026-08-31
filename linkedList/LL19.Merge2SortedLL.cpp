#include <iostream>
using namespace std;

// OLD TRY

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

// void insertAtTail(node *&tail , node *curr){
//     tail->next = curr;
//     tail = curr;
// }
// node* sortTwoLists(node* first, node* second)
// {
//     node *curr1 = first;
//     node *curr2 = second;
//     node *ans = new node(-1);
//     node *temp = ans;

//     while(curr1 != NULL && curr2 != NULL){
//         if(curr1->data <= curr2->data){
//             insertAtTail(temp , curr1);
//             curr1 = curr1->next;
//         }
//         else if(curr1->data > curr2->data){
//             insertAtTail(temp , curr2);
//             curr2 = curr2->next;
//         }
//     }
//     if(curr1 != NULL){
//         temp->next = curr1;
//     }
//      if(curr2 != NULL){
//         temp->next = curr2;
//     }
//     first = ans->next;
//     ans->next = NULL;
//     delete ans;
//     return first;
// }









//* Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// NEW TRY

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        ListNode *l1 = list1;
        ListNode *l2 = list2;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val > l2->val)
            {
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
            else
            {
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }
        }

        if (l1 == NULL)
        {
            temp->next = l2;
        }

        if (l2 == NULL)
        {
            temp->next = l1;
        }

        ListNode *ans = dummy->next;
        dummy->next = NULL;
        delete dummy;
        return ans;
    }
};