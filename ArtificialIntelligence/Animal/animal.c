/******************************************************************************************
人工智能：动物推理系统

使用说明：
将文件夹zhen拷贝到tc目录下，再用tc打开，编译即可根据输入和规则，以及最终结果库推出结论。
在重新推理之前一定要把综合数据库database.txt和推导过程文件deduce.txt中的内容删除......
和系统配套的文件有database.txt,deduce.txt,input.txt,result.txt,rule.txt.其中database.txt
为综合数据库，deduce.txt为推导过程所应用的规则，input.txt为输入文件，result.txt为最终结
果库，rule.txt为规则库。


*****************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"

int infile(char theword[], FILE* file)
/*如果theword在file指向的文件中函数返回1,否则返回0*/
{
	char ch;
	char word[30];
	int i;
	rewind(file);
	while (!feof(file))
	{
		ch = getc(file);
		i = 0;
		while (ch != ' ' && !feof(file))
		{
			word[i] = ch;
			ch = getc(file);
			i++;
		}
		word[i] = '\0';
		if (!strcmp(word, theword))
		{
			return 1;
		}
	}
	return 0;
}

void tofile(char theword[], FILE* file)
/*把theword追加到file文件中*/
{
	fputs(theword, file);
	fputs(" ", file);
}

int filewords(FILE* file)
/*返回综合数据库的长度*/
{
	char ch;
	int i = 0;
	rewind(file);
	ch = getc(file);
	while (!feof(file))
	{
		if (ch == ' ')
		{
			i++;
		}
		if (!feof(file))
		{
			ch = getc(file);
		}
	}
	return i;
}

main()
{
	FILE* input_file, * rule_file, * database_file, * deduce_file, * result_file;

	char one_rule[200];		/*存储一条规则*/
	char ch, word[30];
	int i, j, k, flag, len1, len2;

	if ((input_file = fopen("input.txt", "r")) == NULL)
	{
		printf("Can not open the input.txt!\n");
		system("pause");
		exit(0);
	}

	if ((rule_file = fopen("rule.txt", "r")) == NULL)
	{
		printf("Can not open the rule.txt!\n");
		exit(0);
	}

	if ((database_file = fopen("database.txt", "w+")) == NULL)
	{
		printf("Can not open the database.txt!\n");
		system("pause");
		exit(0);
	}

	if ((deduce_file = fopen("deduce.txt", "a+")) == NULL)
	{
		printf("Can not open the deduce.txt!\n");
		system("pause");
		exit(0);
	}
	if ((result_file = fopen("result.txt", "w+")) == NULL)
	{
		printf("Can not open the result.txt!\n");
		system("pause");
		exit(0);
	}

	//clrscr();

	ch = getc(input_file);

	printf("初始条件是:\n");

	while (!feof(input_file))/*拷贝输入数据到综合数据库中,中间用空格间隔*/
	{ //int feof(FILE *stream)检测文件位置指示器是否已到结尾
		k = 0;
		while (ch != ' ' && !feof(input_file))
		{
			word[k] = ch;
			ch = getc(input_file);
			k++;
		}//从INPUT_FILE中读入一条规则。以   “空格或到文件结尾”   结束循环。

		ch = getc(input_file);
		word[k] = '\0';
		fputs(word, database_file);//把从Input_file中读入的一条记录写到database.txt文件中。
		fputc(' ', database_file);//以空格分开。
	}

	rewind(database_file);
	while (!feof(database_file))
	{
		ch = getc(database_file);
		putchar(ch);
	}
	printf("\n");
	/*
	该段的主要作用是将database_file文件中的数据通过While逐一字符读取，并打印出来
	*/

	rewind(rule_file);//int rewind 将文件操作位置指示器定位到文件开始处。
	len1 = filewords(database_file);	/*返回综合数据库的长度*/
	while (!feof(rule_file))//通过while循环读取rule_file中的所有字符
	{
		ch = getc(rule_file); //读取文件中的字符
		while (ch != '<' && !feof(rule_file))//将整个文件逐一字符读出 去掉空格
		{//读空格
			ch = getc(rule_file);
		}

		ch = getc(rule_file);
		i = 0;
		while (ch != '>' && !feof(rule_file))
		{//读记录
			one_rule[i] = ch; //将读取到的字符逐一存入字符数组中
			ch = getc(rule_file); 
			i++;
			//将读取到的字符值逐一拼接成文字
		}
		one_rule[i] = '\0'; //在字符数组最后附上结束符


		//printf(one_rule );
		//printf("\n");




		flag = 0;
		i = 0;
		while (one_rule[i] != '\0')/*如果一条规则没有结束*/
		{
			j = 0;
			while (one_rule[i] != ' ' && one_rule[i] != '\0')
			{//把规则中读入的一条记录存入word[]中
				word[j] = one_rule[i];
				i++;
				j++;
			}
			i++;
			word[j] = '\0';

			if (!strcmp(word, "推出"))	/*如果是"推出",就把标志置1,并继续测试结论*/
			{//条件记录已经读完
				flag = 1;//推出标志
				continue;
			}

			if (!flag && infile(word, database_file))//flag=0
			{//这就是什么要删去database.txt中的内容了。
				continue; /*当发现条件或者结论 在 综合数据库中的时候,继续下一个条件或结论*/
			}
			if (flag && infile(word, database_file))
			{
				break;	// word中已有推出，条件已读完/*当发现条件或者结论在综合数据库中的时候,继续下一个条件或结论*/？？
			}

			if (!flag && !infile(word, database_file))
			{
				break;		/*当没有到推出,并且发现条件之一不在综合数据库中的时候,推出这条规则*/
			}
			//  puts(word);
			if (flag && !infile(word, database_file))
				/*当已经到结论的时候,发现结论不在综合数据库中执行以下语句*/
			{
				fputs(one_rule, deduce_file);/*把规则写到推理文件中*/

				fputs("\n", deduce_file);

				tofile(word, database_file);/*把结论加入综合数据库中*/

				fputs(word, result_file);

				if (infile(word, result_file))/*如果这个此是结果,就结束*/
				{
					fclose(input_file);
					fclose(rule_file);
					fclose(database_file);
					fclose(deduce_file);
					fclose(result_file);
					printf("\n该动物是:%s\n", word);
					printf("\nThe End\n");
					system("pause");
					exit(0);
				}
			}
			flag = 0;
		}

	}


	printf("对不起，根据您提供的条件，无法确定是那种动物！\n");
	fclose(input_file);
	fclose(rule_file);
	fclose(database_file);
	fclose(deduce_file);
	fclose(result_file);
	system("pause");
	printf("\nThe End\n");

}