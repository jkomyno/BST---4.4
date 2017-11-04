#pragma once
#include <iostream>
#include "Node.h"
using std::ostream;
using std::endl;

template <class T> class BST;

template <class T>
ostream& operator<<(ostream&, const BST<T>&);

template <class T>
class BST {
	friend ostream& operator<<<T>(ostream&, const BST<T>&);
public:
	BST() :
		root(nullptr) {}
	Node<T>* Find(T) const;
	Node<T>* Minimum() const;
	Node<T>* Maximum() const;
	Node<T>* Next(Node<T>*) const;
	Node<T>* Prev(Node<T>*) const;
	void Insert(T);
	static T Value(Node<T>*);
private:
	Node<T>* root;
	// static utilities
	static Node<T>* FindRec(Node<T>*, T);
	static Node<T>* MinimumRec(Node<T>*);
	static Node<T>* MaximumRec(Node<T>*);
	static void InsertRec(Node<T>*, T);
};

template <class T>
T BST<T>::Value(Node<T>* r) {
	return r->info;
}

template <class T>
Node<T>* BST<T>::FindRec(Node<T>* r, T val) {
	// base case 1: tree is empty
	// base case 2: value is at current node
	if (r == nullptr || r->info == val) {
		return r;
	}
	if (val < r->info) {
		return FindRec(r->left, val);
	}
	else {
		return FindRec(r->right, val);
	}
}

template <class T>
Node<T>* BST<T>::Find(T val) const {
	return FindRec(root, val);
}

template <class T>
Node<T>* BST<T>::MinimumRec(Node<T>* r) {
	// r != nullptr

	if (r->left == nullptr) {
		return r;
	}
	return MinimumRec(r->left);
}

template <class T>
Node<T>* BST<T>::Minimum() const {
	if (root == nullptr) {
		return root;
	}
	else {
		return MinimumRec(root);
	}
}

template <class T>
Node<T>* BST<T>::MaximumRec(Node<T>* r) {
	// r != nullptr

	if (r->right == nullptr) {
		return r;
	}
	return MaximumRec(r->right);
}

template <class T>
Node<T>* BST<T>::Maximum() const {
	if (root == nullptr) {
		return root;
	}
	else {
		return MaximumRec(root);
	}
}

template <class T>
Node<T>* BST<T>::Next(Node<T>* r) const {
	/*
	if Node(r) has the right subtree r_d, then r's successor is the minimum of r_d;
	else, the r's successor is the "youngest" r's parent of which r is left descendant
	*/
	
	if (r == nullptr) {
		return r;
	}
	if (r->right) {
		return MinimumRec(r->right);
	}
	while (r->parent && r->parent->right == r) {
		r = r->parent;
	}
	return r->parent;
}

template <class T>
Node<T>* BST<T>::Prev(Node<T>* r) const {
	if (r == nullptr) {
		return r;
	}
	if (r->left) {
		return MaximumRec(r->left);
	}
	while (r->parent && r->parent->left == r) {
		r = r->parent;
	}
	return r->parent;
}

template <class T>
void BST<T>::InsertRec(Node<T>* r, T val) {
	// r != nullptr

	if (val < r->info) {
		if (r->left == nullptr) {
			r->left = new Node<T>(val, r);
		}
		else {
			InsertRec(r->left, val);
		}
	}
	else {
		if (r->right == nullptr) {
			r->right = new Node<T>(val, r);
		}
		else {
			InsertRec(r->right, val);
		}
	}
}

template <class T>
void BST<T>::Insert(T val) {
	if (root == nullptr) {
		root = new Node<T>(val);
	}
	else {
		InsertRec(root, val);
	}
}

template <class T>
ostream& operator<<(ostream& os, const BST<T>& t) {
	os << t.root << endl; // calls Node's operator<<
	return os;
}
