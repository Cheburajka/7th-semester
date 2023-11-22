#include <iostream>
#include "BinaryTreeSearch.h"

BinarySearchTree::Node* BinarySearchTree::Insert(int v, Node* x) // ������� ���� � ������
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

void BinarySearchTree::Traverse(Node* x) // ������ ����� ������
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

BinarySearchTree::Node* BinarySearchTree::Find(int v, Node* x) // ����� ���� � ������
{
    if (x == nullptr) { return nullptr; }
    else
    {
        if (v == x->value) { return x; }
        else if (v < x->value) { return Find(v, x->left); }
        else { return Find(v, x->right); }
    }
}

BinarySearchTree::Node* BinarySearchTree::Delete(int v, Node* x) // �������� ���� �� ������
{
    if (x == nullptr) { return x; }
    else if (v < x->value) { x->left = Delete(v, x->left); }
    else if (v > x->value) { x->right = Delete(v, x->right); }
    else // ���� ������
    {
        if (x->left == nullptr && x->right == nullptr) // ������ 1: � ���� ��� �������� �����
        {
            delete x;
            x = nullptr;
        }
        else if (x->left == nullptr) // ������ 2: � ���� ���� �������� ���� (������)
        {
            Node* temp = x;
            x = x->right;
            delete temp;
        }
        else if (x->right == nullptr) // ������ 2: � ���� ���� �������� ���� (�����)
        {
            Node* temp = x;
            x = x->left;
            delete temp;
        }
        else // ������ 3: � ���� ��� �������� ����
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

BinarySearchTree::BinarySearchTree() // ������ ������
{
   root = nullptr;
}

void BinarySearchTree::Insert(int v) // ������� ���� � ������
{
   if (root == nullptr) { root = Insert(v, root); }
   else { Insert(v, root); }
}

void BinarySearchTree::Traverse() // ����� ������
{
   Traverse(root);
}

void BinarySearchTree::Find(int v) // ����� ���� � ������
{
    if (Find(v, root) != nullptr) { std::cout << "Element found." << std::endl; }
    else { std::cout << "Element not found." << std::endl; }
}

void BinarySearchTree::Delete(int v) // �������� ���� �� ������
{
   root = Delete(v, root);
}