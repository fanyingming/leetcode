#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
    int i;
	int one_bit_num = 0;

	for( i=0; i<32; i++){
		one_bit_num += n&1;
		n = n>>1;
	}

	return one_bit_num;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n",hammingWeight((uint32_t)n));
}