// using 2 pointer method [time O(n), space O(1)]
void reverseString(char* s, int sSize) {
    int start = 0;
    int end = sSize - 1;

    while(end > start){
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }

}