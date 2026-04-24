#define _CRT_SECURE_NO_WARNINGS  // 必须放在所有 include 之前 禁用微软的安全警告
#include<iostream>
#include<cstring>
#include<stdexcept>
using namespace std;

//out of range 索引越界：访问的位置超出了容器的有效范围
//under flow error 数据下溢：容器 / 流已空，仍尝试取出数据
//getline(s,lenth)  输入带空格的字符串，
//英文、数字、符号：都是 1 个字节，值 ≤ 127
//汉字：都是 2 个字节，每个字节的值都 > 127
//char 是带符号，所以不转化为无符号，汉字都会<0

class String {
private:
	char* str;
	size_t lenth;
public:
	String();
	String(const char* s);
	String(const String& s);  //拷贝构造函数
	~String();
	size_t getlenth() const;
	char operator[](size_t index) const;
	String &operator=(const String& s);  //前面加了&，返回值就还是以前那个对象
	bool operator==(const String& s) const;   //优先级较低，加括号
	bool operator!=(const String& s) const;   //优先级较低，加括号
	String copy() const;
	String operator+(const String& s) const;  
	friend ostream& operator<<(ostream& out, const String& s);
};

String::String() {
	str = new char[1];
	str[0] = '\0';
	lenth = 0;   //不能省略
}

String::String(const char* s) {
	lenth = strlen(s);
	str = new char[lenth+1];   //虽然串的长度为lenth,但是申请内存需要+1
	for (int i = 0;i < lenth;i++)
	{
		str[i] = s[i];
	}
	str[lenth] = '\0';
	//strcpy(str,s);   //也可以用这个
}

String::String(const String& s){   //拷贝构造函数
	lenth = s.lenth;
	str = new char[lenth + 1];   //虽然串的长度为lenth,但是申请内存需要+1
	for (int i = 0;i < lenth;i++)
	{
		str[i] = s[i];
	}
	str[lenth] = '\0';
	//strcpy(str,s);   //也可以用这个
}


String::~String() {
	delete[] str;
}

size_t String::getlenth() const {
	return lenth;
}

char String::operator[](size_t index) const {
	if (index<0 || index>lenth) {
		throw std::out_of_range("index is unvalide");
	}
	return str[index];
}

String& String::operator=(const String& s) {
	if(this!=&s)
	{
		delete[] str;
		lenth = s.lenth;
		str = new char[lenth + 1];
		strcpy(str, s.str);
	}
	return *this;
}
bool String::operator==(const String& s) const
{
	return strcmp(str, s.str)==0;
}
bool String::operator!=(const String& s) const
{
	return strcmp(str, s.str)!=0;
}

String String::copy() const {
	String s = *this;  //看起来像赋值，但是相当于初始化的操作  String s(*this);
	//如果没有写拷贝构造函数，那么s和this的地址会一样，析构时，会析构两次  
	//printf("%p %p", s.str, this->str);
	return s;
}
String String::operator+(const String& s) const{
	String result;
	size_t newlen = strlen(str) + strlen(s.str);
	result.str = new char[newlen+1];
	strcpy(result.str, str);
	strcat(result.str, s.str);
	result.lenth = newlen;
	return result;
}

ostream& operator<<(ostream& out, const String& s) {   // out<<s<<A<<endl;   返回值为out
	out << s.str;									   //先运行out<<s， cout<<s.str  返回值为out
													   // 上面式子变成out<<A<<endl;  out<<A 返回一个out
	return out;										   // out<<endl; 结束
}

//int main()
//{
//	String s("123456");
//	cout << s << endl;
//	cout << s + "4567" <<" "<<s[2] <<  endl;
//	cout << (s == "3123") << " " << (s != "fde") << endl;  
//	cout << &s << endl;
//	s = s + "123";
//	cout << &s << endl;
//	String x = s.copy();  //如果没有写拷贝构造函数，那么这里相当于初始化，x和s的地址会一样，析构时会析构两次（free double）,会报错
//	cout << x << endl;
//	String a, b, c;
//	a = b = c = s;
//	cout << a << b << c << s << endl;
//
//}