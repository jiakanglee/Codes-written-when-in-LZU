#include <iostream>
using namespace std;
/*void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/
int A[16];//全局变量
//这里其实可以不用交换函数，可以直接定义一个全局数组，在函数里直接更改值即可。
void selection_sort(int arr[], int len)//选择排序算法
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
int searchone(int x) {//二分查找算法
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
                mid = (left + right) / 2 +1;//这里+1是避免在两个数之间卡住
            }
            else {
                right = mid;
                mid = mid = (left + right) / 2 +1;
            }
        }
    }
    if (flag == 0)
        return 0;//如果没有找到返回0
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