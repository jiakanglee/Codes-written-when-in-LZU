#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
//�������鷨�������
int main()
{
    int N,k,count,number;
   count=1;//count����λ��
   int t=1;//t����������涨�Ĳ�����ÿ��k�����һ��
    number=N;//number�Ǻ���ʣ���ʵʱ���֣�Ϊ�������whileѭ���жϷ��������õġ�
    scanf("%d %d",&N,&k);
    number=N;
    int a[N+50];
    for(int i=1;i<=N;i++){

        a[i]=1;//��ʼ��
    }
    //��ʼģ��
    int i=1;
  while(number!=1){


if((a[(count)%N]!=0&&t==k)||(a[count]!=0&&t==k)){//ע������һ��count%N==0�����
        if(count==N){
            a[count]=0;
            number--;
            t=0;

        }
  if(count!=N){
        a[(count)%N]=0;
    number--;
    t=0;

    }

}
if(count+1==N){//ͬ������һ��
    count++;
    t++;
    continue;
}
else if(a[(count+1)%N]==0){//����һ��������Ҫ��ʱ����
   count++;
    while(a[(count)%N]!=1)
        count++;
    t++;
    continue;
}
count++;
  t++;
    }
    for(int j=1;j<=N;j++){
            if(a[j]==1)
       printf("��%d�������Ǵ���",j);
    }
return 0;
}
//������������

/*
��Ȼ�ᵽ��������ô���Ǻúø�ϰһ�������һЩ��������
��������ͨ����ͬ���ǽ�β��ָ��Ҫ���ݵ�ͷ�����λ�ã�ע�����N,k.
1.����ṹ��
node*current,*previous,*head;
struct node{
int ID;
node* next;
}
2.��������
head=NULL
for(int i=1;i<=N;i++){
 current = (node*)malloc(sizeof(node));
 current->next=NULL;
  current->ID=i;
 	if (head == NULL) {
			head = current;
		}
		else
			previous->next = current;
		previous = current;
	}

3.�������
void print() {//�������
	t = head;
	while (t != NULL) {
		printf("%s\t\t", (t->herbcn));
		printf("%s\t\t", (t->herben));
		printf("%s\t\t", (t->compound));
		printf("%s\t\t", (t->target));
		printf("\n");
		t = t->next;
	}
}
4.�����������������ʱ��һ����ˣ�
5.ɾ�������е�ĳһ��˴����漰��
6.�ͷŶ�̬�ڴ棺
void free() {//�ͷŶ�̬�ڴ�ĺ���
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












*/
































