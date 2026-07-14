#include<iostream>
#include<stack>
using namespace std;
class MinStack{

    private:
    stack<int> s;
    int min = INT_MAX;

    public:


    void push(int element){

        if(s.empty()){
            min = element;
            s.push(element);
        }
        else{
            if(element < min){
                s.push( 2*element - min);
                min = element;
            }
            else{
                s.push(element);
            }
        }
    }


    void pop(){
        if(s.empty()){
            cout<<"Stack underflow"<<endl;
            return;
        }
        else{
            if(s.top() < min){
                min = 2*min - s.top();
                s.pop();
            }
            else{
                s.pop();
            }
        }
    }

    int peek(){
        if(s.empty()){
            cout<<"Not present" <<endl<<"Stack is empty"<<endl;
            return -1;
        }
        else{
            if(s.top() < min){
                return min;
            }
            else{
                return s.top();
            }
        }
    }

    int getMin(){
        return min;
    }
};
