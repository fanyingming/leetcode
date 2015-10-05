bool isAnagram(char* s, char* t) {
    int table_s[26], table_t[26];
    int i;

    if (strlen(s) != strlen(t))
        return false;

    memset(table_s, 0, 26*sizeof(int));
    memset(table_t, 0, 26*sizeof(int));
    
    for (i = 0; i < strlen(s); i++) {
        table_s[s[i] - 'a']++;
        table_t[t[i] - 'a']++;
    }

    for (i = 0; i < 26; i++) {
        if (table_s[i] != table_t[i])
            return false;
    }

    return true;
}
