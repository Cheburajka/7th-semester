#include <iostream>

class BinarySearchTree
{
private:
    struct Node // структура узла
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
    Node* root; // узел - корень дерева

    Node* Insert(int v, Node* x); // вставка узла в дерево
    void Traverse(Node* x); // обход
    Node* Find(int v, Node* x); // поиск узла в дереве
    Node* Delete(int v, Node* x); // удаление узла из дерева
    
public:
    BinarySearchTree();
    void Insert(int v);
    void Traverse();
    void Find(int v);
    void Delete(int v);
};