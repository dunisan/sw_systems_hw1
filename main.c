#include "NumClass.h"

int main(){ 
    int num1,num2; 
    int i;
    printf("please enter two positive numbers: \n"); 
    scanf("%d %d", &num1, &num2);
    
    printf("The Armstorng numbers are: ");
    for(i=num1;i<=num2;i++){
        if(isArmstrong(i))
            printf("%d ", i);
    }
    printf("\n");
    
    printf("The Palindrome numbers are: ");
    for(i=num1;i<=num2;i++){
        if(isPalindrome(i))
            printf("%d ", i);
    }
    printf("\n");

    printf("The prime numbers are: ");
    for(i=num1;i<=num2;i++){
        if(isPrime(i))
            printf("%d ", i); 
    }
    printf("\n");
    
    printf("The Strong numbers are: ");
    for(i=num1;i<=num2;i++){
        if(isStrong(i))
            printf("%d ", i);
    }
    
    
    return 0;
    

}   
