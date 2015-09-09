char* longestCommonPrefix(char** strs, int strsSize) {
	int i, j, last;
	int min_len = 0x7fffffff;
	char *res = malloc(1);

	res[0] = 0;

	if (strs == NULL || strsSize == 0)  return res;
	last = -1;
	for (i = 0; i < strsSize; i++)
		if (strlen(strs[i]) < min_len)
			min_len = strlen(strs[i]);

	for (j = 0; j < min_len; j++) {
		for (i = 1; i < strsSize; i++)
			if (strs[i][j] != strs[0][j])
				break;
		if (i < strsSize)
			break;
		last = j;
	}
	if (last == -1)	return res;// no common prefix.
	free(res);
	res = malloc(last + 2);
	memcpy(res, strs[0], last + 1);
	res[last + 1] = 0;
	return res;
}
