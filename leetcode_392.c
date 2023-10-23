bool isSubsequence(char * s, char * t){
    int lenS = strlen(s);
    int lenT = strlen(t);
    int i = 0;
    int j = 0;

    while(i<lenS && j<lenT){
        if(s[i] == t[j]){
            i++;
            j++;
        }else{
            j++;
        }
    }

    if(i==lenS){
        return true;
    }else{
        return false;
    }

}