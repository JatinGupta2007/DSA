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
    head->prev = temp;             // temp->prev = NULL  &&  head->next = NULL
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
        temp->next->prev = nodeToInsert;
        temp->next = nodeToInsert;
        nodeToInsert->prev = temp;
    }


    // DELETION OF LL
    void deleteNode(int position, node *&head)
{

    // deleting first or start node
    if (position == 1)
    {
        node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        node *curr = head;
        node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = NULL;
        delete curr;
    }
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