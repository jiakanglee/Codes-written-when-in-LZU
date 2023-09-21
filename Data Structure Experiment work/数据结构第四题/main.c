#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void creatfile(FILE* fp)
{
	char ch[1024];
	//输入文本内容，以#结束
	printf("\nEnter the contents of this file. End with # in the beginning of a line:\n");
	fgets(ch, 1024, stdin);
	while (ch[0] != '#')
	{
		//写入文件
		fputs(ch, fp);
		fgets(ch, 1024, stdin);
	}
}
void search(FILE* fp, char b[])
{
	//a[50]存放当前单词
	char ch, a[50];
	//定义单词第一次出现的行和列
	int first_row, first_col;
	int index = 0, row = 1, col = 0, count = 0;   //count为该单词出现的次数,col为该单词是此行的第几个,row为单词出现的行号
	//文件指针没有达到末尾时
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (isalpha(ch))
		{
			a[index] = ch;
			index++;
		}
		else if (ch == ' ')
		{
			if (index != 0)
			{
				col++;
			}
			a[index] = '\0';//表示字符串结束
			index = 0;
			if (strcmp(a, b) == 0)
			{
				count++;
				if (count == 1)
				{
					first_row = row;
					first_col = col;
				}
			}
		}
		//当前字符为回车时
		else if (ch == '\n')
		{
			a[index] = '\0';
			row++;
			index = 0;
			col = 0;
			if (strcmp(a, b) == 0)
			{
				count++;
				if (count == 1)
				{
					first_row = row;
					first_col = col;
				}
			}
		}
	}
	printf("This word appears %d time(s) in total.\n", count);
	if (count > 0)
	{
		printf("The word %s first appears in line:%d,column:%d", b, first_row, first_col);
	}
}
int main()
{
	char b[50];
	FILE* fp;
	fp = fopen("word_search.txt", "w+");
	creatfile(fp);
	printf("\nEnter the word you want to search:\n");
	scanf("%s", b);
	rewind(fp);
	search(fp, b);
	//操作完毕，关闭文件
	fclose(fp);
	return 0;
}
