#include <iostream>
#include "BinaryTreeSearch.h"

BinarySearchTree::Node* BinarySearchTree::Insert(int v, Node* x) // вставка узла в дерево
{
    if (x == nullptr)
    {
        Node* newNode = new Node;
        newNode->value = v;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    else if (v < x->value)
    {
        x->left = Insert(v, x->left);
        return x;
    }
    else
    {
        x->right = Insert(v, x->right);
        return x;
    }
}

void BinarySearchTree::Traverse(Node* x) // прямой обход дерева
{
   if (x != nullptr)
   {
   if (x->value == root->value) { std::cout << "ROOT:" << std::endl; }
   else if (x->value < root->value) { std::cout << std::endl << "LEFT:" << std::endl; }
   else if (x->value > root->value) { std::cout << std::endl << "RIGHT:" << std::endl; }

   std::cout << x->value << std::endl;
   Traverse(x->left);
   Traverse(x->right);
   }
}

BinarySearchTree::Node* BinarySearchTree::Find(int v, Node* x) // поиск узла в дереве
{
    if (x == nullptr) { return nullptr; }
    else
    {
        if (v == x->value) { return x; }
        else if (v < x->value) { return Find(v, x->left); }
        else { return Find(v, x->right); }
    }
}

BinarySearchTree::Node* BinarySearchTree::Delete(int v, Node* x) // удаление узла из дерева
{
    if (x == nullptr) { return x; }
    else if (v < x->value) { x->left = Delete(v, x->left); }
    else if (v > x->value) { x->right = Delete(v, x->right); }
    else // узел найден
    {
        if (x->left == nullptr && x->right == nullptr) // случай 1: у узла нет дочерних узлов
        {
            delete x;
            x = nullptr;
        }
        else if (x->left == nullptr) // случай 2: у узла один дочерний узел (правый)
        {
            Node* temp = x;
            x = x->right;
            delete temp;
        }
        else if (x->right == nullptr) // случай 2: у узла один дочерний узел (левый)
        {
            Node* temp = x;
            x = x->left;
            delete temp;
        }
        else // случай 3: у узла два дочерних узла
        {
            Node* temp = x->right;
            Node* parent = x;

            while (temp->left != nullptr)
            {
                parent = temp;
                temp = temp->left;
            }
            x->value = temp->value;

            if (parent->left == temp) { parent->left = temp->right; }
            else { parent->right = temp->right; }

            delete temp;
        }
    }
    return x;
}

BinarySearchTree::BinarySearchTree() // пустое дерево
{
   root = nullptr;
}

void BinarySearchTree::Insert(int v) // вставка узла в дерево
{
   if (root == nullptr) { root = Insert(v, root); }
   else { Insert(v, root); }
}

void BinarySearchTree::Traverse() // обход дерева
{
   Traverse(root);
}

void BinarySearchTree::Find(int v) // поиск узла в дереве
{
    if (Find(v, root) != nullptr) { std::cout << "Element found." << std::endl; }
    else { std::cout << "Element not found." << std::endl; }
}

void BinarySearchTree::Delete(int v) // удаление узла из дерева
{
   root = Delete(v, root);
}