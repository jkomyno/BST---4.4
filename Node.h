#pragma once
#include <iostream>
// using std::ostream;

using namespace std;

template <class T> class BST;

template <class T> class Node;

template<class T>
ostream& operator<<(ostream&, Node<T>*);

template <class T>
class Node {
	friend class BST<T>; // associated friend class
	friend ostream& operator<<<T>(ostream&, Node<T>*);

private:
	T info;
	Node *parent, *left, *right;
	Node(const T& v, Node* p = nullptr, Node* l = nullptr, Node* r = nullptr) :
		info(v),
		parent(p),
		left(l),
		right(r) {}
};

template <class T>
ostream & operator<< (ostream& os, Node<T>* n) {
	if (n == nullptr) {
		os << '@';
	}
	else {
		os << '(' << n->info << ',' << n->left << ',' << n->right << ')';
	}
	return os;
}
