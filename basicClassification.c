#include "NumClass.h"



int isStrong(int num){
    int temp = num; 
    int add; 
    int result = 0;
    
    while(temp>0){
        add = temp%10;
        result = result + factorial(add);
        temp = temp/10;   
    }

    if(result==num)
        return 1; 
    else
        return 0; 
}


int isPrime(int num){

    int i=0;
    if(num==1)
        return 1; 
    for(i=2;i<=(num/2);i++){
        if(num%i==0)
            return 0; 
    }
    return 1; 
}

int factorial(int num) {
   int fact = 1;
   while(num>1) {
      fact = fact * num;
      num--;
   }
   return fact;
}