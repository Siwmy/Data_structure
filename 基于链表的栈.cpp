#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T>
class Stack {
private:
	struct Node {
		T data;
		Node* next;
		Node(T a) :data(a), next(NULL) {}
	};
	Node* head;
	int size;
public:
	Stack():head(NULL),size(0){}
	~Stack();
	void push(T element);
	T pop();
	T top() const;
	int getsize() const;
};

template<typename T>
Stack<T>::~Stack() {
	while (head)
	{
		Node* tem = head;
		head = head->next;
		delete tem;
	}
}

template<typename T>
void Stack<T>::push(T element) {
	Node* tem = new Node(element);
	tem->next = head;
	head = tem;
	size++;
}

template<typename T>
T Stack<T>::pop() {
	if (size == 0)
		throw std::underflow_error("stack is empty");
	T value = head->data;
	Node* tem = head;
	head = head->next;
	delete tem;
	size--;
	return value;
}

template<typename T>
T Stack<T>::top() const{
	if (size == 0)
		throw std::underflow_error("stack is empty");
	return head->data;
}

template<typename T>
int Stack<T>::getsize() const{
	return size;
}

//int main()
//{
//	Stack<int>st;
//	st.push(10);
//	st.push(20);
//	st.push(30);
//	st.push(40);
//	st.push(50);
//	cout << st.top() << " " << st.getsize() << endl;
//	st.pop();
//	st.pop();
//	cout << st.top() << " " << st.getsize() << endl;
//	st.push(777);
//	cout << st.top() << " " << st.getsize() << endl;
//}