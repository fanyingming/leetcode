int* saved;
int dp(char *s, int n) {
	int rv;
	if (n == -1 || n == 0) {
		saved[0] = 1;
		return 1;
	}
	if (saved[n])
		return saved[n];

	if (s[n] == '0') {
		if (s[n - 1] == '1' || s[n - 1] == '2') {
			rv = dp(s, n - 2);
		}
		else {
			rv = 0;
		}
	} else {
		if (s[n - 1] == '1') {
			rv = dp(s, n - 2) + dp(s, n - 1);
		} else if (s[n - 1] == '2'){
			if (s[n] >= '1' && s[n] <= '6') {
				rv = dp(s, n - 2) + dp(s, n - 1);
			} else {
				rv = dp(s, n - 1);
			}
		} else {
			rv = dp(s, n - 1);
		}
	}

	saved[n] = rv;
	return rv;
}

int numDecodings(char* s) {
	int n = strlen(s);
	if (s == NULL || n == 0 || s[0] == '0')
		return 0;
	saved = malloc((n + 1)*sizeof(int));
	memset(saved, 0, (n + 1)*sizeof(int));
	return dp(s, n - 1);
}