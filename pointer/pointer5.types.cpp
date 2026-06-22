#include<stdio.h>
#include<stdlib.h>
int main()
{
    // WILD POINTER

    int a;
    int *ptr;   // now this uninitialised pointer is wild
    ptr = &a;  // now this is not wild

    // VOID POINTER

    void *ptrr; // This is void pointer(Datatype is not fixed)

    // NULL POINTER

    int *ptrrr = NULL;  // now this is null pointer holding value as nothing
    return 0;
}


    // DANGLING POINTER

// Case 1: Deallocation of memory location

// int main() 
// { 
//    int *ptrr=(int *)malloc(sizeof(int)); 
//    int x=80; 
//    ptrr=&x; 
//    free(ptrr); 
//    return 0; 
// } 

// Case 2: Function call (local variable)

// int *myvalue(){ 
// int a=5; 
// return &a; 
// }

// int main() 
// { 
// int *ptr=myvalue(); 
// printf("%d", *ptr); 
// return 0; 
// }   


// Case 3: If a variable goes out of scope

// int main(){
// int * danglingPtr3; 
//     {
//         int a = 12;
//         danglingPtr3 = &a;
//     }
//     return 0;
// } 

