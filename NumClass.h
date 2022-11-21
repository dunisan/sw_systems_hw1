#include <stdio.h>
#include <string.h> 


/* will return if a number is Armstrong number
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits. ForExample:407 = 43 + 03 +73 =64 + 0 +343 = 407
*/

int isArmstrong();

/* will return if a number is a palindrome */
int isPalindrome();


/* will return if a number is prime */
int isPrime();

/*Strong number is a special number whose sum of the factorial of digits is equal to the original number. For Example: 145 is strong number
145= !5+ !4+ !1 I*/
int isStrong();

/* Will return the factorial of a number */
int factorial(int r);

/* return the length of a number (123 = 3, 858738 = 6) */
int lengthIs(int num);

/*will return the power of num*/
int power(int num, int length);
