int maxProfit(int* prices, int pricesSize){
    int l = 0;
    int r = 0;
    int i = 0;
    int maxProfix = 0;
    int profix = 0;

    for(r=1;r<pricesSize;r++){
        if(prices[r] > prices[l]){
            //calculate maxProfix
            profix = prices[r] - prices[l];

            if(profix > maxProfix){
            maxProfix = profix;
            }
        }else{
            l = r;
        }
    }

    return maxProfix;
    
}