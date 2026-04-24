#include<iostream>
using namespace std;


//！！！ new 类型（a）  表示申请 1 个节点，并用 a 初始化它
//       new 类型[a]    表示申请a个类型节点
template<typename T>
struct BinaryTreeNode {
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;
	BinaryTreeNode() :data(0), left(NULL), right(NULL) {}
	BinaryTreeNode(T d) :data(d), left(NULL), right(NULL) {}
	BinaryTreeNode(T d, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r) :data(d), left(l), right(r) {}

};

template<typename T>
class BinaryTree {
private:
	BinaryTreeNode<T>* nodes;  //看作一个数组  传入数组和树都从索引1开始，这样好计算左右节点
	BinaryTreeNode<T>* root;
	size_t nodeSize;
	BinaryTreeNode<T>* Create(T a[], int size, int nodeId, T nullNode);
	void visit(BinaryTreeNode<T>* node);
	void preOder(BinaryTreeNode<T>* node);
	void inOder(BinaryTreeNode<T>* node);
	void postOder(BinaryTreeNode<T>* node);
	void levelOder(BinaryTreeNode<T>* node) {}

public:
	BinaryTree();
	BinaryTree(int maxnode);
	~BinaryTree();
	BinaryTreeNode<T>* GetTreeNode(int id);
	void CreateTree(T a[], int size,  T nullNode);
	void preOder();
	void inOder();
	void postOder();
};

template<typename T>
BinaryTree<T>::BinaryTree() {
	nodeSize = 10001;
	nodes = new BinaryTreeNode<T>[10001];
}

template<typename T>
BinaryTree<T>::BinaryTree(int maxnode) {
	nodeSize = maxnode;
	nodes = new BinaryTreeNode<T>[maxnode];
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
	delete[] nodes;
}

template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::GetTreeNode(int id) {
	return &nodes[id];
}

template<typename T>
void BinaryTree<T>::visit(BinaryTreeNode<T>* node) {
	cout << node->data;
}



template<typename T>
void BinaryTree<T>::preOder(BinaryTreeNode<T>* node) {
	if (node) {
		visit(node);
		preOder(node->left);
		preOder(node->right);
	}
}

template<typename T>
void BinaryTree<T>::inOder(BinaryTreeNode<T>* node) {
	if (node) {
		inOder(node->left);
		visit(node);
		inOder(node->right);
	}
}

template<typename T>
void BinaryTree<T>::postOder(BinaryTreeNode<T>* node) {
	if (node) {
		postOder(node->left);
		postOder(node->right);
		visit(node);
	}
}

template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::Create(T a[], int size, int nodeId, T nullNode) {
	if (nodeId >= nodeSize || nodeId >= size || a[nodeId] == nullNode) {
		return NULL;
	}
	BinaryTreeNode<T>* nownode = GetTreeNode(nodeId);
	nownode->data = a[nodeId];
	nownode->left = Create(a, size, nodeId * 2, nullNode);
	nownode->right = Create(a, size, nodeId * 2+1, nullNode);
	return nownode;
}

template<typename T>
void BinaryTree<T>::CreateTree(T a[], int size, T nullNode) {
	root = Create(a, size, 1, nullNode);
}

template<typename T>
void BinaryTree<T>::preOder() {
	preOder(root);
}

template<typename T>
void BinaryTree<T>::inOder() {
	inOder(root);

}

template<typename T>
void BinaryTree<T>::postOder() {
	postOder(root);
}

//int main()
//{
//	const char nullNode = '-';
//	char a[15] = {
//		nullNode,'a','b','c','d',
//		nullNode,'e','f','g','h',
//		nullNode,nullNode,nullNode,nullNode,'i'
//	};
//	BinaryTree<char> t(15);
//	t.CreateTree(a, 15, nullNode);
//	t.preOder();cout << endl;
//	t.inOder();cout << endl;
//	t.postOder();
//
//
//}