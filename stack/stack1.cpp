#include<iostream>
//#include<stack>
using namespace std;

// This is not normal stack , this is made by us
// Implementation of stack is done using arrays;
class stack{

    private:
    int *arr;
    int top;
    int size;

    public:

    // Constructor
    stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }


    void push(int element){
        if(top < size - 1){
        top++;
        arr[top] = element;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }


    void pop(){
        if(top == -1){
            cout<<"Stack underflow"<<endl;
            return;
        }
        top--; 
    }


    bool empty(){
        if(top == -1){
            return true;
        }
        return false;
    }


    int peek(){
        if(top == -1){
            cout<<"Not present" <<endl<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
};

 int main()
 {
//     stack<int> s;
//     s.push(5);
//     s.push(2);
//     s.push(69);
//     s.push(1);
//     cout<<"Size of current stack is "<<s.size()<<endl;

//     s.pop();
//     cout<<"Top element of current stack is "<<s.top()<<endl;

//     if(s.empty()){
//         cout<<"Stack is empty"<<endl;
//     }
//     else{
//         cout<<"Stack is not empty"<<endl;
//     }

stack s(5);
s.push(69);
s.push(67);
s.push(100);
s.push(2);

cout<<"Top element is "<<s.peek()<<endl;
s.pop();
cout<<"Top element is "<<s.peek()<<endl;
s.pop();
cout<<"Top element is "<<s.peek()<<endl;
s.pop();
cout<<"Top element is "<<s.peek()<<endl;
s.pop();
cout<<"Top element is "<<s.peek()<<endl;
s.pop();

    
return 0;
}