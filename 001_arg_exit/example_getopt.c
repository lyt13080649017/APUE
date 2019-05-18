#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>		//getopt()
#include <getopt.h>		//getopt_long()

//定义打印的消息类型
#define TYPE_SHORT_OPTION_WITHOUT_ARG 			1
#define TYPE_SHORT_OPTION_WITH_ARG				2
#define TYPE_SHORT_OPTION_WITH_OPTION_ARG		3

#define TYPE_LONG_OPTION_WITHOUT_ARG 			4
#define TYPE_LONG_OPTION_WITH_ARG				5
#define TYPE_LONG_OPTION_WITH_OPTION_ARG		6

#define TYPE_UNRECOGNIZED						0
void log_command_line_info(int type, const char *name,const char *value);


int main(int argc, char *argv[])
{
	struct {
		int verbose_flag;
		char *language;
		char *color;
	} config;

	//初始化config
	config.verbose_flag = 0;
	config.language = malloc(20);
	config.color= malloc(20);

	strcpy(config.language, "en");
	strcpy(config.color, "deafult");

	//参数解析需要的规则
	const char *short_options = "vl:c::1:2::";
	const struct option long_options[] =
	{
		{"verbose", no_argument, &config.verbose_flag, 1},
		{"brief", no_argument, &config.verbose_flag, 0},

		{"language", required_argument, 0, 'l'},
		{"color", optional_argument, 0, 'c'},

		{"other", required_argument, 0, 256},
		{0, 0, 0, 0}
	};
	//记录getopt_long返回值
	int long_options_index = 1;
	int option_return_value = -1;

	while(1)
	{
		option_return_value = getopt_long(argc, argv, short_options, long_options, &long_options_index);

		if(option_return_value == -1)
		{
			break;
		}

		switch(option_return_value)
		{
		case 0:			//flag设置
			log_command_line_info(TYPE_LONG_OPTION_WITHOUT_ARG, long_options[long_options_index].name, optarg);
			break;

		case 'v':
			config.verbose_flag = 1;
			log_command_line_info(TYPE_SHORT_OPTION_WITHOUT_ARG, "v", NULL);
			break;

		//长短选项返回同样的值
		case 'l':
			strcpy(config.language, optarg);

			if(!strcmp(long_options[long_options_index].name, "language"))
			{
				log_command_line_info(TYPE_LONG_OPTION_WITH_ARG, long_options[long_options_index].name, optarg);
			}
			else
			{
				log_command_line_info(TYPE_SHORT_OPTION_WITH_ARG, "l", optarg);
			}
			break;

		case 'c':
			if(optarg == NULL)
			{
				strcpy(config.color, "default");
			}
			else
			{
				strcpy(config.color, optarg);
			}

			if(!strcmp(long_options[long_options_index].name, "color"))
			{
				log_command_line_info(TYPE_LONG_OPTION_WITH_OPTION_ARG, long_options[long_options_index].name, optarg);
			}
			else
			{
				log_command_line_info(TYPE_SHORT_OPTION_WITH_OPTION_ARG, "c", optarg);
			}
			break;

		case '1':
			log_command_line_info(TYPE_SHORT_OPTION_WITH_ARG, "1", optarg);
			break;
		case '2':
			log_command_line_info(TYPE_SHORT_OPTION_WITH_OPTION_ARG, "2", optarg);
			break;

		case 256:
			log_command_line_info(TYPE_LONG_OPTION_WITH_ARG, long_options[long_options_index].name, optarg);
			break;

		case '?':	//错误
			log_command_line_info(TYPE_UNRECOGNIZED, "?", NULL);
			break;
		}
	}
}



void log_command_line_info(int type, const char *name, const char *value)
{
	switch(type)
	{
	case TYPE_SHORT_OPTION_WITHOUT_ARG:
		printf("INFO: short option without arg> option=-%s. \n", name);
		break;

	case TYPE_SHORT_OPTION_WITH_ARG:
		if(value == NULL)
		{
			printf("ERROR: short option with arg> option=-%s missing argument! \n", name);
		}
		else
		{
			printf("INFO: short option with arg> option=-%s, value=%s. \n", name, value);
		}
		break;

	case TYPE_SHORT_OPTION_WITH_OPTION_ARG:
		if(value == NULL)
		{
			printf("INFO: short option with option arg> option=-%s. \n", name);
		}
		else
		{
			printf("INFO: short option with option arg> option=-%s, value=%s. \n", name, value);
		}
		break;

	case TYPE_LONG_OPTION_WITHOUT_ARG:
		printf("INFO: long option without arg> option=--%s. \n", name);
		break;

	case TYPE_LONG_OPTION_WITH_ARG:
		if(value == NULL)
		{
			printf("ERROR: long option with arg> option=--%s missing argument! \n", name);
		}
		else
		{
			printf("INFO: long option with arg> option=--%s, value=%s. \n", name, value);
		}
		break;

	case TYPE_LONG_OPTION_WITH_OPTION_ARG:
		if(value == NULL)
		{
			printf("INFO: long option with option arg> option=--%s. \n", name);
		}
		else
		{
			printf("INFO: long option with option arg> option=--%s, value=%s. \n", name, value);
		}
		break;

	case TYPE_UNRECOGNIZED:
		printf("unknown option %s! \n", name);
		break;

	default:
		printf("unknown log type!");
		break;
	}
}
