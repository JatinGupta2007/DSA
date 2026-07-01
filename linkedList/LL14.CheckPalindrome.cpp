#include<iostream>
#include<vector>
using namespace std;

class node{

    public:
    int data;
    node *next;

    node(int d){
        data = d;
        next = NULL;
    }

    ~node(){
        int val = data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data " << val << endl;
    }
};


// GET MID AND REVERSE THE SECOND HALF METHOD
node *getMid(node *head){

    node *slow = head;
    node *fast = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node *reverse(node *head){
    node *curr = head;
    node *prev = NULL;
    node *forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool isPalindrome(node *head){

    if(head == NULL || head->next == NULL){
        return true;
    } 
    bool result;
    // Step 1 -> Find middle
    node *middle = getMid(head);

    // Step 2 -> Reverse second half
    node *temp = middle->next; 
    middle->next = reverse(temp);

    // Step 3 -> Compare the two halfs
    node *check1 = head;
    node *check2 = middle->next;
    while(check2 != NULL){
        if(check1->data != check2->data){
            result = false;
            break;
        }
        check1 = check1->next;
        check2 = check2->next;
    }

    // Step 4 -> Again reversing second half to get original list(optional)
    temp = middle->next;
    middle->next = reverse(temp);
    return true;
}



// COPY LIST IN AN ARRAY AND THEN JUST DO PALINDROME CHECK ON THE ARRAY;
bool isPalindrome2(node *head){
    vector<int> sol;
    node *temp = head;
    while(temp != NULL){
        sol.push_back(temp->data);
        temp = temp->next;
    }

    int i = 0;
    int j = sol.size() - 1;
    while(i<=j){
        if(sol[i] != sol[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    return 0;
}