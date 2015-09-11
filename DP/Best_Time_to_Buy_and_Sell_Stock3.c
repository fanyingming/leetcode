void helper_left(int* prices, int begin_index, int end_index, int *left_profits) {
    int i, profit;
    int min_index = 0;
    int max_profit = 0;
    
    for (i = begin_index; i <= end_index-1; i++) {
        if (prices[i] < prices[min_index])
            min_index = i;
        profit = prices[i+1] - prices[min_index];
        if (profit > max_profit)
            max_profit = profit;
        left_profits[i+1] = max_profit;
    }
}

void helper_right(int* prices, int begin_index, int end_index, int *right_profits) {
    int i, profit;
    int max_index = end_index;
    int max_profit = 0;
 
    for (i = end_index; i > begin_index; i--) {
        if (prices[i] > prices[max_index])
            max_index = i;
        profit = prices[max_index] - prices[i-1];
        if (profit > max_profit)
            max_profit = profit;
        right_profits[i-1] = max_profit;
    }
}

int maxProfit(int* prices, int pricesSize) {
    int i;
    int max, left, right;
    int *left_profits;
    int *right_profits;
    
    if (prices == NULL || pricesSize < 2)   return 0;
    
    max = 0;
    left_profits = malloc(sizeof(int)*pricesSize);
    right_profits = malloc(sizeof(int)*pricesSize);
    memset(left_profits, 0, sizeof(int)*pricesSize);
    memset(right_profits, 0, sizeof(int)*pricesSize);
    
    helper_left (prices, 0, pricesSize-1, left_profits);
    helper_right(prices, 0, pricesSize-1, right_profits);
    
    for (i = 0; i < pricesSize; i++) {
        left  = left_profits[i];
        right = right_profits[i];
        if (left+right > max)    max = left+right;
    }
    
    free(left_profits);
    free(right_profits);
    return max;
}