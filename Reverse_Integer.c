#include <stdint.h>
#include <stdio.h>

int reverse(int x) {
	int64_t res = 0;
	int sig = 1;
	int input = x;
	int32_t maxNum = 0x7fffffff;
	int64_t minNum = -maxNum - 1;
	if (x < 0) {
		sig = -1;
		input = -x;
	}
	while (input) {
		res = res * 10 + input % 10;
		input = input / 10;
	}
	res = sig*res;
	if (res > maxNum || res < minNum)   return 0;
	return res;
}
/*
int main() {
	int rv = reverse(-2147483648);
	printf("%d\n", rv);
}
*/