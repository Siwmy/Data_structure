#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
/*
1.检查索引位置是否合法
2.检查顺序表是否已满，如果已满则需要扩容，可以扩容两倍大小
3.将插入位置之后的元素依次后移
4.将新元素插入到指定位置
*/
#define eletype double

struct SequentialList
{
	eletype* data;
	int size;
	int capacity;
	SequentialList(int size) {
		this->size = 0;
		this->capacity = size;
		this->data = new eletype[size];
	}
	~SequentialList(){
		delete[] data;
		//cout << "顺序表已销毁" << endl;
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
			eletype* newdata = new eletype[newcapacity];
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

bool cmp(eletype a, eletype b) {
	return a < b;
}

int main1()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)break;
		SequentialList list(n);
		int sum_0 = 0, sum_1 = 0, sum_2 = 0;
		double a;
		double sum = 0;
		for (int i = 0;i < n;i++) {
			cin >> a;
			list.insert(i, a);
			sum += a;
		}
		sort(list.data, list.data + list.size, cmp);
		sum = sum - list.data[0] - list.data[n - 1];
		cout << fixed << setprecision(2) << sum / (n - 2) << endl;
		
	}
	return 0;
}