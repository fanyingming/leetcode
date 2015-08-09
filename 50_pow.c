double binary(double x, int n) {
    if (n == 0)
        return 1;
    
    if (n%2 == 1)
        return x*binary(x*x, n/2);
    else 
        return binary(x*x, n/2);
}

double myPow(double x, int n) {
    double sum = 1;
    int i, sig = 1, x_sig = 1;
    
    if (x == 0)
        return 0;
    if (n == 0)
        return 1;
    
    if (n < 0) {
        sig = -1;
        n = -n;
    }
    if (x < 0) {
        x_sig = -1;
        x = -x;
    }
    
    sum = binary(x, n);
    
    if (x_sig == -1 && n%2 == 1)
        sum = -sum;
    if (sig == -1) 
        sum = 1/sum;
    
    return sum;
}
