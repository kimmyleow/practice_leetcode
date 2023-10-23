int maxProfit(int* prices, int pricesSize){
    int right = 0;
    int profit = 0;

    for(right=1;right<pricesSize;right++){
        if(prices[right] > prices[right-1]){
            profit = profit + (prices[right] - prices[right-1]);
        }
    }
    return profit;
}