#include <iostream>
using namespace std;
void selection_sort(int*arr, int len)//选择排序算法
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
int searchone(int*A,int x) {//二分查找算法
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
                mid = (left + right) / 2 + 1;//这里+1是避免在两个数之间卡住
            }
            else {
                right = mid;
                mid = mid = (left + right) / 2 + 1;
            }
        }
    }
    if (flag == 0)
        return 0;//如果没有找到返回0
}
int main() {
    int A[15];
    cout << "请依次输入这15个数" << endl;
    for (int i = 0; i < 15; i++)
    {
        cin >> A[i];
    }
    selection_sort(A, 15);
    int goal;
    cout << "请输入你想查询的数:" << endl;
    cin >> goal;
    if (searchone(A, goal))
        cout << "这个元素是数组中的第" << searchone(A, goal) << "个元素" << endl;
    else
        cout << "无此数" << endl;
	return 0;
}