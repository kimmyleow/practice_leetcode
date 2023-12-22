#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Brute force method [Time complexity O(n^3)]

bool isPalindrome(char*s, int start, int end){
    while(end > start){
        if (s[start] != s[end]){
            return 0; //Not palindrome
        }
        start++;
        end--;
    }
    return 1; //is Palindrome
}

char* longestPalindrome(char* s){
    int length = strlen(s);
    int maxlength = 0;
    int start = 0;
    int i,j;
    
    for(i=0; i<length; i++){
        for(j=i; j<length; j++){
            if(isPalindrome(s, i, j) && j-i+1 > maxlength){
                start = i;
                maxlength = j-i+1;
            }
        }
    }
    
    //Create & return longest palindromic string
    char* result = (char*)malloc((maxlength+1)*sizeof(char));
    strncpy(result, s+start, maxlength);
    result[maxlength] = '\0';
    
    return result;
}


int main(){
    char inputString[] = "babad";
    
    //Find the longest palindrome substring
    char *result = longestPalindrome(inputString);
    
    //Print the result
    printf("Longest Palindromic Substring: %s\n", result);

    // Free allocated memory
    free(result);

    return 0;
}