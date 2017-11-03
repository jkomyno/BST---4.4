#pragma once
#include <iostream>
using std::ostream;

template <class T> class Node;

template<class T> ostream& operator<< (ostream&, Node<T>*);

template <class T>
class Node {
	friend class BST<T>; // associated friend class
	friend ostream& operator<< (ostream&, Node<T>*);

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
	if (p == nullptr) {
		os << '@';
	}
	else {
		os << '(' << n->info << ',' << n->left << ',' << n->right << ')';
	}
	return os;
}
