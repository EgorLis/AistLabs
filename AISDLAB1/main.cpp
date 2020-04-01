#include<iostream>

#include"map.cpp"
int main() {

	Map<int, int>* tree = new Map<int, int>();

	tree->insert(5, -2);
	tree->insert(3, -3);
	tree->insert(11, -4);
	tree->insert(12, -5);
	tree->insert(6, -5);
	tree->insert(8, -6);
	tree->insert(9, -7);
	tree->insert(7, -8);
	tree->Delete(8);
	tree->printTree();

	system("pause");
	return 0;
}