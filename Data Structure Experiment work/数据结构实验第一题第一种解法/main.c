#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
//向量数组法解决问题
int main()
{
    int N,k,count,number;
   count=1;//count是总位移
   int t=1;//t类似于满足规定的步数，每到k次清空一次
    number=N;//number是猴子剩余的实时数字，为了下面的while循环判断方便所设置的。
    scanf("%d %d",&N,&k);
    number=N;
    int a[N+50];
    for(int i=1;i<=N;i++){

        a[i]=1;//初始化
    }
    //开始模拟
    int i=1;
  while(number!=1){


if((a[(count)%N]!=0&&t==k)||(a[count]!=0&&t==k)){//注意特判一下count%N==0的情况
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
if(count+1==N){//同理特判一下
    count++;
    t++;
    continue;
}
else if(a[(count+1)%N]==0){//当下一步不满足要求时做法
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
       printf("第%d个猴子是大王",j);
    }
return 0;
}
//链表解决该问题

/*
既然提到了链表那么我们好好复习一下链表的一些基本操作
这里与普通链表不同的是结尾的指针要回溯到头链表的位置，注意参数N,k.
1.创造结构体
node*current,*previous,*head;
struct node{
int ID;
node* next;
}
2.创造链表
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

3.输出链表
void print() {//输出函数
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
4.输入链表（创造链表的时候一起搞了）
5.删除链表中的某一项（此处不涉及）
6.释放动态内存：
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












*/
































