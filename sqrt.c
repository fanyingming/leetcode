int mySqrt(int x) {
    int cand;
    int l, r, m;
    
 //   assert(x >= 0);
    if (x == 0 || x == 1)
        return x;
        
    cand = -1;
    l = 1;
    r = x/2;
    //invariant: 
    while (l <= r) {
        m = (l+r)/2;
        if (m > x/m) { // in case multi overflow.
            r = m - 1;
        } else if (m*m < x) {
            l = m + 1;
            cand = m;
        }  else {
            return m;
        }
    }
    
    //assert(cand != -1);
    
    return cand;
}
