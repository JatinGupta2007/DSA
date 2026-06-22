// 1. Object-Like Macros

#include <stdio.h>

// Macro definition
#define DATE 31

int main(){
  
    // Print the message
    printf("Lockdown will be extended"
           " upto %d-MAY-2020",
           DATE);
    return 0;
}


// 2. Chain Macros

// #include <stdio.h>
 
// // Macro definition
// #define INSTAGRAM FOLLOWERS
// #define FOLLOWERS 138

// int main(){
//     printf("Geeks for Geeks have %dK"
//            " followers on Instagram",
//            INSTAGRAM);
 
//     return 0;
// }




// 3. Multi-Line Macros

// #include <stdio.h>

// // Multi-line Macro definition
// #define ELE 1, \
//             2, \
//             3

// int main(){

//     // Array arr[] with elements
//     // defined in macros
//     int arr[] = { ELE };
//     for (int i = 0; i < 3; i++) {
//         printf("%d  ", arr[i]);
//     }
//     return 0;
// }



// 4. Function-Like Macros

// #include <stdio.h>

// // Function-like Macro definition
// #define min(a, b) (((a) < (b)) ? (a) : (b))

// int main(){

//     // Given two number a and b
//     int a = 18, b = 76;

//     printf("Minimum: %d", min(a, b));

//     return 0;
// }