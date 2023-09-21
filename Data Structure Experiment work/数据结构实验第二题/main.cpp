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
struct node {
	float coef;
	int exp;
	node* next;
};
node* previous, * head1, * t, * current, * head2, * head3;//���order����1����A����ʽ�����order����2����B����ʽ
int m1, m2;
//������ͷ��㸳ֵΪNULL
void createlist(int order1) {
	if (order1 == 1) {
		head1 = NULL;
		cout << "�����ڽ���A����ʽ" << endl;
		cout << "���������Ķ���ʽ����:" << endl;
		cin >> m1;
		for (int i = 1; i <= m1; i++) {
			current = (node*)malloc(sizeof(node));
			current->next = NULL;
			cout << "��ֱ���������ϵ����ָ��:" << endl;
			cin >> current->coef >> current->exp;
			if (head1 == NULL)
				head1 = current;
			else
				previous->next = current;
			previous = current;
		}
	}
	if (order1 == 2) {
		head2 = NULL;
		cout << "�����ڽ���B����ʽ" << endl;
		cout << "���������Ķ���ʽ����:" << endl;
		cin >> m2;
		for (int i = 1; i <= m2; i++) {
			current = (node*)malloc(sizeof(node));
			current->next = NULL;
			cout << "��ֱ���������ϵ����ָ��:" << endl;
			cin >> current->coef >> current->exp;
			if (head2 == NULL)
				head2 = current;
			else
				previous->next = current;
			previous = current;
		}
	}
}
void output(struct node* & L) {
	t = L;
	while (t != NULL)
	{
		if (t->coef == 0) {
			t = t->next;
			continue;
		}
		if (t->coef < 0) {
			if (t->next == NULL) {
				cout << "(" << t->coef << ")" << "*" << "x^" << "(" << t->exp << ")";
			}
			else
				cout << "(" << t->coef << ")" << "*" << "x^" << "(" << t->exp << ")" << "+";
		}
		if (t->coef > 0) {
			if (t->next == NULL) {
				cout << t->coef << "*" << "x^" << "(" << t->exp << ")";
			}
			else
				cout << t->coef << "*" << "x^" << "(" << t->exp << ")" << "+";
		}

		t = t->next;
	}
	cout << endl;
}
node* previous1;
node* sortout(struct node*& L, int n) {//����������ض��ӳ�Ա���򣬻��ͷָ������޸�
	node* head0 = L; //������head0Ϊÿ�ε�ͷ���,Ϊÿһ�α������ͷ���
	t = L;
	node* p, * q;

	for (int i = 1; i <= n; i++) {
		t = head0;
		for (int j = 1; j <= n - i; j++) {

			if (t->exp >= (t->next)->exp) {
				if (t == head0) {
					p = t->next;
					t->next = p->next;
					p->next = t;
					previous1 = p;
					head0 = p;
					continue;
				}
				else {
					q = t->next;
					p = q->next;
					previous1->next = q;
					q->next = t;
					t->next = p;
					previous1 = q;
					continue;
				}
			}
			t = t->next;
		}
	}
	return head0;
}
node* r;
node* t1, * t2, * t3;//����node* t1 ��node* t2,node* t3�ͷֱ����A��B,C����λ����
void add() {//A+B�ĺ���,�Լ�˳�㴴��C����
	head3 = NULL;
	t1 = head1;
	t2 = head2;
while (!(t1 == NULL && t2 == NULL)) {
		if (t1 == NULL&&t2!=NULL) {
			while (t2 != NULL) {
				current = (node*)malloc(sizeof(node));
				current->coef = t2->coef;
				current->exp = t2->exp;
				current->next = NULL;
				previous->next = current;
				previous = current;
				t2 = t2->next;
			}
		}

		if (t2 == NULL&&t1!=NULL) {
			while (t1 != NULL) {
				current = (node*)malloc(sizeof(node));
				current->coef = t1->coef;
				current->exp = t1->exp;
				current->next = NULL;
				previous->next = current;
				previous = current;
				t1 = t1->next;
			}
			continue;
		}
		if (t1->exp < t2->exp)
		{
			while (t1->exp < t2->exp) {
				current = (node*)malloc(sizeof(node));
				current->coef = t1->coef;
				current->exp = t1->exp;
				current->next = NULL;
				if (head3 == NULL)
				{
					head3 = current;
					previous = current;
					continue;
				}
				previous->next = current;
				previous = current;
				t1 = t1->next;
				if (t1 == NULL)
					break;
			}
			if (t1 == NULL) {
				continue;
			}
		}
		if (t1->exp > t2->exp) {
			while (t2->exp < t1->exp) {
				current = (node*)malloc(sizeof(node));
				current->coef = t2->coef;
				current->exp = t2->exp;
				current->next = NULL;
				if (head3 == NULL) {
					head3 = current;
					previous = current;
					continue;
				}

				previous->next = current;
				previous = current;
				t2 = t2->next;
				if (t2 == NULL)
					break;
			}
			if (t2 == NULL)
				continue;
		}
		if (t1->exp == t2->exp) {
			current = (node*)malloc(sizeof(node));
			current->coef = t1->coef + t2->coef;
			current->exp = t1->exp;
			current->next = NULL;
			if (head3 == NULL) {
				head3 = current;
				previous = current;
			}
			previous->next = current;
			previous = current;
			t1 = t1->next;
			t2 = t2->next;
		}
	}
}

void minu() {//A-B�ĺ���,�Լ�˳�㴴��C����
	head3 = NULL;
	t1 = head1;
	t2 = head2;
	while (!(t1 == NULL && t2 == NULL)) {
		if (t1 == NULL && t2 != NULL) {
			while (t2 != NULL) {
				current = (node*)malloc(sizeof(node));
				current->coef = -(t2->coef);
				current->exp = t2->exp;
				current->next = NULL;
				previous->next = current;
				previous = current;
				t2 = t2->next;
			}
		}

		if (t2 == NULL && t1 != NULL) {
			while (t1 != NULL) {
				current = (node*)malloc(sizeof(node));
				current->coef = t1->coef;
				current->exp = t1->exp;
				current->next = NULL;
				previous->next = current;
				previous = current;
				t1 = t1->next;
			}
			continue;
		}
		if (t1->exp < t2->exp)
		{
			while (t1->exp < t2->exp) {
				current = (node*)malloc(sizeof(node));
				current->coef = t1->coef;
				current->exp = t1->exp;
				current->next = NULL;
				if (head3 == NULL)
				{
					head3 = current;
					previous = current;
					continue;
				}
				previous->next = current;
				previous = current;
				t1 = t1->next;
				if (t1 == NULL)
					break;
			}
			if (t1 == NULL) {
				continue;
			}
		}
		if (t1->exp > t2->exp) {
			while (t2->exp < t1->exp) {
				current = (node*)malloc(sizeof(node));
				current->coef = -(t2->coef);
				current->exp = t2->exp;
				current->next = NULL;
				if (head3 == NULL) {
					head3 = current;
					previous = current;
					continue;
				}

				previous->next = current;
				previous = current;
				t2 = t2->next;
				if (t2 == NULL)
					break;
			}
			if (t2 == NULL)
				continue;
		}
		if (t1->exp == t2->exp) {
			current = (node*)malloc(sizeof(node));
			current->coef = t1->coef - t2->coef;
			current->exp = t1->exp;
			current->next = NULL;
			if (head3 == NULL) {
				head3 = current;
				previous = current;
			}
			previous->next = current;
			previous = current;
			t1 = t1->next;
			t2 = t2->next;
		}
	}
}
int main()
{
	int order = 1000;
	while (order != 0) {
		cout << "����������ָ��:" << endl;
		cout << "ָ��0�������������ָ��1������A����ʽ��ָ��2������B����ʽ��ָ��3�����������ʽ��ָ��4����A��B����ʽ��ӣ�ָ��5����A��B����ʽ���,ָ��6�����ĳ������ʽ����" << endl;
		cout << "��ע�⣡����һ�μӼ�����ʽ�ӻ����C����ʽ�����Ҹ�C����ʽֻ����A+B��A-Bִ��һ��" << endl;
		cout << "���ң�����ִ������������ǰ����������" << endl;
		cin >> order;
		if (order == 0)
			return 0;
		if (order == 1 || order == 2)
		{
			createlist(order);
		}
		if (order == 3) {
			int c;
			cout << "������������ĸ�����ʽ,����1����A����ʽ��2����B����ʽ��3����C����ʽ" << endl;
			cout << "��ע��ÿһ���ָ���������ű�ʾ����" << endl;
			cin >> c;
			if (c == 1)
				output(head1);
			if (c == 2)
				output(head2);
			if (c == 3) {
				output(head3);
			}
		}
		if (order == 4)
			add();
		if (order == 5)
			minu();
		if (order == 6) {
			int d;
			cout << "����������ĸ�����ʽ����,����1����A����ʽ��2����B����ʽ" << endl;
			cin >> d;
			if (d == 1)
				head1 = sortout(head1, m1);
			if (d == 2)
				head2 = sortout(head2, m2);
		}
	}
	return 0;
}
