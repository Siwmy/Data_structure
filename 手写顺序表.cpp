#include<iostream>
#include<cassert>
using namespace std;
/*
1.检查索引位置是否合法
2.检查顺序表是否已满，如果已满则需要扩容，可以扩容两倍大小
3.将插入位置之后的元素依次后移
4.将新元素插入到指定位置
*/

struct SequentialList
{
	int* data;
	int size;
	int capacity;
	SequentialList(int size) {
		this->size = 0;
		this->capacity = size;
		this->data = new int[size];
	}
	~SequentialList(){
		delete[] data;
		cout << "顺序表已销毁" << endl;
	}

	void insert(int index, int value) {  //插入
		if (index<0 || index>size)
		{
			cout << "索引位置不合法" << endl;
			return;
		}
		if (size == capacity) {
			int newcapacity = capacity * 2;
			if (newcapacity == 0) newcapacity = 1; //处理初始容量为0的极端情况
			int* newdata = new int[newcapacity];
			for (int i = 0;i < size;i++) {
				newdata[i] = data[i];
			}
			delete[] data;
			data = newdata;
			capacity = newcapacity;
		}
		
		for (int i = size;i > index;i--) {
			data[i] = data[i - 1];
		}
		data[index] = value;
		size++;
		
	}

	void deleteList(int index) {
		if (index < 0 || index >= size) {
			cout << "索引位置不合法" << endl;
			return;
		}
		for (int i = index;i < size - 1;i++) {
			data[i] = data[i + 1];
		}
		size--;
	}

	void change(int index, int value) {
		if (index < 0 || index >= size) {
			cout << "索引位置不合法" << endl;
			return;
		}
		data[index] = value;
	}
	int find(int value)
	{
		for (int i = 0;i < size;i++)
		{
			if (data[i] == value)
				return i;
		}
		return -1;
	}
};


int main1()
{
	SequentialList list(10);
	cout << list.capacity << " " << list.size << endl;
	for (int i = 0;i < 10;i++)
		list.insert(i, i * 10);
	for (int i = 0;i < list.size;i++)
		cout << list.data[i] << " ";
	cout << endl;
	list.change(2, 520);
	for (int i = 0;i < list.size;i++)
		cout << list.data[i] << " ";
	cout << endl;
	list.insert(6, 1090);
	cout << list.capacity << " " << list.size << endl;
	for (int i = 0;i < list.size;i++)
		cout << list.data[i] << " ";
	cout << endl;
	list.deleteList(4);
	for (int i = 0;i < list.size;i++)
		cout << list.data[i] << " ";
	cout << endl;
	return 0;
}