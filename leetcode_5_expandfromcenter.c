#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//This approach is using method expand from center
//For example "babad" --> b <a> b
//Set a as reference, then check its left and right
//Need to consider odd and even length
//Time complexity O(n^2)

int expandFromCenter(char* s, int left, int right){
    int MaxLen = 0;
    
    while(left>=0 && right<strlen(s) && s[left]==s[right]){
        MaxLen = right - left + 1;
        left--;
        right++;
    }
    return MaxLen;
}

char* longestPalindrome(char* s){
    int length = strlen(s);
    int Maxlength = 1;
    int start = 0;
    int len1, len2, len, i;
    
    for(i=0; i<length;i++){
        //odd length palindrome
        len1 = expandFromCenter(s, i, i);
        
        len2 = expandFromCenter(s, i, i+1);
        
        len = len1>len2 ? len1:len2;
        
        if(len > Maxlength){
            start = i - (len - 1)/2;
            printf("start: %d\n", start);
            Maxlength = len;
        }
    }
    
    //return result
    char* result = (char*)malloc((Maxlength+1)*sizeof(char));
    strncpy(result, s + start, Maxlength); // Copy the palindrome substring
    result[Maxlength] = '\0';
    return result;
}

int main(){
    char* string = "babad";
    
    char* result = longestPalindrome(string);
    printf("The longest palindrome: %s\n", result);
    
    free(result);
    
    return 0;
}