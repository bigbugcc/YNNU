/******************************************************************************************
�˹����ܣ���������ϵͳ

ʹ��˵����
���ļ���zhen������tcĿ¼�£�����tc�򿪣����뼴�ɸ�������͹����Լ����ս�����Ƴ����ۡ�
����������֮ǰһ��Ҫ���ۺ����ݿ�database.txt���Ƶ������ļ�deduce.txt�е�����ɾ��......
��ϵͳ���׵��ļ���database.txt,deduce.txt,input.txt,result.txt,rule.txt.����database.txt
Ϊ�ۺ����ݿ⣬deduce.txtΪ�Ƶ�������Ӧ�õĹ���input.txtΪ�����ļ���result.txtΪ���ս�
���⣬rule.txtΪ����⡣


*****************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"

int infile(char theword[], FILE* file)
/*���theword��fileָ����ļ��к�������1,���򷵻�0*/
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
/*��theword׷�ӵ�file�ļ���*/
{
	fputs(theword, file);
	fputs(" ", file);
}

int filewords(FILE* file)
/*�����ۺ����ݿ�ĳ���*/
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

	char one_rule[200];		/*�洢һ������*/
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

	printf("��ʼ������:\n");

	while (!feof(input_file))/*�����������ݵ��ۺ����ݿ���,�м��ÿո���*/
	{ //int feof(FILE *stream)����ļ�λ��ָʾ���Ƿ��ѵ���β
		k = 0;
		while (ch != ' ' && !feof(input_file))
		{
			word[k] = ch;
			ch = getc(input_file);
			k++;
		}//��INPUT_FILE�ж���һ��������   ���ո���ļ���β��   ����ѭ����

		ch = getc(input_file);
		word[k] = '\0';
		fputs(word, database_file);//�Ѵ�Input_file�ж����һ����¼д��database.txt�ļ��С�
		fputc(' ', database_file);//�Կո�ֿ���
	}

	rewind(database_file);
	while (!feof(database_file))
	{
		ch = getc(database_file);
		putchar(ch);
	}
	printf("\n");
	/*
	�öε���Ҫ�����ǽ�database_file�ļ��е�����ͨ��While��һ�ַ���ȡ������ӡ����
	*/

	rewind(rule_file);//int rewind ���ļ�����λ��ָʾ����λ���ļ���ʼ����
	len1 = filewords(database_file);	/*�����ۺ����ݿ�ĳ���*/
	while (!feof(rule_file))//ͨ��whileѭ����ȡrule_file�е������ַ�
	{
		ch = getc(rule_file); //��ȡ�ļ��е��ַ�
		while (ch != '<' && !feof(rule_file))//�������ļ���һ�ַ����� ȥ���ո�
		{//���ո�
			ch = getc(rule_file);
		}

		ch = getc(rule_file);
		i = 0;
		while (ch != '>' && !feof(rule_file))
		{//����¼
			one_rule[i] = ch; //����ȡ�����ַ���һ�����ַ�������
			ch = getc(rule_file); 
			i++;
			//����ȡ�����ַ�ֵ��һƴ�ӳ�����
		}
		one_rule[i] = '\0'; //���ַ���������Ͻ�����


		//printf(one_rule );
		//printf("\n");




		flag = 0;
		i = 0;
		while (one_rule[i] != '\0')/*���һ������û�н���*/
		{
			j = 0;
			while (one_rule[i] != ' ' && one_rule[i] != '\0')
			{//�ѹ����ж����һ����¼����word[]��
				word[j] = one_rule[i];
				i++;
				j++;
			}
			i++;
			word[j] = '\0';

			if (!strcmp(word, "�Ƴ�"))	/*�����"�Ƴ�",�Ͱѱ�־��1,���������Խ���*/
			{//������¼�Ѿ�����
				flag = 1;//�Ƴ���־
				continue;
			}

			if (!flag && infile(word, database_file))//flag=0
			{//�����ʲôҪɾȥdatabase.txt�е������ˡ�
				continue; /*�������������߽��� �� �ۺ����ݿ��е�ʱ��,������һ�����������*/
			}
			if (flag && infile(word, database_file))
			{
				break;	// word�������Ƴ��������Ѷ���/*�������������߽������ۺ����ݿ��е�ʱ��,������һ�����������*/����
			}

			if (!flag && !infile(word, database_file))
			{
				break;		/*��û�е��Ƴ�,���ҷ�������֮һ�����ۺ����ݿ��е�ʱ��,�Ƴ���������*/
			}
			//  puts(word);
			if (flag && !infile(word, database_file))
				/*���Ѿ������۵�ʱ��,���ֽ��۲����ۺ����ݿ���ִ���������*/
			{
				fputs(one_rule, deduce_file);/*�ѹ���д�������ļ���*/

				fputs("\n", deduce_file);

				tofile(word, database_file);/*�ѽ��ۼ����ۺ����ݿ���*/

				fputs(word, result_file);

				if (infile(word, result_file))/*���������ǽ��,�ͽ���*/
				{
					fclose(input_file);
					fclose(rule_file);
					fclose(database_file);
					fclose(deduce_file);
					fclose(result_file);
					printf("\n�ö�����:%s\n", word);
					printf("\nThe End\n");
					system("pause");
					exit(0);
				}
			}
			flag = 0;
		}

	}


	printf("�Բ��𣬸������ṩ���������޷�ȷ�������ֶ��\n");
	fclose(input_file);
	fclose(rule_file);
	fclose(database_file);
	fclose(deduce_file);
	fclose(result_file);
	system("pause");
	printf("\nThe End\n");

}