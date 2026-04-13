#include<iostream>
#include<vector>
/*
vector是C++标准库提供的一个动态数组容器，具有以下特点：
1.动态大小：vector可以根据需要自动调整大小，允许在运行时添加或删除元素。
2.连续内存：vector在内存中以连续的方式存储元素，这使得它在访问元素时具有较高的效率。
3.随机访问：vector支持通过索引进行随机访问，可以直接访问任意位置的元素。
用法示例：vector<数据类型> 名称；
函数用法：
1.push_back(value)：在vector末尾添加一个元素。
2.size()：返回vector中元素的数量。
3.capacity()：返回vector当前的容量，即在不进行扩容的情况下可以存储的元素数量。
4.at(index)：返回vector中指定位置的元素，并进行边界检查。
*/
using namespace std;
int main2() {
	vector<int> ret = { 1,2,3,4,5 };
	ret.push_back(60);
	for (int i = 0;i < ret.size();i++) {
		cout << ret[i] << " ";
	}
	cout << ret.at(2) << endl;
	return 0;
}