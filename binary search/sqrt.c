/*
** 这道题注意溢出，m*m > x，m*m可能溢出。以后遇到乘法和加法的时候要考虑会不会溢出。
** 还要考虑如果平方根不是整数的时候，如何用最近的整数代替，也就是代码中的cand。
** 由于小数的整数结果是向下取整，所以代码中将cand放在m*m < x下边。
*/

int mySqrt(int x) {
    int cand;
    int l, r, m;
    
    if (x == 0 || x == 1)   return x;
        
    cand = -1;
    l = 1;
    r = x;

    while (l <= r) {
        m = l + (r-l)/2;
        if (m > x/m) { // in case multi overflow.
            r = m - 1;
        } else if (m*m < x) {
            l = m + 1;
            cand = m;
        }  else {
            return m;
        }
    }
    
    return cand;
}
