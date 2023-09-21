#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>
#include<string.h>
/*int n, n1;//注意文件的输入方式，第一个结构体要把herb其包含的所有compound 和 target 都要输入进去，因此要定义两个结构体
char targetnum1[1000];//第二个结构体则是输入一个compound 一个 target 1个 PMID。
char targetnum2[1000];
char targetnum3[1000];
char seperate[3] = { "*" };
struct node {
	char herbcn[1000];
	char herben[1000];
	char compound[1000];
	char target[1000];
	node* next;
};
struct compound {
	char compound1[1000];
	char target1[1000];
	char PMID[20];
	compound* next;
};
compound* head1, * current1, * previous1, * temp1, * t1;
node* head, * current, * previous, * temp, * t;
void refresh(char* p) {
	for (int i = 0; i < 1000; i++) {
		p[i] = '0';
	}
}
int judge(char* a, char* b) {
	if (strlen(a) != strlen(b))return 0;
	int flag = 1;
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] != b[i])flag = 0;
	}
	return flag;
}
int find(char* a, char* b) {//在数组a里面查找有没有数组b
	int flag = 0, k = 0;
	for (int i = 0; i < strlen(a); i++) {
		k = i;
		if (strlen(a) - i < strlen(b) || ((strlen(a) - i == strlen(b)) && a[i] != b[0]))return flag;
		if (a[k] == b[0]) {
			for (int j = 0; j < strlen(b); j++, k++) {
				if (a[k] != b[j])
					break;
				if (j == strlen(b) - 1)
				{
					flag = 1;
					return flag;
				}
			}
		}
	}
}
void deleter1(char* a, char* b) {//在数组a中删除掉对应有的数组b的值    (这里只考虑a中b只出现一次）
	int flag = 0, k = 0;
	for (int i = 0; i < strlen(a); i++) {
		k = i;
		if (strlen(a) - i < strlen(b) || ((strlen(a) - i == strlen(b)) && a[i] != b[0]))return;
		if (a[k] == b[0]) {


			for (int j = 0; j < strlen(b); j++, k++) {
				if (a[k] != b[j])
					break;
				if (j == strlen(b) - 1)
				{
					flag = 1;

				}
				if (flag == 1) {

					strcpy(a + i, a + k + 1);
					return;
				}

			}

		}
	}
}
void replace(char* a, char* b, char* c) {//在数组a中用数组c的值替换掉对应的数组a中b的值（默认只有一次）
	int flag = 0, k = 0;
	char d[1000] = { 0 };
	for (int i = 0; i < strlen(a); i++) {
		k = i;
		if (strlen(a) - i < strlen(b) || ((strlen(a) - i == strlen(b)) && a[i] != b[0]))return;
		if (a[k] == b[0]) {
			for (int j = 0; j < strlen(b); j++, k++) {
				if (a[k] != b[j])//k=2;,j=2
					break;
				if (j == strlen(b) - 1)
					flag = 1;
				if (flag == 1) {
					strcpy(d, a + k + 1);
					strcpy(a + i, c);
					strcat(a, d);
					return;
				}
			}
		}
	}
}
void print() {//输出函数（未针对compound）
	t = head;
	while (t != NULL) {
		printf("%s\t\t", (t->herbcn));
		printf("%s\t\t", (t->herben));
		printf("%s\t\t", (t->compound));
		printf("%s\t\t", (t->target));
		printf("\n");
		t = t->next;
	}
	t1 = head1;
	while (t1 != NULL) {
		printf("%s\t", t1->compound1);
		printf("%s\t", t1->target1);
		printf("%s\t", t1->PMID);
		printf("\n");
		t1 = t1->next;
	}
}
void createlist() {//建立两个链表的函数

	printf("Please input the size of your herblist:\n");
	scanf("%d", &n);
	head = NULL;
	for (int i = 0; i < n; i++) {
		current = (node*)malloc(sizeof(node));
		current->next = NULL;
		printf("please input the Chinese and English names of the herb USE A SPACE to seperate them\nPlease input all the english names of the compounds\n USE A SPACE to begin to input compounds\neach compound was seperated with a *\neg.*Spinson*ARL,Don't input SPACE to seperate each compound \nPlease input all the English names of the targets\nUSE A SPACE to begin to input targets\neach target was seperated with a *\nif the name has a space use '-'to replace:\n");
		scanf("%s", (current->herbcn));
		scanf("%s", (current->herben));
		scanf("%s", (current->compound));
		scanf("%s", (current->target));
		if (head == NULL) {
			head = current;
		}
		else
			previous->next = current;
		previous = current;
	}
	printf("Please input the size of your compoundlist:\n");
	scanf("%d", &n1);
	head1 = NULL;
	for (int i = 0; i < n1; i++) {
		current1 = (compound*)malloc(sizeof(compound));
		current1->next = NULL;
		printf("please input the name of the compound and the target and PMID\nThis time Don't input all of the them once,but only input ONE compound,ONE target,ONE PMID \n:");
		scanf("%s", (current1->compound1));
		scanf("%s", (current1->target1));
		scanf("%s", current1->PMID);
		if (head1 == NULL) {
			head1 = current1;
		}
		else
			previous1->next = current1;
		previous1 = current1;
	}
	printf("Done with creating list!!\n");
}
void aimedinsertbefore() {//这是根据在指定的元素前插入新元素的函数(包括对队首队尾元素操作）//未针对compound
	t = head;
	if (judge(head->herben, targetnum1) || judge(head->herbcn, targetnum1)) {
		current = (node*)malloc(sizeof(node));
		scanf("%s", (current->herbcn));
		scanf("%s", (current->herben));
		scanf("%s", (current->compound));
		scanf("%s", (current->target));
		current->next = head;
		head = current;
		printf("insert head.\n");
		refresh(targetnum1);
	}
	else {
		while (!judge(t->herbcn, targetnum1) || !judge(t->herben, targetnum1)) {
			if (judge(t->herbcn, targetnum1) || judge(t->herben, targetnum1))break;
			temp = t;
			t = t->next;
			if (t == NULL)
			{
				printf("No targeted herb found!error!\n");
				return;
			}
		}
		current = (node*)malloc(sizeof(node));
		printf("please input the Chinese and English name of the herb and input the English name of compound and target:\n");
		scanf("%s", (current->herbcn));
		scanf("%s", (current->herben));
		scanf("%s", (current->compound));
		scanf("%s", (current->target));
		current->next = t;
		temp->next = current;
		refresh(targetnum1);
		printf("insert middle.\n");
	}
}
void aimedinsertafter() {//在指定元素之后插入新元素（包括队首队尾）//未针对compound
	t = head;
	if (judge(head->herben, targetnum1) || judge(head->herbcn, targetnum1)) {
		current = (node*)malloc(sizeof(node));
		scanf("%s ", (current->herbcn));
		scanf("%s ", (current->herben));
		scanf("%s ", (current->compound));
		scanf("%s ", (current->target));
		temp = head->next;
		head->next = current;
		current->next = temp;
		printf("insert head.\n");
		refresh(targetnum1);
		return;
	}
	else {
		while (!judge(temp->herbcn, targetnum1) || !judge(temp->herben, targetnum1)) {
			if (judge(temp->herbcn, targetnum1) || judge(temp->herben, targetnum1))break;
			temp = t;
			t = t->next;
			if (temp == NULL)
			{
				printf("No targeted herb found!error!\n");
				return;
			}
		}
		current = (node*)malloc(sizeof(node));
		printf("please input the Chinese and English name of the herb and input the English name of compound and target:\n");
		scanf("%s", (current->herbcn));
		scanf("%s", (current->herben));
		scanf("%s", (current->compound));
		scanf("%s", (current->target));
		temp->next = current;
		current->next = t;
		if (t == NULL)printf("insert end.\n");
		else printf("insert middle.\n");

	}
	char targetnum1[1000] = { '0' };
}
void insert() {//直接默认加在数组的末尾就可以了若想加在数组特定元素的前或后参加如上的aimedinsertbefore/after，且可以实现4，5功能
	int insert = 0;
	printf("Please input a number,inputing 12 means found herb ,and you want to insert compound,inputing 23 means you found compound , and you want to insert target\n:");
	scanf("%d", &insert);

	if (insert == 12) {
		t = head;
		printf("Please input the name of the herb as index:");
		scanf("%s", targetnum1);
		while (t != NULL) {
			if (judge(t->herbcn, targetnum1) || judge(t->herben, targetnum1))break;
			t = t->next;
			if (t == NULL) {
				printf("No herb found!error!\n");
				return;
			}
		}

		refresh(targetnum1);
		printf("Please input the compound you want to insert:");
		scanf("%s", targetnum1);
		strcat(t->compound, seperate);
		strcat(t->compound, targetnum1);
		refresh(targetnum1);
		printf("Done with inserting!!\n");
		return;
	}
	if (insert == 23) {
		t1 = head1;
		printf("Please input the PMID as index:");
		scanf("%s", targetnum1);
		while (t1 != NULL) {
			if (judge(t1->PMID, targetnum1))break;
			t1 = t1->next;
			if (t1 == NULL) {
				printf("No herb found!error!\n");
				return;
			}
		}
		refresh(targetnum1);
		printf("Please input the target you want to insert:");
		scanf("%s", targetnum1);
		strcat(t1->target1, seperate);//这个地方打*代表是第二次改动时添加的
		strcat(t1->target1, targetnum1);
		refresh(targetnum1);
		printf("Done with inserting!!\n");
		return;
	}
	else printf("WRONG INPUR,ERROR!\n");
}
void update() {//可实现4，5功能
	int update;
	printf("Please input a number,inputing 12 means found herb wrong,and you want to update compound,inputing 23 means you found compound wrong and you want to update target\n:");
	scanf("%d", &update);
	if (update == 12) {
		t = head;
		current = (node*)malloc(sizeof(node));
		printf("please input the Chinese or English name of the herb :\n");
		scanf("%s", targetnum1);

		while (t != NULL) {
			if (judge(t->herbcn, targetnum1) || judge(t->herben, targetnum1))break;
			t = t->next;
		}
		if (t == NULL) {
			printf("No herb found!error!\n");
			return;
		}
		printf("Please  input the English name of new compound you want to update\n:");
		scanf("%s", current->compound);
		refresh(targetnum1);
		printf("Please input the English name of old compound you want to update\n:");
		scanf("%s", targetnum1);
		replace(t->compound, targetnum1, current->compound);
		refresh(targetnum1);
		printf("Done with updating!!\n");
		return;
	}
	if (update == 23)
	{
		t1 = head1;
		printf("Please input the PMID  and compound and target as index:");
		scanf("%s", targetnum1);
		scanf("%s", targetnum2);
		scanf("%s", targetnum3);
		while (t1 != NULL) {
			if (judge(t1->PMID, targetnum1) && judge(t1->compound1, targetnum2) && judge(targetnum3, t1->target1))break;
			t1 = t1->next;
			if (t1 == NULL) {
				printf("No herb or others found!error!\n");
				return;
			}
		}
		refresh(targetnum1);
		printf("Please input the target you want to be repalced:");
		scanf("%s", targetnum1);
		printf("Please input the target you want to replace the old target:");
		scanf("%s", targetnum2);
		replace(t1->target1, targetnum1, targetnum2);
		refresh(targetnum1);
		refresh(targetnum2);
		printf("Done with updating!!\n");
		return;

	}
	else printf("Wrong input!ERROR!!\n");

}
void deleter() {//delete函数（对于第一个结构体由于当时草药没有在pubmed上找所以没有PMID所以直接就这样了）（第二个结构体又PMID所以要对PMID进行索引查找即可）
	int dele;
	printf("Please input a number,inputing 12 means found herb wrong,and you want to delete compound,inputing 23 means you found compound wrong and you want to delete target\n:");
	scanf("%d", &dele);

	if (dele == 12) {
		t = head;
		printf("Please input the name of the herb as index:");
		scanf("%s", targetnum1);
		while (t != NULL) {
			if (judge(t->herbcn, targetnum1) || judge(t->herben, targetnum1))break;
			t = t->next;
			if (t == NULL) {
				printf("No herb found!error!\n");
				return;
			}
		}

		refresh(targetnum1);
		printf("Please input the compound you want to delete:");
		scanf("%s", targetnum1);
		deleter1(t->compound, targetnum1);
		refresh(targetnum1);
		printf("Done with deleting!!\n");
		return;
	}
	if (dele == 23) {
		t1 = head1;
		printf("Please input the PMID  and compound and target as index:");
		scanf("%s", targetnum1);
		scanf("%s", targetnum2);
		scanf("%s", targetnum3);
		while (t1 != NULL) {
			if (judge(t1->PMID, targetnum1) && judge(t1->compound1, targetnum2) && judge(targetnum3, t1->target1))break;
			temp1 = t1;
			t1 = t1->next;
			if (t1 == NULL) {
				printf("No such PMID found or no such target you want to delete!error!\n");
				return;
			}
		}
		temp1->next = t1->next;
		free(t1);
		refresh(targetnum1);
		refresh(targetnum2);
		refresh(targetnum3);

		printf("Done with deleting!!\n");
		return;
	}
	else printf("Wrong INPUT!ERROR!!\n");
}
void enquire() {//查询函数(囊括了1，2，3 三个功能）
	int enquire;
	printf("Please input a number for enquiring,inputing 1 means herb,inputing 2 means compound,inputing 3 means target\n:");
	scanf("%d", &enquire);
	if (enquire == 1) {//如果是查中药
		printf("please input the English name or Chinese name of the herb:\n");
		scanf("%s", targetnum1);
		t = head;
		while (t != NULL) {
			if (judge(t->herbcn, targetnum1) || judge(targetnum1, t->herben))
			{
				printf("this herb includes compound:%s\n", t->compound);
				printf("this herb includes target:%s\n", t->target);
			}
			temp = t;
			t = t->next;
			if (t == NULL && !judge(temp->herbcn, targetnum1) || judge(targetnum1, temp->herben))printf("No herb found!error!\n");
		}
		refresh(targetnum1);
		printf("Done with requiring!!\n");
		return;
	}
	if (enquire == 2) {//如果是查compound 
		printf("please input the English name of the compound:\n");
		scanf("%s", targetnum1);
		t = head;
		while (t != NULL) {
			if (find(t->compound, targetnum1)) {
				printf("The  herb:%s includes this compound\n", t->herben);
			}
			temp = t;
			t = t->next;
			if (t == NULL && !find(temp->compound, targetnum1))printf("Error!can't find relative herb!!\n");
		}
		t1 = head1;
		while (t1 != NULL) {
			if (judge(t1->compound1, targetnum1))
			{
				printf("this compound includes target:%s\n", t1->target1);
			}
			temp1 = t1;
			t1 = t1->next;
			if (t1 == NULL && !judge(temp1->compound1, targetnum1))printf("Error!can't find relative target!!\n");
		}
		refresh(targetnum1);
		printf("Done with requiring!!\n");
		return;
	}
	if (enquire == 3) {//如果是查target
		printf("please input the English name of the target:\n");
		scanf("%s", targetnum1);
		t = head;
		if (head == NULL)printf("NO DATABASE CREATED!\n");
		while (t != NULL) {
			if (find(t->target, targetnum1)) {
				printf(" The  herb:%s includes this target\n", t->herben);
			}
			temp = t;
			t = t->next;
			if (t == NULL && !find(temp->target, targetnum1))printf("Error!can't find relative herb!!\n");
		}
		t1 = head1;
		if (head1 == NULL)printf("NO DATABASE CREATED!\n");
		while (t1 != NULL) {
			if (judge(t1->target1, targetnum1))
			{
				printf("The compound :%s includes this target\n", t1->compound1);
			}
			temp1 = t1;
			t1 = t1->next;
			if (t1 == NULL && !judge(temp1->target1, targetnum1))printf("Error!can't find relative compound!!\n");
		}
		refresh(targetnum1);
		printf("Done with requiring!!\n");
		return;
	}
	else printf("Wrong INPUT!ERROR!!\n");
}
void free() {//释放动态内存的函数
	t = head;
	while (t != NULL) {
		temp = t;
		t = t->next;
		free(temp);
	}
	t1 = head1;
	while (t1 != NULL) {

		temp1 = t1;
		t1 = t1->next;
		free(temp1);
	}
}
void FILElist() {
	FILE* fp = fopen("李嘉康草药.txt", "w");
	for (int i = 0; i < n; i++) {
		t = head;
		fprintf(fp, "herbname(CN and EN):");
		fprintf(fp, "\t%s\t", t->herbcn);
		fprintf(fp, "\t%s\t\n", t->herben);
		fprintf(fp, "herbcompound:");
		fprintf(fp, "\t%s\t\n", t->compound);
		fprintf(fp, "compoundtarget:");
		fprintf(fp, "\t%s\t\n", t->target);
		t = t->next;
	}
	for (int i = 0; i < n1; i++) {
		t1 = head1;
		fprintf(fp, "compound name:");
		fprintf(fp, "\t%s\t\n", t1->compound1);
		fprintf(fp, "targets:");
		fprintf(fp, "\t%s\t\n", t1->target1);
	}
	fclose(fp);
	printf("Done with FILElisting!!\n");
}
int oper = 1;
int main() {

	while (oper != 0) {
		printf("Please input a number to make an action\n0 means you are ending with the actions\n1 means you want to createlist\n2 means you want to insert\n3 means you want to update\n4 means you want to delete\n5 means you want to enquire\n6 means you want to transform your list into File\n7 means you want to print your list onto your screen\n:");
		scanf("%d", &oper);
		if (oper == 1) {
			createlist();
			continue;
		}
		if (oper == 2) {
			insert();
			continue;
		}
		if (oper == 3) {
			update();
			continue;
		}
		if (oper == 4) {
			deleter();
			continue;
		}
		if (oper == 5) {
			enquire();
			continue;
		}
		if (oper == 6) {
			FILElist();
			continue;
		}
		if (oper == 7) {
			print();
			continue;
		}
		else printf("Wrong input!!ERROR!Please input again!\n");
	}
	free();
	return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
/*struct stud_node {
	int    num;
	char   name[20];
	int    score;
	struct stud_node* next;
};

struct stud_node* createlist() {
	struct stud_node* current, * previous = NULL, * head1 = NULL;
	while (1) {
		int temp, temp1;
		current = (struct stud_node*)malloc(sizeof(struct stud_node));
		current->next = NULL;
		scanf("%d", &temp);
		current->num = temp;
		if (current->num == 0) {
			return head1;
		}
		scanf("%s", current->name);
		scanf("%d", &temp1);
		current->score = temp1;

		if (head1 == NULL) {
			head1 = current;
			previous = current;
			continue;
		}
		previous->next = current;
		previous = current;
	}




}
struct stud_node* deletelist(struct stud_node* head, int min_score) {
	struct stud_node* t, * previous = NULL;
	t = head;
	while (t != NULL) {

		if (t->score < min_score && t == head) {
			head = head->next;
			previous = t;
			t = t->next;
			continue;
		}
		if (t->score < min_score && t != head) {
			previous->next = t->next;
			t = t->next;
			continue;
		}
		previous = t;
		t = t->next;

	}
	return head;

}
int main()
{
	int min_score;
	struct stud_node* p, * head = NULL;
	head = createlist();
	scanf("%d", &min_score);

	head = deletelist(head, min_score);

	for (p = head; p != NULL; p = p->next)
		printf("%d %s %d\n", p->num, p->name, p->score);

	return 0;
}*/


#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int data;
	struct ListNode* next;
};

struct ListNode* reverse(struct ListNode* head) {
	struct ListNode* t, * previous=NULL, * later, * farlater, * head0=NULL;
	t = head;
	int numnode = 0;
	while (t != NULL) {
		numnode++;
		t = t->next;
	}
	for (int i = 1; i <= numnode; i++) {
		t = head0;
		for (int j = 1; j <= numnode - i; j++) {
			if (t == head) {
				later = t->next;
				t->next = t->next->next;
				later->next = t;
				head0 = later;
				previous = later;
			}
			else {
				later = t->next;
				farlater = t->next->next;
				previous->next = later;
				later->next = t;
				t->next = farlater;
				previous = later;
			}
		}
	}
	return head0;
}
struct ListNode* createlist(); /*裁判实现，细节不表*/
struct ListNode* reverse(struct ListNode* head);
void printlist(struct ListNode* head)
{
	struct ListNode* p = head;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	struct ListNode* head;

	head = createlist();
	head = reverse(head);
	printlist(head);

	return 0;
}