#include<iostream>
#include "BinaryTreeSearch.h"

int main()
{
    BinarySearchTree BST;
    BST.Insert(5);
    BST.Insert(15);
    BST.Insert(10);
    BST.Insert(3);
    BST.Insert(2);
    BST.Insert(75);
    BST.Insert(4);
    BST.Insert(65);
    BST.Insert(77);
    BST.Insert(76);
    BST.Insert(79);
    BST.Traverse();

    std::cout << "____________________________" << std::endl;
    std::cout << std::endl;
    BST.Find(2);
    BST.Find(75);
    BST.Find(13);
    std::cout << std::endl;
    std::cout << "____________________________" << std::endl;

    BST.Delete(75);
    BST.Traverse();
}