bool isPalindrome(int x) {
    int reverse_num = 0;
    int x_t = x;
    
    if (x < 0)
        return false;
    
    while (x_t) {
        reverse_num = reverse_num*10 + x_t%10;
        x_t = x_t/10;
    }
    return reverse_num == x;
}
