int lengthOfLongestSubstring(char * s){
    int num[128];
    int flag = 0;
    int maxlength = 0;
    int i = 0;
    int temp;
    
    memset(num,-1,128*sizeof(int));
    
    for(i=0; i<strlen(s); i++)
    {
        temp = num[s[i]];
        num[s[i]]=i;
        
        if(temp>=flag)
        {
            maxlength = maxlength > (i - flag)? maxlength:(i-flag);
            flag = temp + 1;
        }
    }
    maxlength = maxlength > (i - flag)? maxlength:(i-flag);
    return maxlength;
}