/*
** 这道题注意n的符号，以及n为奇数时候的处理。
*/
double binary (double x, int n) {
    double res;
    if (n == 1)
        return x;
    else if (n == 0)    
        return 1;

    res = binary(x, n/2);
    res *= res;
    return (n&1) == 1 ? res*x : res;
}

double myPow(double x, int n) {
    double x_bak = x < 0 ? -x : x;
    double n_bak = n < 0 ? -n : n;
    double res;

    if (x == 0) return 0;

    res = binary(x_bak, n_bak);

    if (x < 0 && (n&1) == 1)
        res *= -1;
    if (n < 0)
        res = 1/res;
    return res;
}