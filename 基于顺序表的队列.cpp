#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T>
class Queue {
private:
	T* data;
	int front;
	int rear;  //指向队列后一个位置。  队列范围0 - capacity-1  
	int capacity;
	void resize();

public:
	Queue() :data(new T[10]), front(0), rear(0), capacity(10){}
	~Queue();
	void enqueue(T val);
	T dequeue();
	T getfront() const;
	int getsize() const;
	bool empty() const;

};

template<typename T>
Queue<T>::~Queue() {
	delete[] data;
}

template<typename T>
void Queue<T>::resize() {
	T* newdata = new T[capacity * 2];
	for (int i = 0;i < rear;i++)
	{
		newdata[i] = data[i];
	}
	delete[] data;
	data = newdata;
	capacity *= 2;
}

template<typename T>
void Queue<T>::enqueue(T val) {
	if (rear == capacity)resize();
	data[rear++] = val;
}

template<typename T>
T Queue<T>::dequeue() {
	if (front == rear)
		throw std::underflow_error("queue is empty");
	return data[front++];
}

template<typename T>
T Queue<T>::getfront() const{
	if (front == rear)
		throw std::underflow_error("queue is empty");
	return data[front];
}

template<typename T>
int Queue<T>::getsize() const{
	return rear - front;
}

template<typename T>
bool Queue<T>::empty() const {
	return getsize()==0;
}


//用队列实现栈的诀窍在于用第一个栈作为基准，每次操作完后又放回第一个栈


class MyStack {
private:
	Queue<int> q1;
	Queue<int> q2;
public:
	MyStack() {
	}
	void push(int x);
	int pop();
	int top();
	bool empty() const;
};

void MyStack::push(int x) {
	q1.enqueue(x);
}

int MyStack::pop() {
	while (q1.getsize() > 1)
	{
		q2.enqueue(q1.dequeue());
	}
	int ans = q1.getfront();
	q2.enqueue(q1.dequeue());
	while (!q2.empty())
	{
		q1.enqueue(q2.dequeue());
	}
	return ans;
}

int MyStack::top() {
	while (q1.getsize() > 1)
	{
		q2.enqueue(q1.dequeue());
	}
	int ans = q1.dequeue();
	while (!q2.empty())
	{
		q1.enqueue(q2.dequeue());
	}
	return ans;
}

bool MyStack::empty() const {
	return q1.getsize() == 0;
}


//int main()
//{
//	Queue<int> q;
//	q.enqueue(1);
//	q.enqueue(2);
//	q.enqueue(3);
//	q.enqueue(4);
//	cout << q.getfront() << " "<<q.getsize()<<endl;
//	q.dequeue();
//	q.dequeue();
//	q.enqueue(7);
//	cout << q.getfront()  << " " << q.getsize() << endl;
//	cout << q.dequeue() << " " << q.getsize() << endl;
//}