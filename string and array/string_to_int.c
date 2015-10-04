#include <string.h>

#define ERROR_INT -1

int string_to_int(char *str)
{
	int length = strlen(str);
	int sig = 1;//positive or negtive integer.
	int value = 0;
	int i;
	int check_begin_position = 0;
	int multiply_factor = 1;

	//make sure all char are '0' to '9' or sig char.
	if(length == 0)
		return 0;
	if(str[0] == '+')
	{
		sig = 1;
		check_begin_position = 1;
	}
	if(str[0] == '-')
	{
		sig = -1;
		check_begin_position = 1;
	}
	for( i=check_begin_position; i< length; i++ )
	{
		if(str[i]>='0' && str[i]<='9')
			continue;
		return ERROR_INT;
	}

	//trans char to int.
	for( i=length-1; i>=check_begin_position; i-- )
	{
		int v = str[i] - '0';
		
		if(i == length-1)
			multiply_factor = 1;
		else
			multiply_factor *= 10;

		value += v*multiply_factor;
	}

	//return
	return value*sig;
}

char * int_to_string(int integer)
{
	
}