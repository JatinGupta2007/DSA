#include <iostream>
using namespace std;


// This will not swap a and b
void swap(int a, int b)
{                                     // temp a b
    int temp = a;                     // 4   4  5
    a = b;                            // 4   5  5
    b = temp;                         // 4   5  4
}

// Call by reference using pointers
void swapPointer(int *a, int *b)
{                                     // temp a b
    int temp = *a;                    // 4   4  5
    *a = *b;                          // 4   5  5
    *b = temp;                        // 4   5  4
}

// Call by reference using C++ reference Variables

////int &
void swapReferenceVar(int &a, int &b)
{                                     // temp a b
    int temp = a;                     // 4   4  5
    a = b;                            // 4   5  5
    b = temp;                         // 4   5  4
   ////  return a;
}


int main()
{
    int x = 4, y = 5;
    cout << "The value of x is " << x << " and the value of y is " << y << endl;
    // swap(x, y);                                        
    // swapPointer(&x, &y);                              
    swapReferenceVar(x, y);                               
//// swapReferenceVar(x, y) = 766;                        
   cout << "The value of x is " << x << " and the value of y is " << y << endl;
    
    return 0;
}

//RETURN BY REFERENCE
//BAD PRACTISE

// int& func(int a) {
//     int num = a;
//     int& ans = num;
//     return ans;
// }


// int* fun(int n) {
//     int* ptr = &n;
//     return ptr;
// }
