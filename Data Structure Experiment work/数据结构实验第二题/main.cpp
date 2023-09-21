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
node* previous, * head1, * t, * current, * head2, * head3;//如果order等于1则建立A多项式，如果order等于2则建立B多项式
int m1, m2;
//对三个头结点赋值为NULL
void createlist(int order1) {
	if (order1 == 1) {
		head1 = NULL;
		cout << "您正在建立A多项式" << endl;
		cout << "请输入您的多项式项数:" << endl;
		cin >> m1;
		for (int i = 1; i <= m1; i++) {
			current = (node*)malloc(sizeof(node));
			current->next = NULL;
			cout << "请分别输入该项的系数与指数:" << endl;
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
		cout << "您正在建立B多项式" << endl;
		cout << "请输入您的多项式项数:" << endl;
		cin >> m2;
		for (int i = 1; i <= m2; i++) {
			current = (node*)malloc(sizeof(node));
			current->next = NULL;
			cout << "请分别输入该项的系数与指数:" << endl;
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
node* sortout(struct node*& L, int n) {//对链表进行特定子成员排序，会对头指针进行修改
	node* head0 = L; //这里设head0为每次的头结点,为每一次遍历后的头结点
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
node* t1, * t2, * t3;//这里node* t1 和node* t2,node* t3就分别代表A，B,C链表位移了
void add() {//A+B的函数,以及顺便创造C链表
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

void minu() {//A-B的函数,以及顺便创造C链表
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
		cout << "请输入您的指令:" << endl;
		cout << "指令0代表结束操作，指令1代表建立A多项式，指令2代表建立B多项式，指令3代表输出多项式，指令4代表A，B多项式相加，指令5代表A，B多项式相减,指令6代表把某个多项式排序" << endl;
		cout << "请注意！！第一次加减完后的式子会存入C多项式，并且该C多项式只能由A+B或A-B执行一次" << endl;
		cout << "并且！！在执行相加相减操作前必须先排序" << endl;
		cin >> order;
		if (order == 0)
			return 0;
		if (order == 1 || order == 2)
		{
			createlist(order);
		}
		if (order == 3) {
			int c;
			cout << "请问您想输出哪个多项式,输入1代表A多项式，2代表B多项式，3代表C多项式" << endl;
			cout << "请注意每一项的指数会由括号表示出来" << endl;
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
			cout << "请问您想对哪个多项式排序,输入1代表A多项式，2代表B多项式" << endl;
			cin >> d;
			if (d == 1)
				head1 = sortout(head1, m1);
			if (d == 2)
				head2 = sortout(head2, m2);
		}
	}
	return 0;
}
