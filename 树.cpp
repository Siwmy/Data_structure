#include<iostream>
using namespace std;

template<typename T>
struct ListNode {
	T data;
	ListNode* next;
	ListNode(T d) :data(d), next(NULL){}
};

template<typename T>
struct TreeNode {
	T data;
	ListNode< TreeNode<T>* >* childrenhead;     // 树的子节点是一个链表，链表里面每一个节点的类型为TreeNode<T>* 
	TreeNode() {
		childrenhead = NULL;
	}
	void Addchild(TreeNode<T>* node)			//树可能有多个子节点，用一个链表存下来 如果是俩就是TreeNode<T>* left，right
	{
		ListNode< TreeNode<T>* >* childnode = new ListNode< TreeNode<T>* >(node);
		childnode->next = childrenhead;
		childrenhead = childnode;
	}
};

template<typename T>
class Tree {
private:
	TreeNode<T>* nodes;
	TreeNode<T>* root;
public:
	Tree();
	Tree(int maxnode);
	~Tree();
	TreeNode<T>* GetTreeNode(int id);
	void SetRoot(int rootId);
	void AddChild(int parentid, int childid);
	void AssignData(int nodeId, T data);
	void Print(TreeNode<T> *node = NULL);

};

template<typename T>
Tree<T>::Tree() {
	nodes = new TreeNode<T>[10001];
}
template<typename T>
Tree<T>::Tree(int maxnode) {
	nodes = new TreeNode<T>[maxnode];
}
template<typename T>
Tree<T>::~Tree() {
	delete[] nodes;

}

template<typename T>
TreeNode<T>* Tree<T>::GetTreeNode(int id) {
	return &nodes[id];

}

template<typename T>
void Tree<T>::SetRoot(int rootId) {
	root = GetTreeNode(rootId);
}

template<typename T>
void Tree<T>::AddChild(int parentid, int childid) {
	TreeNode<T>* parentnode = GetTreeNode(parentid);
	TreeNode<T>* childnode = GetTreeNode(childid);
	parentnode->Addchild(childnode);
}

template<typename T>
void Tree<T>::AssignData(int nodeId, T data) {
	GetTreeNode(nodeId)->data = data;
}

template<typename T>
void Tree<T>::Print(TreeNode<T>* node) {
	if (node == NULL)
		node = root;
	cout << node->data;
	ListNode< TreeNode<T>* >* temp = node->childrenhead;  //childrenhead未初始化，会变成野指针，所以输出到g时，就输出不了了
	while (temp)
	{
		Print(temp->data);
		temp = temp->next;
	}
}


//int main()
//{
//	Tree<char> t(9);
//	t.AssignData(0, 'a');
//	t.AssignData(1, 'b');
//	t.AssignData(2, 'c');
//	t.AssignData(3, 'd');
//	t.AssignData(4, 'e');
//	t.AssignData(5, 'f');
//	t.AssignData(6, 'g');
//	t.AssignData(7, 'h');
//	t.AssignData(8, 'i');
//	t.SetRoot(0);
//	t.AddChild(0, 2);
//	t.AddChild(0, 1);
//	t.AddChild(1, 3);
//	t.AddChild(2, 5);
//	t.AddChild(2, 4);
//	t.AddChild(3, 8);
//	t.AddChild(3, 7);
//	t.AddChild(3, 6);
//	t.Print();
//
//}