#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void creatfile(FILE* fp)
{
	char ch[1024];
	//�����ı����ݣ���#����
	printf("\nEnter the contents of this file. End with # in the beginning of a line:\n");
	fgets(ch, 1024, stdin);
	while (ch[0] != '#')
	{
		//д���ļ�
		fputs(ch, fp);
		fgets(ch, 1024, stdin);
	}
}
void search(FILE* fp, char b[])
{
	//a[50]��ŵ�ǰ����
	char ch, a[50];
	//���嵥�ʵ�һ�γ��ֵ��к���
	int first_row, first_col;
	int index = 0, row = 1, col = 0, count = 0;   //countΪ�õ��ʳ��ֵĴ���,colΪ�õ����Ǵ��еĵڼ���,rowΪ���ʳ��ֵ��к�
	//�ļ�ָ��û�дﵽĩβʱ
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
			a[index] = '\0';//��ʾ�ַ�������
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
		//��ǰ�ַ�Ϊ�س�ʱ
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
	//������ϣ��ر��ļ�
	fclose(fp);
	return 0;
}
