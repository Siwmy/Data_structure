#include<iostream>
#include<stdexcept>
using namespace std;
#define eletype int

struct listNode {
	eletype data;
	listNode* next;
	listNode(eletype value):data(value),next(NULL){}
};
class linkedlist {
private:
	listNode* head;
	int size;
public:
	linkedlist():head(NULL),size(0){}
	~linkedlist();
	void insert(int i, eletype value);
	void remove(int i);
	listNode* find(eletype value);
	listNode* get(int i);
	void upgrate(int i, eletype value);
	void print();
};

linkedlist::~linkedlist() {
	listNode* curr = head;
	while (curr)
	{
		listNode* temp = curr;
		curr = curr -> next;
		delete temp;
	}
}
void linkedlist::insert(int i, eletype value) {
	if (i<0 || i>size)
		throw std::out_of_range("invalid location");
	listNode* newnode = new listNode(value);
	if (i == 0)
	{
		
		newnode->next = head;
		head = newnode;
		size++;
	}
	else
	{
		listNode* temp = head;
		for (int j = 0;j < i-1;j++)
			temp = temp->next;
		newnode->next = temp->next;
		temp->next = newnode;
		size++;
	}
	
}

void linkedlist::remove(int i) {
	if (i<0 || i>=size)
		throw std::out_of_range("invalid location");
	if (i == 0) {
		listNode* temp = head;
		head = temp->next;
		delete temp;
		size--;
	}
	else {
		listNode* temp = head;
		for (int j = 0;j < i - 1;j++)
			temp = temp->next;
		listNode *nextnode = temp->next;
		temp->next = nextnode -> next;
		delete nextnode;
		size--;
	}

}

listNode* linkedlist::find(eletype value) {
	listNode* temp = head;
	while (temp && temp->data != value)
		temp = temp->next;
	return temp;
}
	
listNode* linkedlist::get(int i) {
	if (i < 0 || i >= size)
		throw std::out_of_range("invalid location");
	listNode* temp = head;
	for (int j = 0; j < i;j++)
		temp = temp->next;
	return temp;

}

void linkedlist::upgrate(int i, eletype value) {
	if (i < 0 || i >= size)
		throw std::out_of_range("invalid location");
	get(i)->data = value;
}

void linkedlist::print() {
	listNode* temp = head;
	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}
int main() {
	linkedlist list;
	list.insert(0, 0);
	list.insert(1, 10);
	list.insert(2, 20);
	list.insert(3, 30);
	list.insert(4, 40);
	list.insert(5, 50);
	list.remove(3);
	list.upgrate(1, 520);
	list.upgrate(0, 530);
	cout << list.find(50)->data << endl;
	if (!list.find(80))
		cout << "链表里面不存在80" << endl;
	list.print();

}