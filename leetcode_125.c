
// function to covert lower case ASCII
// convert lowercase +0x20
// convert uppercase -0x20
char convert2lower(char ch){
    if(ch >= 'A' && ch <= 'Z')
    {
        ch = ch + 0x20;
    }
    return ch;
}

bool isPalindrome(char * s){
    int len = strlen(s);
    int left = 0;
    int right = len - 1;

    while(right > left){

        // check alphanumeric in left in terms of ASCII
        if((s[left] >= '0' &&  s[left] <= '9') 
        || (s[left] >= 'a' &&  s[left] <= 'z')
        || (s[left] >= 'A' &&  s[left] <= 'Z'))
        {
            if(s[left] >= 'A' &&  s[left] <= 'Z'){
                s[left] = convert2lower(s[left]);
            }
        }else{
            left++;
            continue;
        }

        // check alphanumeric in right in terms of ASCII
        if((s[right] >= '0' &&  s[right] <= '9') 
        || (s[right] >= 'a' &&  s[right] <= 'z')
        || (s[right] >= 'A' &&  s[right] <= 'Z'))
        {
            if(s[right] >= 'A' &&  s[right] <= 'Z'){
                s[right] = convert2lower(s[right]);
            }
        }else{
            right--;
            continue;
        }

        if(s[left] != s[right]){
            return false;
        }

        left++;
        right--;
    }

    return true;
}

