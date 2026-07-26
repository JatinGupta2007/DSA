#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(){

    }
    node(int d)
    {
        data = d;
        next = NULL;
    }

    // destructor
 ~node() {
    cout << " memory is free for node with data " << data << endl;
}

};

// IMPLEMETATION OF STACK USING LINKED LIST


// TAIL BASED STACK (TOP ELEMENT IS AT TAIL)


// void insertAtTail(node *&tail , node *&head , int d){
//     if(tail == NULL){
//          node *temp = new node(d);
//          tail = temp;
//          head = temp;
//          return;
//     }

//     node *temp = new node(d);
//     tail->next = temp;
//     tail = temp;  
// }

// void deleteNode(node *&head , node *&tail){
//     if(tail == NULL){
//         cout<<"Stack underflow"<<endl;
//         return;
//     }
//      node *curr = head;
//      node *prev = NULL;
        
//         if(curr->next == NULL){
//             delete curr;
//             tail = NULL;
//             head = NULL;
//             return;
//         }

//         while (curr->next != NULL)
//         {
//             prev = curr;
//             curr = curr->next;
//         }

//         prev->next = curr->next;
//         curr->next = NULL;
//         delete curr;
//         curr = NULL;
//         tail = prev;

// }
// class stack{

//     node *head;
//     node *tail;

//     public:

//     stack(){
//         head = NULL;
//         tail = NULL;
//     }

//     void push(int num){
//         insertAtTail(tail , head , num);
//     }

//     void pop(){
//         deleteNode(head , tail);
//     }

//     bool empty(){
//         if(head == NULL){
//             return true;
//         }
//         return false;
//     }

//     int peek(){
//         if(tail != NULL){
//         return tail->data;
//         }

//         return -1;
//     }
// };


// HEAD BASED STACK (HEAD IS THE TOP ELEMENT)

class stack {
    node *head;

public:
    stack() {
        head = NULL;
    }

    void push(int num) {
        node *temp = new node(num);
        temp->next = head;
        head = temp;
    }

    void pop() {
        if (head == NULL) {
            cout << "Stack underflow" << endl;
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
    }

    bool empty() {
        return head == NULL;
    }

    int peek() {
        if (head == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return head->data;
    }
};

int main() {
    stack s;
    s.push(5);
    s.push(10);
    s.pop();
    cout << s.peek() << endl;  // prints 5
}


