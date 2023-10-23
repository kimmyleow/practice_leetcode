int hIndex(int* citations, int citationsSize){
    int i = 0;
    int j = 0;
    int count = 0;
    int h = 0;

    for(i=citationsSize; i>0; i--){
        count = 0;
        for(j=0;j<citationsSize;j++){
            if(citations[j]>=i){
                count = count + 1;
            }
        }

        if(count>=i){
            return i;
        }
    }
    return h;
}