#include<iostream>
#include<stack>
using namespace std;

void insertBelow(stack<int>& myStack, int x , int count){
    //base case
    if(myStack.empty()) {
        myStack.push(x);
        return;
    }

    int top = myStack.top();
    myStack.pop();
    insertBelow(myStack , x , count+1 );

    myStack.push(top);

} 

void reverseStack(stack<int> &stack) {

    // base case
    if(stack.empty()){
        return ;
    }
    
    // ALAG RAKHA TOP ELEMENT
    int top = stack.top();
    stack.pop();

    // RECURSION NE STACK REVERSE KARDIA
    reverseStack(stack);

    // TOP ELEMENT KO SABSE NICHE DAALDO
    insertBelow(stack , top , 0);
    
}
int main(){
    return 0;
}

