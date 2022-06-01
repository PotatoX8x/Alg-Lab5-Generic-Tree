#include "Tree.h"

int main() {
	Tree* A = nullptr;
	A = Makenull(A);
	Insert(0, '^', 0, A);
	Insert(1, 'a', 0, A);
	Insert(2, 's', 0, A);
	Insert(3, '*', 2, A);
	Insert(4, '+', 2, A);
	Insert(5, '-', 2, A);
	Insert(6, '2', 3, A);
	Insert(7, 'c', 3, A);
	Insert(8, 'b', 4, A);
	Insert(9, '3', 5, A);
	cout << "PreOrder tree traversal: " << endl;
	preOrder(A[0], A);
	cout << endl << endl << "PostOrder tree traversal: " << endl;
	postOrder(A[0], A);
	cout << endl << endl << "InOrder tree traversal: " << endl;
	inOrder(A[0], A);
	return 0;
}