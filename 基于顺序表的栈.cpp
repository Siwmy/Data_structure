#include<iostream>
#include<stdexcept>
using namespace std;

/*
栈：用于函数调用、递归、表达式求值等操作
这里栈顶指针在栈顶元素上面。
template<typename T> = 开模板
T = 任意类型的代号
作用：一套代码支持所有类型，不用重复写
例子1：
template<typename T>
T add(T a, T b) {
    return a + b;
}
add<int>(1, 2);
add<double>(1.5, 2.3);
add<string>("a", "b");

例子2：
template<typename T>
class complex {
public:
    T real;
    T fake;
};
complex<int> c1;     // 整数复数
complex<double> c2;  // 小数复数
*/

template<typename T>
class Stack {
private:
    T* data;
    int size;     //数据存储位置 0 - capacity-1 ,  size大一位，栈满size == capacity 栈空 size==0
    int capacity;
public:
    Stack() :data(new T[10]), size(0), capacity(10) {}
    ~Stack();
    void push(T value);
    T pop();
    T top() const;
    int getsize() const;
    bool empty() const;
};

template<typename T>
Stack<T>::~Stack() {
    delete[] data;
}

template<typename T>
void Stack<T>::push(T value) {
    if (size == capacity)
    {
        int newcapacity = capacity * 2;
        T* newdata = new T[newcapacity];
        for (int i = 0;i < size;i++)
        {
            newdata[i] = data[i];
        }
        data = newdata;
        capacity = newcapacity;
    }
    data[size++] = value;
}

template<typename T>
T Stack<T>::pop() {
    if (size == 0)
        throw std::underflow_error("stack is empty");
    return data[--size];
}

template<typename T>
T Stack<T>::top() const {
    if (size == 0)
        throw std::underflow_error("stack is empty");
    return data[size - 1];
}

template<typename T>
int Stack<T>::getsize() const {
    return size;
}

template<typename T>
bool Stack<T>::empty() const {
    return getsize() == 0;
}


//用栈实现队列的诀窍在于用第一个栈作为基准，每次操作完后又放回第一个栈
class MyQueue {
private:
    Stack<int> stk1;
    Stack<int> stk2;

public:
    MyQueue(){}
    void push(int d);
    int pop();
    int peek();
    bool empty() const;

};

void MyQueue::push(int d) {
    stk1.push(d);
}

int MyQueue::pop() {
    while (stk1.getsize() > 1) {
        stk2.push(stk1.pop());
    }
    int ans = stk1.pop();
    while (!stk2.empty())
    {
        stk1.push(stk2.pop());
    }
    return ans;
}

int MyQueue::peek() {
    while (stk1.getsize() > 1) {
        stk2.push(stk1.pop());
    }
    int ans = stk1.top();
    stk2.push(stk1.pop());
    while (!stk2.empty())
    {
        stk1.push(stk2.pop());
    }
    return ans;
}
bool MyQueue::empty() const{
    return stk1.empty();
}




//int main()
//{
//    Stack<int> st;
//    st.push(10);
//    st.push(20);
//    st.push(30);
//    st.push(40);
//    st.push(50);
//    cout << st.top() << " "<<st.getsize()<<endl;
//    st.pop();
//    st.pop();
//    cout << st.top() << " " << st.getsize() << endl;
//    st.pop();
//    st.pop();
//	return 0;
//}