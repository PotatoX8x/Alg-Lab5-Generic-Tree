#include "Tree.h"

int Tree::TreeSize = 10;

Tree* Makenull(Tree* A) {
	A = new Tree[Tree::TreeSize];
	for (int i = 0; i < Tree::TreeSize; i++) {
		A[i].parent = 0;
	}
	return A;
}

Tree Parent(int n, Tree* A) {
	return A[A[n].parent];
}

Tree LeftmostChild(int n, Tree* A) {
	for (int i = n + 1; i < Tree::TreeSize; i++) {
		if (A[i].parent == n) {
			return A[i];
		}
	}
	return A[0];
}

Tree RightSibling(int n, Tree* A) {
	if (A[n + 1].parent == A[n].parent) {
		return A[n + 1];
	}
	return A[0];
}

char Label(int n, Tree* A) {
	return A[n].label;
}

Tree Root(Tree* A) {
	return A[0];
}

void Insert(int n, char x, int p, Tree* A){
	A[n].index = n;
	A[n].label = x;
	A[n].parent = p;
}

bool isLeaf(Tree n, Tree* A) {
	if (LeftmostChild(n.index, A).index == 0) {
		return true;
	}
	return false;
}

void preOrder(Tree n, Tree* A) {
	cout << Label(n.index, A) << "_";
	if (!isLeaf(n, A)) {
		Tree tmp = LeftmostChild(n.index, A);
		while (tmp.index != 0) {
			preOrder(tmp, A);
			tmp = RightSibling(tmp.index, A);
		}
	}
}

void postOrder(Tree n, Tree* A) {
	if (!isLeaf(n, A)) {
		Tree tmp = LeftmostChild(n.index, A);
		while (tmp.index != 0) {
			postOrder(tmp, A);
			tmp = RightSibling(tmp.index, A);
		}
	}
	cout << Label(n.index, A) << "_";
}

void inOrder(Tree n, Tree* A) {   
	if (isLeaf(n, A))
		cout << Label(n.index, A) << "_";
	else {
		Tree tmp = LeftmostChild(n.index, A);
		while (tmp.index != 0) {
			inOrder(tmp, A);
			if (tmp.index == LeftmostChild(tmp.parent, A).index) {
				cout << Parent(tmp.index, A).label << "_";
			}
			tmp = RightSibling(tmp.index, A);
		}
	}
}