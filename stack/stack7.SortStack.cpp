#include<iostream>
#include<stack>
using namespace std;


void insertSorted(stack<int> &stack , int top){
	//base case
	if(stack.empty()){
		stack.push(top);
		return;
	}


    // AGAR TOP ELEMENT CHOOTA HO TO AUR ANDAR JAO
	if(stack.top() > top){
         
        // ISKA TOP ALAG KARO
		int a = stack.top();
		stack.pop();
        
        // RECURSIVELY ANDAR JAO JAB TAK ELEMENT ADD NA KARLO
		insertSorted(stack , top);

        // JO UPAR WAALE THEE UNHE VAPAS DAL DO
		stack.push(a);
	}


    // AGAR TOP ELEMENT BADA HO TO RUK JAO KAM HOGYA
	else if(stack.top() <= top){
		stack.push(top);
		return;
	}
	
}

void solve(stack<int> &stack){
	//base case
	if(stack.empty()){
		return;
	}


    //SIDE MAI RAKHA TOP ELEMENT
	int top = stack.top();
	stack.pop();

    //RECURSION SORT KARDEGA
	solve(stack);
    
    // TOP ELEMENT KO SORTED INSERT KIYA
	insertSorted(stack , top);
}
void sortStack(stack<int> &stack)
{
	solve(stack);
	
}