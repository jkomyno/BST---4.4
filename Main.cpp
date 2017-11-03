#include <iostream>
#include "Node.h"
#include "BST.h"
using namespace std;

int main() {
	BST<int> a;

	a.Insert(3);
	a.Insert(2);
	a.Insert(3);
	a.Insert(1);
	a.Insert(6);
	a.Insert(5);

	cout << a << endl;
}