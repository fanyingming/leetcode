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
