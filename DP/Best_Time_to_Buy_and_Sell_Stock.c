int maxProfit(int* prices, int pricesSize) {
    int i;
    int max_profit = 0;
    int min_price = 0x7fffffff;
    
    if (prices == NULL || pricesSize < 2)   return 0;
    
    for (i = 0; i < pricesSize-1; i++) {
        min_price = min(prices[i], min_price);
        max_profit= max(prices[i+1] - min_price, max_profit);
    }
    
    return max_profit;
}