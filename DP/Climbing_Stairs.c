int *saved;
int dp(int n) {
    if (n == 1 || n == 0) {
        saved[n] = 1;
        return 1;
    }
    if (saved[n])
        return saved[n];
    saved[n] = dp(n-1) + dp (n-2);
    return saved[n];
}

int dp_loop(int n) {
    int f1 = 1;
    int f2 = 2;
    int f3;
    int i;
    
    if (n == 0)
        return 1;
    if (n == 1)
        return f1;
    if (n == 2)
        return f2;
    for (i = 3; i <= n; i++) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}

int climbStairs(int n) {
    saved = malloc((n+1)*sizeof(int));
    memset(saved, 0, (n+1)*sizeof(int));
    return dp(n);    
}