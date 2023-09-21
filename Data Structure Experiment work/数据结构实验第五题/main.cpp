#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<string.h>
#include<queue>
#include<map>
#include<ctype.h>
#include<malloc.h>
using namespace std;
struct node {//这里suppose一下我的树里面存的data是英文字符。
	char data;
	node* lson;
	node* rson;
};
node* current,* temp;
node* head;
int flag=0;

node* createtree(node* T ) {//是先序输入哟,对你的输入要求会比较大
	cout << "您正在先序输入，如果想停止对于结点的扩展输入请输入字符'!'"<<endl;
	char ch;
	cin >> ch;
	if (ch != '!') {
		T = (node*)malloc(sizeof(node));
		if (head == NULL)
			head = T;
		T->data = ch;
		T->lson = NULL;
		T->rson = NULL;
		T->lson = createtree(T->lson);
		T->rson = createtree(T->rson);

	}
	return T;
}
void preorder(node* T) {//先序输出哟，递归
	cout << T->data;
	if(T->lson!=NULL)
	preorder(T->lson);
	if (T->rson != NULL)
	preorder(T->rson);




}
void inorder(node* T) {//中序非递归输出哟，总体思路是先找左子树（并入栈），再输出尽头的该结点，再找该结点的右子树（的左子树，一直找下去，直到尽头，再出栈），
	int index = 0;
	node* vstack[100];
	do {
		while (T!=NULL) {
			index++;//栈顶指针，从0开始

			vstack[index] = T;//找遍该结点的所有子结点，并入栈
            T = T->lson;
		}
		if (index != 0)//正常出栈以及查找右子树
		{
			T = vstack[index];
			index--;
			cout << T -> data;
			T = T->rson;
		}







	} while (T != NULL || index != 0);
}
void posorder(node* T) {//后序输出哟，非递归，大体思路，和中序一样我们得先左查找最左子树，然后这个地方
	node* S[100];
	int S1[100];
	node* t;
	for (int i = 1; i <= 100; i++) {
		S1[i] = 0;//初始化
	}
	S[0] = 0;//这个地方如果不设置初始值为0的话，会发生内存溢出的错误，故建议这么设
	int tag, top = 0,tag1=0;
	if (T != NULL) {
		do {
			while (T != NULL) {//查找左子树
				top++;
				S[top] = T;
				T = T->lson;
			}
			tag = 1;
			if(S[top]->rson==NULL)//只有该结点的右子树为空才能退栈
			while (top&&tag) {//退栈以及搜寻右子树
					T = S[top];
					if (S1[top] == 1)
					{
						cout << T->data;
						S1[top] = 0;
						top--;
						continue;
					}
					if (T->rson == NULL)
					{
						cout << T->data;
						top--;
						continue;
					}
					if(T->rson!=NULL)
					{
						T = T->rson;
						S1[top] = 1;
						tag = 0;
					}
			}
			else
			{
				t = S[top]->rson;
				top++;
				S[top] = t;
			}

		} while (top);//基本退出循环的骚操作
	}
}
		void exchange_subtree(node* T)
		{
			if (!T)
	{
	return;//退出

	}
			else
			{
				swap(T->lson, T->rson);
				exchange_subtree(T->lson);
				exchange_subtree(T->rson);
			}
		}
		void swap(node* &Tree1, node* &Tree2)
		{
			node* temp;
			temp = Tree1;
			Tree1 = Tree2;
			Tree2 = temp;
		}

		int height_calculation(node* T)
		{
			int height_lson=0;
			int height_rson=0;
			int max=0;
			if (T == NULL)
			{
				return 0;
			}
			height_lson = height_calculation(T->lson);
			height_rson = height_calculation(T->rson);
			max = height_lson > height_rson ? height_lson : height_rson;
			return max + 1;
		}



int main() {
head = NULL;
int height;
createtree(head);
	while (1)
	{
		printf("-----------------------------------");
		printf("\n");
		printf("--------1 输出前序遍历结果----------\n\n");
		printf("--------2 输出中序遍历结果----------\n\n");
		printf("--------3 输出后序遍历结果----------\n\n");
		printf("--------4 交换左右子树--------------\n\n");
		printf("--------5 统计二叉树的高度----------\n\n");
		printf("--------6 退出----------------------\n\n");
		printf("\n\n请输入您的选择:");
		int m;
		cin >> m;
		switch (m)
		{
		case 1:
			printf("\n\n前序遍历结果为：\n\n");
			preorder(head);
			printf("\n\n");
			break;
		case 2:
			printf("\n\n中序遍历结果为:\n\n");
			inorder(head);
			printf("\n\n");
			break;
		case 3:
			printf("\n\n后序遍历结果为:\n\n");
			posorder(head);
			printf("\n\n");
			break;
		case 4:
			exchange_subtree(head);
			printf("交换成功！");
			printf("\n\n");
			break;
		case 5:
			printf("\n\n此二叉树的高度为:\n\n");
			height = height_calculation(head);
			printf("%d", height);
			printf("\n\n");
			break;
		case 6:exit(0);
		default:printf("输入错误！"); break;
		}
	}
	return 0;
}
