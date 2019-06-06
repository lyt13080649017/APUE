#include <stdlib.h>		//_Exit()
#include <unistd.h>  	//_exit()

#include <stdio.h>		//printf()...
#include <string.h>		//strcmp(),isprintf()...


#include <getopt.h>		//getopt_long()...

void exit_fn1(void)
{
	printf("runing exit_fn1. \n");
}

void exit_fn2(void)
{
	printf("runing exit_fn2. \n");
//	_exit(0);			//导致直接退出
//	exit(0);	longjump();		//未定义的行为
}


int main(int argc, char *argv[])
{
	atexit(exit_fn1);
	atexit(exit_fn2);
	atexit(exit_fn2);

	while(1)
	{
		const char* short_option = "h";

		const struct option long_options[] =
		{
				{"_exit", no_argument, 0, 256},
				{"_Exit", no_argument, 0, 256},
				{"exit", no_argument, 0, 258},
				{"return", no_argument, 0, 259},
				{"abort", no_argument, 0, 260},
				{"help", no_argument, 0, 'h'},
				{0, 0, 0, 0}
		};

		int getopt_return_value = -1;
		int getopt_index = -1;

		getopt_return_value = getopt_long(argc, argv, short_option, long_options, &getopt_index);

		if(-1 == getopt_return_value)
		{
			break;
		}

		switch(getopt_return_value)
		{
		case 'h':
			printf("syntax: program [options].\n");
			printf("    the option is used to choose exit method, default is exit()\n \n");
			printf("    --_exit --_Exit: exit process direct \n");
			printf("    --exit: exit after call some clean function registered by atexit() \n");
			printf("    -h --help: show the help info \n");
			break;

		case 256:	//_exit/_Exit
			if(!strcmp(long_options[getopt_index].name, "_exit"))
			{
				printf("option _exit!!\n");
				_exit(0);
			}
			else if(!strcmp(long_options[getopt_index].name, "_Exit"))
			{
				printf("option _Exit!!\n");
				_Exit(0);
			}
			break;

		case 258:		//exit
			printf("option exit!!\n");
			exit(0);
			break;

		case 259:
			printf("option return!!\n");
			return 0;
			break;

		case 260:
			printf("option abort!! \n");
			abort();
			break;

		case '?':
			printf("err option exit!!\n");
			exit(0);
			break;

		default:
			printf("default exit!!\n");
			exit(0);
			break;
		}
	}

	printf("normale exit!!\n");
	exit(0);
}
