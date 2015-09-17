#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pow_int(int a, int b)
{
	int i=0;
	int total = 1;

	while(b>0)
	{
		total *= a;
		b--;
	}
	
	return total;
}
int titleToNumber(char* s) {
    int length;
	int i = 0;
	int count = 0;
	int total = 0;

	while(s[i]!=0)
		i++;
	length = i;

	for( i=length-1; i>=0; i--,count++){
		int v = s[i] - 'A' + 1;

		if(s[i]>'Z' || s[i]<'A')
			return -1;

		total += v*pow_int(26, count);
	}

	return total;
}

int main()
{
	char a[100];

	scanf("%s", a);

	printf("%d\n", titleToNumber(a));
}