#include <iostream>
using namespace std;
/*void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/
int A[16];//ȫ�ֱ���
//������ʵ���Բ��ý�������������ֱ�Ӷ���һ��ȫ�����飬�ں�����ֱ�Ӹ���ֵ���ɡ�
void selection_sort(int arr[], int len)//ѡ�������㷨
{
    int i, j;

    for (i = 0; i < len - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++)
            if (arr[j] < arr[min])
                min = j;
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
int searchone(int x) {//���ֲ����㷨
    int mid = (0 + 14) / 2;
    int left = 0;
    int right = 14;
    int flag = 0;
    while (left < right) {
        if (A[mid] == x) 
        {
            flag = 1;
            return mid + 1;
        }
        else {
            if (x > A[mid]) {
                left = mid;
                mid = (left + right) / 2 +1;//����+1�Ǳ�����������֮�俨ס
            }
            else {
                right = mid;
                mid = mid = (left + right) / 2 +1;
            }
        }
    }
    if (flag == 0)
        return 0;//���û���ҵ�����0
}
int main() {
    for (int i = 0; i < 15; i++) {
        cout << "Please input the integer of the grades respectively:" << endl;
        cin >> A[i] ;
        while (A[i] > 100 || A[i] < 0)
        {
            cout << "Wrong input!Please input again!" << endl;
            cin >> A[i];
        }
    }
        selection_sort(A, 15);
        for (int i = 0; i < 15; i++)
            cout << A[i] << " ";
        cout << endl;
        int query;
        while (1) {
            cout << "Please input the integer you wanna query" << endl;
            cout << "Please input an integer between 0 and 100,if you want to stop,input 1000:" << endl;
            cin >> query;
            if (query == 1000)
                break;
            cout << searchone(query) << endl;
        }
    return 0;
}