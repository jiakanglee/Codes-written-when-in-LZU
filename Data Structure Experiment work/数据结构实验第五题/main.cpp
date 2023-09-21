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
struct node {//����supposeһ���ҵ���������data��Ӣ���ַ���
	char data;
	node* lson;
	node* rson;
};
node* current,* temp;
node* head;
int flag=0;

node* createtree(node* T ) {//����������Ӵ,���������Ҫ���Ƚϴ�
	cout << "�������������룬�����ֹͣ���ڽ�����չ�����������ַ�'!'"<<endl;
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
void preorder(node* T) {//�������Ӵ���ݹ�
	cout << T->data;
	if(T->lson!=NULL)
	preorder(T->lson);
	if (T->rson != NULL)
	preorder(T->rson);




}
void inorder(node* T) {//����ǵݹ����Ӵ������˼·������������������ջ�����������ͷ�ĸý�㣬���Ҹý���������������������һֱ����ȥ��ֱ����ͷ���ٳ�ջ����
	int index = 0;
	node* vstack[100];
	do {
		while (T!=NULL) {
			index++;//ջ��ָ�룬��0��ʼ

			vstack[index] = T;//�ұ�ý��������ӽ�㣬����ջ
            T = T->lson;
		}
		if (index != 0)//������ջ�Լ�����������
		{
			T = vstack[index];
			index--;
			cout << T -> data;
			T = T->rson;
		}







	} while (T != NULL || index != 0);
}
void posorder(node* T) {//�������Ӵ���ǵݹ飬����˼·��������һ�����ǵ������������������Ȼ������ط�
	node* S[100];
	int S1[100];
	node* t;
	for (int i = 1; i <= 100; i++) {
		S1[i] = 0;//��ʼ��
	}
	S[0] = 0;//����ط���������ó�ʼֵΪ0�Ļ����ᷢ���ڴ�����Ĵ��󣬹ʽ�����ô��
	int tag, top = 0,tag1=0;
	if (T != NULL) {
		do {
			while (T != NULL) {//����������
				top++;
				S[top] = T;
				T = T->lson;
			}
			tag = 1;
			if(S[top]->rson==NULL)//ֻ�иý���������Ϊ�ղ�����ջ
			while (top&&tag) {//��ջ�Լ���Ѱ������
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

		} while (top);//�����˳�ѭ����ɧ����
	}
}
		void exchange_subtree(node* T)
		{
			if (!T)
	{
	return;//�˳�

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
		printf("--------1 ���ǰ��������----------\n\n");
		printf("--------2 �������������----------\n\n");
		printf("--------3 �������������----------\n\n");
		printf("--------4 ������������--------------\n\n");
		printf("--------5 ͳ�ƶ������ĸ߶�----------\n\n");
		printf("--------6 �˳�----------------------\n\n");
		printf("\n\n����������ѡ��:");
		int m;
		cin >> m;
		switch (m)
		{
		case 1:
			printf("\n\nǰ��������Ϊ��\n\n");
			preorder(head);
			printf("\n\n");
			break;
		case 2:
			printf("\n\n����������Ϊ:\n\n");
			inorder(head);
			printf("\n\n");
			break;
		case 3:
			printf("\n\n����������Ϊ:\n\n");
			posorder(head);
			printf("\n\n");
			break;
		case 4:
			exchange_subtree(head);
			printf("�����ɹ���");
			printf("\n\n");
			break;
		case 5:
			printf("\n\n�˶������ĸ߶�Ϊ:\n\n");
			height = height_calculation(head);
			printf("%d", height);
			printf("\n\n");
			break;
		case 6:exit(0);
		default:printf("�������"); break;
		}
	}
	return 0;
}
