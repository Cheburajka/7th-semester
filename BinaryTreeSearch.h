#include <iostream>

class BinarySearchTree
{
private:
    struct Node // ��������� ����
    {
        int value;
        Node* left;
        Node* right;

        Node()
        {
            value = 0;
            left = nullptr;
            right = nullptr;
        }
        ~Node()
        {
            left = nullptr;
            right = nullptr;
        }
    
    };
    Node* root; // ���� - ������ ������

    Node* Insert(int v, Node* x); // ������� ���� � ������
    void Traverse(Node* x); // �����
    Node* Find(int v, Node* x); // ����� ���� � ������
    Node* Delete(int v, Node* x); // �������� ���� �� ������
    
public:
    BinarySearchTree();
    void Insert(int v);
    void Traverse();
    void Find(int v);
    void Delete(int v);
};