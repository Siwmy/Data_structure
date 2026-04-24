#include<iostream>
#include<stdexcept>

using namespace std;

template<typename T>
class Queue {
private:
	struct Node {
		T data;
		Node* next;
		Node(T t):data(t),next(NULL){}
	};
	Node* front;
	Node* rear;
	int size;
public:
	Queue() :front(NULL), rear(NULL), size(0) {}
	~Queue();
	void enqueue(T t);
	T dequeue();
	int getsize() const;
	T getfront() const;
};

template<typename T>
Queue<T>::~Queue() {
	while (front)
	{
		Node* temp = front;
		front = front->next;
		delete temp;
	}
}

template<typename T>
void Queue<T>::enqueue(T t) {
	Node* temp = new Node(t);
	if (front == NULL)   //队列为空的情况下
	{
		front = temp;
		rear = front;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
	size++;
}

template<typename T>
T Queue<T>::dequeue() {
	if (front == NULL)
		throw std::underflow_error("queue is empty");
	Node* temp = front;
	T value = temp->data;
	front = front->next;
	if (size == 0)
		rear = NULL;
	delete temp;
	size--;
	return value;

}

template<typename T>
int Queue<T>::getsize() const {
	return size;
}

template<typename T>
T Queue<T>::getfront() const {
	if (front == NULL)
		throw std::underflow_error("queue is empty");
	return front->data;
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
//	cout << q.getfront();
//
//}