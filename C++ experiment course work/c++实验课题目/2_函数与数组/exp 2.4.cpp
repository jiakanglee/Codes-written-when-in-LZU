#include<iostream>
using namespace std;
int C[4][4];
void matrix_mul(int A[][4],int B[][4]) {//¾ØÕóÏà³Ëº¯Êı
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}
int main() {
	int A[4][4];
	int B[4][4];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> A[i][j];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> B[i][j];
	matrix_mul(A, B);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}