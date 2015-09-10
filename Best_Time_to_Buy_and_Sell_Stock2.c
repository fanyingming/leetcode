int maxProfit(int* prices, int pricesSize) {
    int i;
    int profits = 0;
    if (prices == NULL || pricesSize < 2)   return 0;
    for (i = 0; i < pricesSize-1; i++) {
        int profit = prices[i+1] - prices[i];
        if (profit > 0)
            profits += profit;
    }
    return profits;
}