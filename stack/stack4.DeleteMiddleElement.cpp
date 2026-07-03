#include<iostream>
#include<stack>
using namespace std;

// void deleteMiddle(stack<int>&inputStack, int N){
//    int count = 0;
//    int *arr  = new int[N/2];
//    while(count != N/2){
//       arr[count]  = inputStack.top();
//       inputStack.pop();
//       count++;
//    }
//    inputStack.pop();
   
//    count--;
//    while(count >= 0){
//       inputStack.push(arr[count]);
//       count--;
//    }
// }


// RECURSIVELY DONE;
void solve(stack<int>&inputStack, int N , int count){
   //base case
   if(count == N/2){
      inputStack.pop();
      return;
   }

   // TOP ELEMENT ALAG KARO
   int top = inputStack.top();
   inputStack.pop();


   //ANDAR JAATE RAHO JAB TAK MIDDLE NA MILE
   solve(inputStack , N , count+1);
   
   //JO TOP ALAG KIYA THA UNHE VAPAS DAALTE RAHO
   inputStack.push(top);
}


void deleteMiddle(stack<int>&inputStack, int N){
   int count = 0;
   solve(inputStack , N , count);
}

int main(){
    return 0;
}