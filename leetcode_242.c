// what is anagram = 
// anagram means both strings contains same words but arrange in different sequence

bool isAnagram(char * s, char * t){

    int hash[256] = {0};
    
    // if both is NULL, return false
    if(s==NULL || t==NULL){
        return false;
    }

    // both length must be same
    if(strlen(s) != strlen(t)){
        return false;
    }

    while((*s!='\0') && (*t!='\0')){
        hash[*s++] += 1;
        hash[*t++] -= 1;
    }

    for(int i = 0; i<255; i++){
        if(hash[i] != 0){
            return false;
        }
    }

    return true;
}