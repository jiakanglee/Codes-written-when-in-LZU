#include <iostream>
using namespace std;
void selection_sort(int*arr, int len)//ѡ�������㷨
{
    int i, j;

    for (i = 0; i < len - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++)
            if (*(arr+j) < *(arr+min))
                min = j;
        int temp = *(arr + min);
        *(arr + min) = *(arr + i);
        *(arr + i) = temp;
    }
}
int searchone(int*A,int x) {//���ֲ����㷨
    int mid = (0 + 14) / 2;
    int left = 0;
    int right = 14;
    int flag = 0;
    while (left < right) {
        if (*(A+mid) == x)
        {
            flag = 1;
            return mid + 1;
        }
        else {
            if (x > *(A + mid)) {
                left = mid;
                mid = (left + right) / 2 + 1;//����+1�Ǳ�����������֮�俨ס
            }
            else {
                right = mid;
                mid = mid = (left + right) / 2 + 1;
            }
        }
    }
    if (flag == 0)
        return 0;//���û���ҵ�����0
}
int main() {
    int A[15];
    cout << "������������15����" << endl;
    for (int i = 0; i < 15; i++)
    {
        cin >> A[i];
    }
    selection_sort(A, 15);
    int goal;
    cout << "�����������ѯ����:" << endl;
    cin >> goal;
    if (searchone(A, goal))
        cout << "���Ԫ���������еĵ�" << searchone(A, goal) << "��Ԫ��" << endl;
    else
        cout << "�޴���" << endl;
	return 0;
}