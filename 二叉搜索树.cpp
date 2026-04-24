#include<iostream>
using namespace std;

template<typename T>
struct TreeNode {
	T val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr){}
	TreeNode(T d) :val(d), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinarySearchTree {
private:
	TreeNode<T>* root;
	TreeNode<T>* insertNode(TreeNode<T>* rt, T d);
	TreeNode<T>* removeNode(TreeNode<T>* rt , T target);
	bool SearchNode(TreeNode<T>* rt, T target);
	void inOder(TreeNode<T>* rt);
public:
	BinarySearchTree():root(nullptr){}
	~BinarySearchTree();
	void insert(T d) {
		root = insertNode(root, d);
	}
	void remove(T d) {
		root = removeNode(root, d);
	}
	bool search(T d)
	{
		return SearchNode(root, d);
	}
	void inOdertraversal() {
		inOder(root);
		cout << endl;
	}
};

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
	while (root)
	{
		remove(root->val);
	}
}

template<typename T>
TreeNode<T>* BinarySearchTree<T>::insertNode(TreeNode<T>* rt, T d) {
	if (rt == NULL) return new TreeNode<T>(d);
	if (rt->val > d) {
		rt->left = insertNode(rt->left, d);
	}
	else if (rt->val < d) {
		rt->right = insertNode(rt->right, d);
	}
	return rt;
}

template<typename T>
TreeNode<T>* BinarySearchTree<T>::removeNode(TreeNode<T>* rt, T target) {
	if (rt == NULL)return NULL;
	if (target < rt->val) {
		rt->left = removeNode(rt->left, target);
	}
	else if (target > rt->val) {
		rt->right = removeNode(rt->right, target);
	}
	else {
		if (rt->left == NULL && rt->right == NULL) {
			delete rt;
			return NULL;
		}
		else if (rt->right == NULL)
		{
			TreeNode<T>* tem = rt->left;
			delete rt;
			return tem;
		}
		else if (rt->left == NULL) {
			TreeNode<T>* tem = rt->right;
			delete rt;
			return tem;
		}
		else {
			TreeNode<T>* tem = rt->right;
			while (tem->left) {
				tem = tem->left;
			}
			rt->val = tem->val;
			rt->right = removeNode(rt->right, tem->val);
		}

	}
	return rt;
}

template<typename T>
bool BinarySearchTree<T>::SearchNode(TreeNode<T>* rt, T target) {
	if (rt == NULL)return false;
	if (rt->val > target) {
		return SearchNode(rt->left, target);
	}
	else if (rt->val < target) {
		return SearchNode(rt->right, target);
	}
	else
		return true;
}

template<typename T>
void BinarySearchTree<T>::inOder(TreeNode<T>* rt) {
	if (rt)
	{
		inOder(rt->left);
		cout << rt->val << " ";
		inOder(rt->right);
	}
}

int main()
{
	BinarySearchTree<int> t;
	t.insert(10);
	t.insert(5);
	t.insert(15);
	t.insert(2);
	t.insert(3);
	t.insert(1);
	t.insert(11);
	t.insert(16);
	t.insert(14);
	t.inOdertraversal();
	cout<<t.search(3);
	cout << t.search(100);
	t.remove(10);
	cout << endl;
	t.inOdertraversal();
	t.insert(7);
	t.inOdertraversal();
	t.remove(19);
}