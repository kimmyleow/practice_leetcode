#include<stdio.h>

int digitSquareSum(int n)
{
    int sum = 0;
    while(n>0){
        int digit = n % 10; // find the right number. example 19 = 19 mod 10 = 9
        sum += digit * digit;
        n /= 10; // find the left number. example 19 = 19 % 10 = 1
    }
    return sum;
}

int isHappy(int n)
{
    while(n != 1 && n != 4)
    {
        n = digitSquareSum(n);
    }
    
    if(n==1){
        return 1; //happy
    }else{
        return 0; // not happy
    }
}

int main()
{
    int n = 19;
    
    if(isHappy(n)){
        printf("This %d is HAPPY ^^ !!\n", n);
    }else{
        printf("This %d is NOT HAPPY =( !!\n", n);
    }
    return 0;
}