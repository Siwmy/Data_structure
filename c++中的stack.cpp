#include<iostream>
#include<stdexcept>
#include<stack>
using namespace std;

/*
四种操作：
empty(),空返回1，非空返回0
pop()
push(v)
top()
size() 返回数量
*/

//栈的应用，嵌套的窗口关闭，先关闭后打开的


//int main()
//{
//	stack<int> intstk;
//	stack<double> doublestk;
//
//	intstk.push(1);
//	intstk.push(2);
//	intstk.push(3);
//	intstk.push(4);
//	intstk.push(5);
//	while (!intstk.empty())
//	{
//		cout << intstk.top() << endl;
//		intstk.pop();
//	}
//	return 0;
//}