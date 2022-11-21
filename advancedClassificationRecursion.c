#include "NumClass.h"

int is_Armstrong(int num, int temp, int length);
int is_Palindrome(int num, int reverse); 


// this is the final function with one integer parameter. 
int isPalindrome(int num){
    
    return (num == is_Palindrome(num, 0));
        
    
}
//the is the real function for isPalindrome.
int is_Palindrome(int num, int reverse){
    if(num==0)
        return reverse;
    
    reverse = reverse *10; // move up the digits
    reverse = reverse + num%10; //new first digit
    num = num /10; //remove the same digit from num
    return is_Palindrome(num, reverse); 
}


//isArmstrong reccursion.(final function)
int isArmstrong(int num){
    
    int length = lengthIs(num); 
    return is_Armstrong(num, num, length);
}
//isArmostrong (real function)
int is_Armstrong(int num, int temp, int length){
    if(num==0 && temp==0)
        return 1; 
    if(num<0 || temp==0)
        return 0; 
    
    return is_Armstrong(num-power(temp%10,length), temp/10, length);

     
}

//function for power(non recursive)
int power(int num, int length){
    int sum=1;
    int i;
    for(i=0;i<length;i++)
        sum = sum * num;
    return sum; 
    }    

//function for number length(non recursive)
int lengthIs(int num){
    int count=0; 
    while(num!=0){  
       num=num/10;  
       count++;  
   }  
   return count;  
}
