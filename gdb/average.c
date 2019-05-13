#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>

int16_t average(int16_t num, ...);

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf( "need at list two argument! "
				"first is the number of data, other is the data\n"
				"you can type --help to see the usage "
				"or --version to check the version \n");

		//返回码理解
		exit(0);
	}

	if(strcmp(argv[1], "--version"))
	{
		printf("v1.0.0 \n");
	}
	else if(strcmp(argv[1], "--help"))
	{
		printf("data type should be uint16_t, first is the number of data, other is the data. \n");
	}
	else
	{
		char **ptr;
		uint8_t realNum = 0;
		for(ptr = argv[2]; *argv != NULL; ptr++)
		{
			realNum++;
		}

		//how to transfer command_line argv to variable argument list??
		printf("arvege = %d \n", (int)average(3, 10, 20, 30));
	}

	return 0;
}


int16_t average(int16_t num, ...)
{
	int32_t sum = 0;
	int16_t inData = 0;
	if(num < 1)
	{
		//printf输出到哪里了？有那些同类函数？
		printf("this fun need at least 2 argument! \n");
	}

	va_list inDataPtr;

	va_start(inDataPtr, num);
	for(uint8_t i = 0; i < num; i++)
	{
		inData = va_arg(inDataPtr, int16_t);
		sum += inData;
	}
	va_end(inDataPtr);
	return (int16_t)(sum/num);
}
