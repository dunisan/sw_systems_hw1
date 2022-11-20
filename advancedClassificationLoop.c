#include "NumClass.h"



int isPalindrome(long int num){
    int start,end; 
    long int temp = num; 
    char palind[100]; // Abuffer to change the number to a srting
    int index = 0; // Index fo buffer 

    //convert the digit to cahr and put them into the buffer
    while(temp!=0){
        palind[index++] = temp%10 + '0';
        temp=temp/10; 
    }

    //check if the string is palindrome
    for(start=0,end=index-1; start<end; start++, end--){
        if(palind[start] != palind[end])
            return 0;
    }
    return 1;
}


int isArmstrong(int num){
    int length = lengthIs(num); //check num of digits in the given num
    int i; // index of for loop
    int totalSum=0; 
    int tempSum;  // The sum of every digit in power of the length
    int temp=num;

    // sum up the power of length for every digit 
    while(temp!=0){
        tempSum=1;
        for(i=0;i<length;i++){
            tempSum = tempSum * (temp%10);
        }    
        totalSum = totalSum+tempSum;
        temp = temp/10; // move to the next digit  
    } 

    if(totalSum == num)
        return 1;
    else    
        return 0;
}

int lengthIs(int num){
    int count=0; 
    while(num!=0){  
       num=num/10;  
       count++;  
   }  
   return count;  
}
