double binary(double x, int n) {
    double half, value;
    if (n == 0)
        return 1;

    half = binary(x, n / 2);
    value = half*half;

    return n % 2 == 1 ? value*x : value;
}

double myPow(double x, int n) {
    double sum = 1;
    double x_bak = x;
    int n_bak = n;
    
    if (x == 0)
        return 0;
    if (x < 0)
        x_bak *= -1;
    n_bak = abs(n);

    sum = binary(x_bak, n_bak);

    if (x < 0 && n % 2 == 1)
        sum = -sum;
    if (n < 0)
        sum = 1 / sum;

    return sum;
}