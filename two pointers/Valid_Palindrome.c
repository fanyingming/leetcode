bool is_alpha (char c) {
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
        return true;
    else
        return false;
}

bool is_same(char a, char b) {
    if (a == b)
        return true;
    if (a-'a'+'A' == b)
        return true;
    if (b-'a'+'A' == a)
        return true;
    return false;
}

bool isPalindrome(char* s) {
    int l, r;
    if (s == NULL || strlen(s) == 0)    return true;
    
    l = 0;
    r = strlen(s)-1;
    while (l < r) {
        if (is_alpha(s[l]) == false) {
            l++;
            continue;
        }
        if (is_alpha(s[r]) == false) {
            r--;
            continue;
        }
        if (is_same(s[l], s[r]) == false)   return false;
        l++;
        r--;
    }
    return true;
}