#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution
{

public:
    // USING MAP

    Node *cloneLinkedList(Node *head)
    {

        // Step 1 -> Make a dummy node

        Node *dummy = new Node(-1);

        // Step 2 -> Copying the original LL in clone LL and marking a relation betwwn the 
        //           corresponding nodes using a hashmap

        Node *temp = head;
        Node *temp2 = dummy;

        unordered_map<Node *, Node *> oldToNew;

        while (temp != NULL)
        {
            Node *newNode = new Node(temp->data);
            temp2->next = newNode;
            oldToNew[temp] = newNode;

            temp2 = temp2->next;
            temp = temp->next;
        }

        // Step 2 -> Clone ke next and randoms ko original ke next and randoms le according link karna using map

        temp = head;
        temp2 = dummy->next;

        while (temp != NULL)
        {
            temp2->next = oldToNew[temp->next];
            temp2->random = oldToNew[temp->random];
            temp = temp->next;
            temp2 = temp2->next;
        }

        temp2 = dummy->next;
        delete dummy;
        return temp2;
    }





    // WITHOUT ANY EXTRA SPACE
    Node *cloneLinkedList2(Node *head)
    {

        // Step 1 -> Make a clone linked list

        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        // Step 2 -> Copying the original LL in clone LL
        Node *temp = head;

        while (temp != NULL)
        {

            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // Step 3 -> Changing links of ll
        Node *originalNode = head;
        Node *cloneNode = cloneHead;
        while (originalNode != NULL)
        {

            Node *forward = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = forward;

            forward = cloneNode->next;

            cloneNode->next = originalNode;
            cloneNode = forward;
        }

        // Step 4 -> Copying the random pointer stuff

        originalNode = head;
        while (originalNode != NULL)
        {
            if (originalNode->random != NULL)
            {
                originalNode->next->random = originalNode->random->next;
            }
            originalNode = originalNode->next->next;
        }

        // Step 5 -> Reverting the links we changed

        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != NULL)
        {

            Node *temp = cloneNode->next;
            originalNode->next = temp;
            originalNode = temp;

            if (originalNode != NULL)
            {
                cloneNode->next = originalNode->next;
                cloneNode = originalNode->next;
            }
            else
            {
                cloneNode->next = NULL; 
            }
        }

        return cloneHead;
    }
};

