#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream oufile("C:/Users/45373/Desktop/private file/c++实验课题目/9_文件操作/file.txt", ios::binary);//写入
	char test[1024];
	cin.get(test, 1024, '#');//这里运用cin.get函数
	for (int i = 0; test[i] != '\0'; i++)//加密
	{
		if (test[i] <= 'Z' && test[i] >= 'A')
			test[i] = (test[i] - 'A' + 4) % ('Z' - 'A') + 'A';
		else if (test[i] <= 'z' && test[i] >= 'a')
			test[i] = (test[i] - 'a' + 4) % ('z' - 'a') + 'a';
	}
	oufile << test;
	oufile.close();
	ifstream xx("C:/Users/45373/Desktop/private file/c++实验课题目/9_文件操作/file.txt");//读入
	char ch;
	while (xx >> noskipws >> ch)//解密，这里noskipws函数是不忽略任何地方的空格
	{
		if (ch <= 'Z' && ch >= 'A')
			ch = (ch + 'Z' - 'A' - 4 - 'A') % ('Z' - 'A') + 'A';
		else if (ch <= 'z' && ch >= 'a')
			ch = (ch + 'z' - 'a' - 4 - 'a') % ('z' - 'a') + 'a';
		cout << ch;
	}
	return 0;
}