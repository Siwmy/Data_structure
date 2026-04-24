#define _CRT_SECURE_NO_WARNINGS  // 必须放在所有 include 之前 禁用微软的安全警告
#include<iostream>
#include<string>
#include<stdexcept>
#include <cstdio> 
using namespace std;
//getline(s,lenth)  输入带空格的字符串，
//英文、数字、符号：都是 1 个字节，值 ≤ 127
//汉字：都是 2 个字节，每个字节的值都 > 127
//char 是带符号，所以不转化为无符号，汉字都会<0


//int main()
//{
//	string s = "ggsfdgs";
//	cout << s.length();
//	char a = '6';
//	cout << int(a);
//}