#include <stdint.h>
#include <stdio.h>

int reverse(int x) {
	int num, res;
	int maxValue = 0x7fffffff;
	int minValue = -maxValue - 1;
	res = 0;
	if (x == minValue)	return 0;

	num = x < 0 ? -x : x;//this may overflow.

	while (num) {
		if (res > (maxValue - num % 10) / 10)//judge overflow
			return 0;
		res = res * 10 + num % 10;
		num = num / 10;
	}

	return x < 0 ? -res : res;
}

int reverse_old(int x) {
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