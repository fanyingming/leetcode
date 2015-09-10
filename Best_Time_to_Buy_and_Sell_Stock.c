int maxProfit(int* prices, int pricesSize) {
    int i;
    int min_index = 0;
    int max_profit = 0;
    int max_index = 0;
    int index_buy, index_sell;
    
    if (prices == NULL || pricesSize < 2)   return 0;
    
    for (i = 0; i < pricesSize-1; i++) {
        int profit;
        if (prices[i] < prices[min_index])
            min_index = i;
        profit = prices[i+1] - prices[min_index];
        if (profit > max_profit) {
            max_profit = profit;
            max_index = i+1;
            index_buy = min_index;
            index_sell = max_index;
        }
    }
    
    return max_profit;
}