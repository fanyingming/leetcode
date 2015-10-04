/*
** 1.负数不是回文数；
** 2.反转一个数时注意溢出，检测溢出的方式是：用最大的数减去xxxxxx，而不用 current_num + cand > int_max这样的判断。
*/
#include <limits.h>

bool isPalindrome(int x) {
    int reverse_num = 0;
    int x_t = x;
    
    if (x < 0)  return false;
    
    while (x_t) {
        if (reverse_num > (INT_MAX-x_t%10)/10)
            return false;
        reverse_num = reverse_num*10 + x_t%10;
        x_t = x_t/10;
    }
    return reverse_num == x;
}
