#include <iostream>
using namespace std;
typedef struct node
{
	int elem;
	node* next;
} Node;
int main() {
	Node* head = NULL;
	Node* tail = NULL;
	cout << "input the value for the node you've newly built,enter 0 to stop:  " << endl;
	int k;
	cin >> k;
	while(k!=0)
	{
		int i = 1;
		Node* pNode = new Node;
		pNode->elem = k; //�ڵ㸳���ֵ
		pNode->next = NULL; //�ڵ㸳ֵΪNULL
		if (pNode == NULL) //�жϷ����Ƿ�ɹ�
		{
			cout << "Memory insufficient!";
			break;
		}
		//�����潨�����½ڵ�ӵ������еĹ���Ϊ��
		if (head == NULL) //����ǵ�һ���ڵ㣬����Ϊ��
		{
			head = tail = pNode; //��һ���ڵ����ͷҲ��β��
		}
		else
		{
			tail->next = pNode; //β�ڵ��ָ��ָ���½ڵ㣬�����½ڵ�ӵ�������
			tail = pNode; //�½ڵ���뵽����β����βָ��ָ��ýڵ㡣
		}
		i++;
		cout << "input the value for the node you've newly built,enter 0 to stop:  " << endl;
		cin >> k;
	}
	//˳���������Ĺ���Ϊ��
		Node* pNode = head; //��һ��ָ��pNode ָ������ͷ
		cout << "Link elements:";
	while (pNode != NULL)
	{   
		
		cout <<pNode->elem <<" " ;// ����ڵ�洢�����ݣ�Ҳ�����Ƿ���pNode ��ָ�ڵ�
		//���ݵ�������䣻
		pNode = pNode->next; //��pNode ָ����һ���ڵ㡣
	}
	Node* pNode = head;
	Node* temp = pNode;
	while (pNode != NULL)
	{
		temp = pNode->next;
		if (temp == NULL)
			break;
		delete(pNode);
		//��pNode ָ����һ���ڵ㡣
	}
	return 0;
}