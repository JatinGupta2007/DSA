#include<iostream>
using namespace std;

class node{

    public:
    int data;
    node *prev;
    node *next;

    //constructor
    node(int d){
        data = d;
        prev = NULL;
        next = NULL;
    }

    
    // destructor
    ~node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};


// INSERTING AT HEAD OF THE LINKED LIST
void insertAtHead(node *&head , int d){

    // IF NODE IS NULL
    if(head == NULL){
        node *temp = new node(d);
        head = temp;  
        return;
    }


    node *temp = new node(d);
    temp->next = head;
    head->prev = temp;       // temp->prev = NULL  &&  head->next = NULL
    head = temp;
}


// INSERTING AT TAIL OF THE LINKED LIST
void insertAtTail(node *&tail , int d){
      
      // IF NODE IS Null
      if(tail == NULL){
        node *temp = new node(d);
        tail = temp;
        return;
    }


    node *temp = new node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;

}


// INSERTING AT ANY POSITION OF THE LINKED LIST
void insertAtPosition(node* &head , node* &tail , int position, int d){

        // Insert at start
        if(position == 1){
            insertAtHead(head , d);
            return;
        }

        node *temp = head;
        int count = 1;

        while(temp != NULL && count < position - 1){
            temp = temp->next;
            count++;
        }

        // out of bound
        if(temp == NULL){
            return ;
        }
        
        // Insert at end
        if(temp->next == NULL){
            insertAtTail(tail , d);
            return;
        }

        // Insert ay any k position
        node *nodeToInsert = new node(d);

        nodeToInsert->next = temp->next;
        temp->next->prev = nodeToInsert;
        temp->next = nodeToInsert;
        nodeToInsert->prev = temp;
    }


// DELETION OF LL
void deleteNode(int position, node *&head)
{
    // Empty list case
    if (head == NULL) {
        return;
    }

    // deletion at head
    if (position == 1) {
        node *temp = head;
        if (temp->next == NULL) {          // single node case
            head = NULL;
        } 
        else {
            temp->next->prev = NULL;
            head = temp->next;
        }
        temp->next = NULL;
        delete temp;
        return;
    }

    // deletion at any position (even tail)
    node *curr = head;
    node *prev = NULL;
    int cnt = 1;

    while (curr != NULL && cnt < position) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    if (curr == NULL) return;              // position out of bounds

    prev->next = curr->next;

    if (curr->next != NULL) {               // If insertion is not at end
        curr->next->prev = prev;
    }

    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}


// TRANSVERSING THE LINKED LIST
void print(node *head){
    node *temp = head;
    while(temp != NULL){
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}



// CHECKING THE LENGTH OF THE LINKED LIST
int len(node *head){
    node *temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}


int main()
{
    node *node1 = new node(5);
    node *head = node1;
    node *tail = node1;
    print(head);

    insertAtHead(head , 10);
    insertAtHead(head , 112);
    print(head);


    insertAtTail(tail , 10);
    insertAtTail(tail , 112);
    print(head);

    insertAtPosition(head , tail , 3 , 69);
    print(head);

    deleteNode(3 , head);
    print(head);
  
 
    
    
return 0;
}