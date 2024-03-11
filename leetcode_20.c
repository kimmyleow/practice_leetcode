#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char *s)
{
    int i;
    int top = -1;
    char stack_arr[10000];
    
    for(i = 0; s[i] != '\0'; i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            top = top + 1;
            stack_arr[top] = s[i];
        }else{
            if(top == -1){
                return false;
            }
            
            if((s[i]==')' && stack_arr[top]=='(') ||
               (s[i]=='}' && stack_arr[top]=='{') ||
               (s[i]==']' && stack_arr[top]=='[')) {
                   top = top - 1;
               }else{
                   return false;
               }
        }
    }
    return top == -1;
}

int main()
{
    char s[] = "[";
    if(isValid(s)){
        printf("Valid\n");
    }else{
        printf("Invalid\n");
    }

    return 0;
}