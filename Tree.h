#pragma once
#include <iostream>
using namespace std;

struct Tree {
	int index;
	char label;
	int parent;
	static int TreeSize;
};

Tree* Makenull(Tree*);
Tree Parent(int, Tree*);
Tree LeftmostChild(int, Tree*);
Tree RightSibling(int, Tree*);
char Label(int, Tree*);
Tree Root(Tree*);

void Insert(int, char, int, Tree*);
bool isLeaf(Tree, Tree*);

void preOrder(Tree, Tree*);
void postOrder(Tree, Tree*);
void inOrder(Tree, Tree*);