int divide(int dividend, int divisor) {
	int bit_count = 0;
	int sum = 0;
	int sig = 1;
	int max_bits = 30;
	int res = 0;

	if (divisor == 0)	return INT_MAX;
	if (dividend == 0)	return 0;
	if (divisor == INT_MIN) {
		if (dividend == INT_MIN)	return 1;
		return 0;
	}
	if (dividend == INT_MIN) {//overslow handling.
		if (divisor == -1)//overflow
			return INT_MAX;
		dividend += abs(divisor);
		res++;//notice here, not easy to think here.
	}

	if (dividend < 0 && divisor < 0) {
		sig = 1;
		dividend = -dividend;
		divisor = -divisor;
	}
	else if (dividend < 0) {
		sig = -1;
		dividend = -dividend;
	}
	else if (divisor < 0) {
		sig = -1;
		divisor = -divisor;
	}

	while (dividend >= divisor) {
		while (bit_count+1 <= max_bits) {
			if ((divisor << (bit_count + 1)) < dividend) {
				if (bit_count + 1 == max_bits) {
					bit_count++;
					sum = divisor << (bit_count);
					break;
				}
				else
					bit_count++;
			}
			else if ((divisor << (bit_count + 1)) == dividend) {
				res += 1 << (bit_count + 1);
				return sig*res;
			}
			else {
				sum = divisor << bit_count;
				break;
			}
		}
		res += 1 << (bit_count);
		dividend -= sum;
		bit_count = 0;
	}

	return sig*res;
}