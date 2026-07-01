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

private:
    void insertAtTail(Node *&head, Node *&tail, int d)
    {
        if (tail == NULL)
        {
            Node *temp = new Node(d);
            tail = temp;
            head = temp;
            return;
        }

        Node *temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }

public:
    // USING MAP

    Node *cloneLinkedList(Node *head)
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

        // Step 3 -> Making a map to make a relation b/w old
        //           and new corresponding nodes

        unordered_map<Node *, Node *> oldToNew;
        temp = head;
        Node *temp2 = cloneHead;
        while (temp != NULL)
        {
            oldToNew[temp] = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }

        // Step 4 -> Clone ke randoms ko original ke random ke
        //           corresponding mapped clone ke element ko point karvana
        temp = head;
        temp2 = cloneHead;

        while (temp != NULL)
        {
            temp2->random = oldToNew[temp->random];
            temp = temp->next;
            temp2 = temp2->next;
        }

        return cloneHead;
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

int main()
{
    return 0;
}