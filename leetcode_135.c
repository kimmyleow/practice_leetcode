int candy(int* ratings, int ratingsSize){
    int i = 0;
    int candies[ratingsSize];
    int total = 0;

    //initialize all student 1 candy
    for(i=0;i<ratingsSize;i++){
        candies[i] = 1;
    }

    //left to right
    for(i=1;i<ratingsSize;i++){
        if(ratings[i]>ratings[i-1] && candies[i] <= candies[i-1]){
            candies[i] = candies[i-1] + 1;
        }
    }

    //right to left
    for(i=ratingsSize-1; i>0; i--){
        if(ratings[i]<ratings[i-1] && candies[i] >= candies[i-1]){
            candies[i-1] = candies[i] + 1;
        }
    }

    //total
    for(i=0;i<ratingsSize;i++){
        total = total + candies[i];
    }

    return total;
}