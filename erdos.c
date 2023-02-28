/*
Author: Ridvik Pal
Date Modified: February 12th, 2022
File Name: Lab4Part2.c
Description: This program identifies the smallest Erdos-Woods number within a user entered domain for "a" and "k".
*/

#include <stdio.h>

//this function returns the greatest common divisor of two numbers a and b using the euclidian algorithm
int gcd(int a, int b){
    int remainder;
    while (b>0){
        remainder=a%b;
        a=b;
        b=remainder;
    }
    return a;
}

void main(){
    int aStart, aStop, kStart, kStop, bound1, bound2, a, k, i, counter=0; //define our variables

    //get the parameters for a and k from the user.  
    do{
        printf("Enter the number to start searching for k (> 2, inclusive): ");
        scanf("%d", &kStart);
    } while (kStart<=2);
    
    do{
        printf("Enter the number to stop searching for k (inclusive): ");
        scanf("%d", &kStop);
    }while (kStop<=kStart);

    do{
        printf("Enter the number to start searching for a (> 0, inclusive): ");
        scanf("%d", &aStart);
    } while (aStart<=0);

    do{
        printf("Enter the number to stop searching for a (inclusive): ");
        scanf("%d", &aStop);
    } while (aStop<=aStart);

    //start finding the Erdos number
    for (k=kStart; k<=kStop; k++){ //loop through k
        printf("Trying k = %d...\n", k);
        for (a=aStart;a<=aStop;a++){ //loop through a
            for (i=1; i<k; i++){ //loop through i for the k
                bound1 = gcd(a, a+i); //find our lower bound for erdos number
                bound2 = gcd(a+k, a+i); //find our upper bound for erdos number
                if (bound1>1 || bound2>1){
                    counter++; //increase the counter variable
                }
            }
            if (counter==(k-1)){ //if the counter variable equals the number of times i has increased, then the erdos number has been found
                printf("Erdos-Woods number: %d\n", k);
                printf("a = %d", a);
                return; //once the erdos number is found, end the main loop
            }
            counter=0; //reset the counter variable after checking
        }        
    }
    if(counter==0){ //if the counter variable is equal to 0, then no erdos number has been found.
        printf("Erdos-Woods number not found.");
    }
}
