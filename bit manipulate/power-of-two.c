bool isPowerOfTwo(int n) {
    int num = n;
    if (n <= 0 || num != 1 && num % 2)
    	return false;

    while (num) {
    	if (num == 1)
    		return true;
    	if (num%2 == 1)
    		return false;
    	num = num/2;
    }
    return true;
}