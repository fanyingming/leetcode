void reverse(char *s) {
    int len = strlen(s);
    int i;
    char t;

	for (i = 0; i < (len/2); i++) {
        t = s[i]; s[i] = s[len-1-i]; s[len-1-i] = t;
	}
}
int max1(int a, int b) {
    return a < b ? b: a;
}
char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    char *r_str = malloc(len_a + len_b+1);//should max(a,b)+1;
    int i, j, index = 0;
    int max_len = max1(len_a, len_b);
    char *(str[2]);

    if (len_a == 0 && len_b == 0)
        return NULL;

    if (len_a < len_b) {
        str[0] = b;
        str[1] = a;
    } else {
        str[1] = b;
        str[0] = a;
    }

    for (i = strlen(str[0])-1, j = strlen(str[1])-1; j >= 0 && i >= 0; i--, j--)
        r_str[index++] = str[0][i] + str[1][j] - '0';

    for (; i >= 0; i--)
        r_str[index++] = str[0][i];

    for (i = 0; i < index; i++) {
        if (r_str[i] == '0' || r_str[i] == '1')
            continue;
        if (r_str[i] == '2')
            r_str[i] = '0';
        else if (r_str[i] == '3')
            r_str[i] = '1';

        if (i+1 == index) {
            r_str[index++] = '1';
            break;
        } else {
            r_str[i+1]++;
        }
    }

    r_str[index++] = 0;
    reverse(r_str);
    return r_str;
}
