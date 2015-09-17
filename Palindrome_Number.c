#include <limits.h>

bool isPalindrome1(int x) {
    int reverse_num = 0;
    int x_t = x;
    
    if (x < 0)	return false;
    
    while (x_t) {
    	if (reverse_num > (INT_MAX-x_t%10)/10)
    		return false;
        reverse_num = reverse_num*10 + x_t%10;
        x_t = x_t/10;
    }
    return reverse_num == x;
}
//another method is to compare first and last number.
bool isPalindrome(int x) {

}
