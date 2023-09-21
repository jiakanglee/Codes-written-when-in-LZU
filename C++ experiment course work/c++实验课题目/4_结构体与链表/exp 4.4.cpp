#include <iostream>
using namespace std;
struct Messenger {
	char name[20];
	char address[20];
	char postcode[20];
	char telenum[20];
	char email[20];
	Messenger* next;
};
Messenger* head =NULL;
Messenger* Tail = NULL;
int compare(char a[], char b[]) {
	int flag = 0;
	if (strlen(a) != strlen(b))
		return 0;
	else {
		for (int i = 0; i < strlen(a); i++) {
			if (a[i] != b[i])
				flag = 1;
		}
	}
	if (flag == 1)
		return 0;
	if (flag == 0)
		return 1;
}
void init() {//初始化
	int flag = 1;
	Messenger* temp;
	Messenger* tail = head;
		while (flag == 1) {
        temp = new Messenger;
		cout << "please input the name,address,postcode,telenum,email:" << endl;
		cin >> temp->name >> temp->address >> temp->postcode >> temp->telenum >> temp->email;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			temp->next = NULL;
			tail = temp;
		}
		Tail = tail;
		cout << "if you wanna end the inputting enter 0,or enter 1:" << endl;
		cin >> flag;
		if (flag == 0)
			return;
	}
}
void print() {//显示
	Messenger* temp = head;
	while (temp!=NULL) {
		cout << "name.address,postcode,telenum,email:" << temp->name << " " << temp->address << " " << temp->postcode << " " << temp->telenum << " " << temp->email << endl;
		temp = temp->next;
	}
}
void delete_name(char search_name[20]) {//删除
	Messenger* temp = head;
	Messenger* front;
	front = temp;
	while (temp != NULL) {
		if (compare(temp->name, search_name))
		{   
			if (temp == head)//删除开头
				head = front->next;
			if (temp == Tail) {//删除结尾
				delete(temp);
				Tail = front;
				front->next = NULL;
				return;
			}
			front->next = temp->next;
			delete(temp);
			cout << "success!" << endl;
			return;
		}
		front = temp;
		temp = temp->next;
	}

}
void search(char query[20]) {//搜索
	Messenger* temp = head;
	Messenger* front;
	while (temp != NULL) {
		front = temp;
		if (compare(temp->name, query))
		{
			cout << "The query's name.address,postcode,telenum,email:" << temp->name << " " << temp->address << " " << temp->postcode << " " << temp->telenum << " " << temp->email << endl;
			return;
		}
		temp = temp->next;
	}
	cout << "nothing found" << endl;//没找到
}
void add() {//增加结点
	int number;
	cout << "Please enter how many records you wanna add:" << endl;
	cin >> number;
	Messenger* temp;
	Messenger* tail = Tail;
	for (int i = 1; i <= number; i++) {
		temp = new Messenger;
		cout << "please input the name,address,postcode,telenum,email:" << endl;
		cin >> temp->name >> temp->address >> temp->postcode >> temp->telenum >> temp->email;
		tail->next = temp;
		tail = temp;
		temp->next = NULL;
		Tail = temp;
	}


}
int main() {
	char query[20];
    init();
	print();
	cout << "Please input the name you wanna delete:" << endl;
	cin >> query;
	delete_name(query);
	cout << "Please input the name you wanna search:" << endl;
	cin >> query;
	search(query);
	print();
	add();
	print();







	return 0;
}