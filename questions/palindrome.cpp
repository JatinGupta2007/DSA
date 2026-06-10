class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0){
            return false;
        }

        int num =x,digit=0;
        while(num!=0){
            num = num/10;
            digit++;
        } 

        int num2 = x;
        long int newNum=0;

        while(num2!=0){
            newNum = newNum + (pow(10 , (digit -1))*(num2%10));
            num2 = num2/10;
            digit--;
        }

        if(newNum == x){
            return true;
        }
        return false;
        
    }
};