#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream oufile("C:/Users/45373/Desktop/private file/c++ʵ�����Ŀ/9_�ļ�����/file.txt", ios::binary);//д��
	char test[1024];
	cin.get(test, 1024, '#');//��������cin.get����
	for (int i = 0; test[i] != '\0'; i++)//����
	{
		if (test[i] <= 'Z' && test[i] >= 'A')
			test[i] = (test[i] - 'A' + 4) % ('Z' - 'A') + 'A';
		else if (test[i] <= 'z' && test[i] >= 'a')
			test[i] = (test[i] - 'a' + 4) % ('z' - 'a') + 'a';
	}
	oufile << test;
	oufile.close();
	ifstream xx("C:/Users/45373/Desktop/private file/c++ʵ�����Ŀ/9_�ļ�����/file.txt");//����
	char ch;
	while (xx >> noskipws >> ch)//���ܣ�����noskipws�����ǲ������κεط��Ŀո�
	{
		if (ch <= 'Z' && ch >= 'A')
			ch = (ch + 'Z' - 'A' - 4 - 'A') % ('Z' - 'A') + 'A';
		else if (ch <= 'z' && ch >= 'a')
			ch = (ch + 'z' - 'a' - 4 - 'a') % ('z' - 'a') + 'a';
		cout << ch;
	}
	return 0;
}