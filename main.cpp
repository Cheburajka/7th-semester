#include "BinarySearchTree.h"
#include <iostream>

void Check();

int main()
{
	Check();
	return 0;
}

void Check()
{
	P_D_Tree::BinarySearchTree<int> BST;
	BST.Add(7);
	BST.Add(10);
	BST.Add(8);
	BST.Add(11);
	BST.Add(9);
	std::cout << "Binary tree: " << BST.InOrderPrint();
	std::cout << "\nSize:" << BST.GetSize();
	BST.Remove(8);
	std::cout << "\nBinary tree after delete node: " << BST.InOrderPrint();
	bool has_val = BST.HasValue(8);
	std::cout << "\nHas value 8: " << has_val;
}