/*
** 题目简单时，多考虑特殊情况。
** 这道题的特殊就是最后有空格时如何处理。
*/
bool isChar(char c) {
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        return true;
    else
        return false;
}

int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int i;
    int count = 0;
    
    for (i = len-1; i >= 0; i--) {
        if (s[i] == ' ')
            len--;
        else
            break;
    }
    
    for (i = len-1; i >= 0; i--) {
        if (isChar(s[i])) {
            count++;
        } else {
            break;
        }
    }
    
    return count;
}