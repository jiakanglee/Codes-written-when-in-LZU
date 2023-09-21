#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<string.h>
#include<queue>
#include<map>
#include<bits/stdc++.h>
using namespace std;
int N,k;
 struct node{
     int ID;//ID就是编号
     int status;//status是这个猴子有没有被抽走，1是没抽走，0是抽走了
     node*next;
};
node*current,*previous,*t,*head;
void createlist(){//链表初始化+赋值
    for(int i=1;i<=N;i++){
current=(node*)malloc(sizeof(node));
current->ID=i;
current->status=1;
current->next=NULL;
if(head==NULL){
    head=current;
}
else previous->next=current;
previous=current;
if(i==N)//特别注意这个地方运用了循环链表，把它的尾部的最后一个结点的next指针表示为头结点的位置
{
    current->next=head;
}
    }
}
int main(){
cin>>N>>k;
 createlist();//初始化
 int number=N;//number是现存猴子数
 int count=1;//count代表满足规范的步数
 t=head;//t只是个head的代词，并无实际意义
 while(number!=1){//
    if(count==k&&t->status!=0)
        //满足要求时，把status弄成0，猴子数--，count初始化
      {

      t->status=0;
    number--;
    count=0;

    }
   /* else if(count==k&&t->status==0){
        while(t->status==0)
            t=t->next;
        t->status=0;
        number--;
        count=0;
    }*/
if((t->next)->status==0){//该判断是保证每一步都是符合规范的
   t=t->next;
   while(t->status!=1)
    t=t->next;
    count++;
    continue;
}

    t=t->next;
    count++;
 }
 t=head;
while(t->status!=1){
    t=t->next;
}
printf("%d",t->ID);
return 0;
}
