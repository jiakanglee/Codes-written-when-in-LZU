#include <iostream>
#include <string.h>
using namespace std;
char a[100];
char b[100];
void chararray() {
	int temp = strlen(a);
	for (int i = temp,j = 0; j < strlen(b); i++, j++)
		a[i] = b[j];
	a[strlen(a) + strlen(b)] = '/0';
}
void str_cat() {
	strcat_s(a, b);
}
/*
要求3，用string定义
即
string a,b;
a = a+b;
即可
*/
int main() {
	gets_s(a);
	gets_s(b);
	//chararray();
	str_cat();
	cout << a << endl;
	return 0;
}
