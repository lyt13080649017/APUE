#include <stdlib.h>		//_Exit()
#include <unistd.h>  	//_exit()

#include <stdio.h>		//printf()...
#include <string.h>		//strcmp(),isprintf()...


#include <getopt.h>		//getopt_long()...

int main(int argc, char *argv[])
{
	//格式输出测试
	printf("常量到指定整数类型的输出测试。\n");
	printf("0234->%%d整数    :%d \n", 0234);
	printf("-10->%%d整数     :%d \n", -10);
	printf("-10->%%i整数     :%d \n", -10);
	printf("-20->%%u整数     :%u \n", -20);
	printf("156->%%o八进制数  :%o \n", 156);
	printf("255->%%x十六进制  :%x \n", 255);
	printf("255->%%X十六进制  :%X \n", 255);

	//浮点树测试
	printf("\n浮点树测试 e-科学计数法 f-浮点树 g-e和f自动。详细限制见下面。\n");
	printf("1-默认精度为6 2-.和.0等价 3-f和e精度必须用0填充够，e精度换算后会删除末尾的0.\n");
	printf("255->%%f        :%f \n", 255);
	printf("(double)255->%%f:%f \n", (double)255);
	printf("10.1->%%.f      :%.f \n", 10.1);
	printf("10.1->%%.0f     :%.0f \n", 10.1);
	printf("10.1->%%.3f     :%.3f \n", 10.1);
	printf("10.1111->%%.3f  :%.3f \n", 10.1111);
	printf("10.1->%%e       :%e \n", 10.1);
	printf("10.1->%%.3e     :%.3e \n", 10.1);
	printf("g的指数小于-4或者大于给定精度会使用e，否则使用f。\n");
	printf("0.0003->%%g  :%g \n", 0.0003);
	printf("0.00003->%%g :%g \n", 0.00003);
	printf("99.1->%%g    :%.2g \n", 99.1);
	printf("100.1->%%g   :%.2g \n", 100.1);

	//其他类型数据输出，字符串、字符、指针、错误输出、字符输出个数
	int addrVar = 0;
	int n1 = 0, n2 = 0;
	char sprintfOutStr[20];
	printf("\n s-字符串 c-字符 p-地址 n-已经输出字符个数 m-strerr(errno)。\n");
	printf("liyaotao->%%s   :%s\n", ("liyaotao"));
	printf("98->%%c         :%c\n", 98);
	printf("'b'->%%c        :%c\n", 'b');
	printf("&addrVar->%%p   :%p\n", &addrVar);
	sprintf(sprintfOutStr, "li%nyaotao%n:\n", &n1, &n2);
	printf("li%%nyaotao%%n  :n1=%d, n2=%d:", n1, n2);

	//以特殊格式输出
	printf("\n以特定格式输出 八进制前输出0, 十六进制输出0x或者0X。\n");
	printf("156->%%#o八进制   :%#o\n", 156);
	printf("255->%%#x十六进制 :%#x\n", 255);
	printf("255->%%#X十六进制 :%#X\n", 255);

	//对齐测试
	printf("\n对齐测试 默认-右对齐补空格 0-右对齐补0 -左对齐补空格。\n");
	printf("123456789->%%7d八进制  :%7d\n", 123456789);
	printf("123->%%#7o八进制       :%#7o\n", 123);
	printf("123->%%#07x十六进制    :%#07x\n", 123);
	printf("123->%%#-7X十六进制    :%#-7X\n", 123);

	//正负号测试
	printf("\n正负号测试 默认-正数前啥都没有 空格-整数前加一个空格 +正数前加+。\n");
	printf("-10->%%+d整数:%+d\n", (int)-10);
	printf("10->%%d整数  :%d\n", (int)10);
	printf("10->%% d整数 :% d\n", (int)10);
	printf("10->%%+d整数 :%+d\n", (int)10);


	return 0;
}

