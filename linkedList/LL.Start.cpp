#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int d){
        data = d;
        next = NULL;
    }
};

    void insertAtHead(node* &head , int d){
        node *temp = new node(d);
        temp->next = head;
        head = temp;
    }

    void insertAtTail(node* &tail , int d){
        node *temp = new node(d);
        tail->next = temp;
        tail = temp;
        
    }

    void insertAtPosition(node* &head , node* &tail , int position, int d){
        // Insert at start
        if(position == 1){
            insertAtHead(head , d);
            return;
        }

        node *temp = head;
        int count = 1;

        while(count < position - 1){
            temp = temp->next;
            count++;
        }
        
        // Insert at end
        if(temp->next == NULL){
            insertAtTail(tail , d);
            return;
        }

        node *nodeToInsert = new node(d);

        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }
    
    void print(node *head){
        node *temp = head;
        while(temp != NULL){
            cout << temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

int main()
{
    node *node1 = new node(5); 
    node *head = node1;
    node *tail = node1;
    print(head);

    // INSERTING AT HEAD
    insertAtHead(head,15);
    insertAtHead(head,20);
    print(head);

    // INSERTING AT TAIL
    insertAtTail(tail , 15);
    insertAtTail(tail , 20);
    print(head);

    // INSERTING AT A PARTICULAR POSITION
    insertAtPosition(head,tail,6,69);
    print(head);

    return 0;
}