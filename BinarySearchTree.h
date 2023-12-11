#pragma once
#include "Node.h"
#include <vector>
#include <sstream>
#include <exception>
#include <iterator>

namespace P_D_Tree
{
	/**
	* @brief BST - Binary search tree
	*/
	template <typename T>
	class BinarySearchTree
	{
	private:
		/**
		 * @brief sort by data
		*/
		std::vector<T> values;
		
		/**
		 * @brief Recurse form values
		 * @param current node, from what we start values formation
		*/
		void InOrder(Node<T>* node);
		/**
		 * @brief recurse call form values
		*/
		void MakeValues();
		/**
		 * @brief Recurse delete tree
		 * @param current - by default root
		*/
		void InOrderRemove(Node<T>* node);
	protected:
		/**
		 * @brief root node
		*/
		Node<T>* root;
		/**
		 * @brief number of nodes in tree
		*/
		size_t size;
		/**
		 * @brief insert new node
		 * @param value - value of new node
		 * @return true/false result of working method(sussess or fail)
		*/
		Node<T>* Insert(Node<T>* current, Node<T>* node, Node<T>* parent);
		/**
		 * @brief find node by value
		 * @param current - node for start search
		 * @param target - value of node target
		 * @return adress of node / nullptr, if not exist
		*/
		Node<T>* Find(Node<T>* node, const T& value) const noexcept;
		/**
		 * @brief find node with min data
		 * @param current - node from what we start search
		 * @return adress of min node
		*/
		Node<T>* FindMin(Node<T>* node);
		/**
		 * @brief find node with max data
		 * @param current - node from what we start search
		 * @return adress of min node
		*/
		Node<T>* FindMax(Node<T>* node);
		/**
		 * @brief Change current node on son.
		 * @param deleted - old node
		 * @param son - new node
		*/
		void Transplant(Node<T>* deleted, Node<T>* son);
		/**
		 * @brief swap nodes
		 * @param other tree
		*/
		void Swap(BinarySearchTree& other) noexcept;

	public:
		/**
		 * @brief default constructor
		*/
		BinarySearchTree();
		/**
		 * @brief param constructor
		 * @param list of values for node in bst
		*/
		BinarySearchTree(std::initializer_list<T> list);
		/**
		 * @brief copy constructor
		 * @param other - tree from what we copy
		*/
		BinarySearchTree(const BinarySearchTree<T>& other);
		/**
		 * @brief move constructor
		 * @param other - tree from what we move
		*/
		BinarySearchTree(BinarySearchTree<T>&& other) noexcept;
		/**
		 * @brief copy operator
		 * @param other - tree from what we copy
		*/
		BinarySearchTree& operator=(const BinarySearchTree<T>& other);
		/**
		 * @brief move operator
		 * @param other - tree from what we move
		*/
		BinarySearchTree& operator=(BinarySearchTree<T>&& other) noexcept;
		/**
		 * @brief Destructor
		*/
		virtual ~BinarySearchTree();
		/**
		 * @brief insert new node
		 * @param value - value of new node
		 * @return true/false result of working method(sussess or fail)
		*/
		bool Add(const T& value);
		/**
		 * @brief remove selected node
		 * @param value - value of node for delete
		 * @return true/false result of working method(sussess or fail)
		*/
		bool Remove(const T& value);
		/**
		 * @brief Exist node with value
		 * @param value - value of node.
		 * @return true/false result of working method(sussess or fail)
		*/
		bool HasValue(const T& value) const noexcept;
		/**
		 * @brief Method for check exist tree or not(exist root or not)
		 * @return true/false result of working method(sussess or fail)
		*/
		bool IsEmpty() const noexcept;
		/**
		 * @brief get number of nodes in tree
		*/
		size_t GetSize() const noexcept;
		/**
		 * @brief Output of tree values
		 * @return string with values
		*/
		std::string InOrderPrint() const noexcept;
	};
}

template<typename T>
void P_D_Tree::BinarySearchTree<T>::InOrder(Node<T>* node)
{
	if (node == nullptr) { return; }

	this->InOrder(node->left);
	this->values.push_back(node->data);
	this->InOrder(node->right);
}

template<typename T>
void P_D_Tree::BinarySearchTree<T>::MakeValues()
{
	this->values.clear();
	this->InOrder(this->root);
}

template <typename T>
void P_D_Tree::BinarySearchTree<T>::InOrderRemove(Node<T>* node)
{
	if (node == nullptr) { return; }

	--this->size;
	this->InOrderRemove(node->left);
	this->InOrderRemove(node->right);

	delete node;
	node = nullptr;
}

template<typename T>
P_D_Tree::Node<T>* P_D_Tree::BinarySearchTree<T>::Insert(Node<T>* current, Node<T>* node, Node<T>* parent)
{
	if (current == nullptr)
	{
		current = node;
		current->parent = parent;
		return current;
	}
	else if (*node < *current) { current->left = this->Insert(current->left, node, current); }
	else { current->right = this->Insert(current->right, node, current); }

	return current;
}


template <typename T>
P_D_Tree::Node<T>* P_D_Tree::BinarySearchTree<T>::Find(Node<T>* node, const T& value) const noexcept
{
	if (node == nullptr) { return nullptr; }
	else
	{
		if (std::less<T>()(value, node->data)) { return this->Find(node->left, value); }
		else if (std::greater<T>()(value, node->data)) { return this->Find(node->right, value); }
		else { return node; }
	}
}

template <typename T>
P_D_Tree::Node<T>* P_D_Tree::BinarySearchTree<T>::FindMin(Node<T>* node)
{
	while (nullptr != node->left) { node = node->left; }
	return node;
}

template <typename T>
P_D_Tree::Node<T>* P_D_Tree::BinarySearchTree<T>::FindMax(Node<T>* node)
{
	while (nullptr != node->right) { node = node->right; }
	return node;
}

template <typename T>
void P_D_Tree::BinarySearchTree<T>::Transplant(Node<T>* deleted, Node<T>* son)
{
	if (deleted == son) { return; }

	int TreeData = son->data;
	Node<T>* TreeParent = son->parent;
	Node<T>* TreeRight = son->right;
	delete son;

	if (TreeParent == deleted) { TreeParent->right = TreeRight; }
	else if (TreeRight != nullptr) { TreeRight->parent = TreeParent; }
	else { TreeParent->left = TreeRight; }

	deleted->data = TreeData;
}

template <typename T>
void P_D_Tree::BinarySearchTree<T>::Swap(BinarySearchTree<T>& other) noexcept
{
	std::swap(this->root, other.root);
	std::swap(this->left, other.left);
	std::swap(this->right, other.right);
}

template <typename T>
P_D_Tree::BinarySearchTree<T>::BinarySearchTree() : root{ nullptr }, size{ 0 } {}

template <typename T>
P_D_Tree::BinarySearchTree<T>::BinarySearchTree(std::initializer_list<T> list) : BinarySearchTree()
{
	for (auto& it : list) { this->Add(it); }
}

template <typename T>
P_D_Tree::BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other) : BinarySearchTree()
{
	for (auto& it : other) { this->Add(it); }
}

template <typename T>
P_D_Tree::BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& other) noexcept : BinarySearchTree()
{
	*this = other;
}

template <typename T>
P_D_Tree::BinarySearchTree<T>& P_D_Tree::BinarySearchTree<T>::operator=(const BinarySearchTree<T>& other)
{
	if (this != other)
	{
		BinarySearchTree<T> temp(other);
		this->Swap(temp);
	}

	return *this;
}

template <typename T>
P_D_Tree::BinarySearchTree<T>& P_D_Tree::BinarySearchTree<T>::operator=(BinarySearchTree<T>&& other) noexcept
{
	if (this != other) { this->Swap(other); }

	return *this;
}

template <typename T>
P_D_Tree::BinarySearchTree<T>::~BinarySearchTree()
{
	this->InOrderRemove(this->root);
	this->root = nullptr;
}

template <typename T>
bool P_D_Tree::BinarySearchTree<T>::Add(const T& value)
{
	auto newNode = new Node<T>(value);
	if (this->root == nullptr) { this->root = newNode; }
	else { this->root = this->Insert(this->root, newNode, this->root->parent); }

	++this->size;
	this->MakeValues();
	return true;
}

template <typename T>
bool P_D_Tree::BinarySearchTree<T>::Remove(const T& value)
{
	auto newNode = new Node<T>(value);
	if (this->IsEmpty()) { throw std::logic_error("Empty tree"); }

	Node<T>* current = this->root;
	while (current != nullptr && *newNode != *current)
	{
		if (*newNode < *current) { current = current->left; }
		else if (*newNode > *current) { current = current->right; }
	}

	if (current == nullptr) { throw std::logic_error("Node with this value doesnt exist"); }
	else if (current->IsLeaf() == false)
	{
		if (current->right != nullptr && current->left != nullptr)
		{
			Node<T>* MinRight = this->FindMin(current->right);
			Transplant(current, MinRight);
		}
		else
		{
			if (current->right != nullptr) { current = current->right; }
			else { current = current->left; }

			T DataTree = current->data;
			Node<T>* ParentNode = current->parent;
			Node<T>* RightNode = current->right;
			Node<T>* LeftNode = current->left;
			delete current;

			ParentNode->data = DataTree;
			ParentNode->right = RightNode;
			ParentNode->left = LeftNode;
		}
	}
	else
	{
		delete current;
		current = nullptr;
	}

	--this->size;
	this->MakeValues();
	return true;
}

template <typename T>
bool P_D_Tree::BinarySearchTree<T>::HasValue(const T& value) const noexcept
{
	return this->Find(this->root, value) != nullptr;
}

template <typename T>
bool P_D_Tree::BinarySearchTree<T>::IsEmpty() const noexcept
{
	return this->root == nullptr;
}

template <typename T>
size_t P_D_Tree::BinarySearchTree<T>::GetSize() const noexcept
{
	return this->size;
}

template <typename T>
std::string P_D_Tree::BinarySearchTree<T>::InOrderPrint() const noexcept
{
	std::ostringstream buffer{};
	buffer << "{ ";
	for (auto it = this->values.cbegin(); it != this->values.cend(); ++it)
	{
		buffer << (*it) << " ";
	}
	buffer << "}";

	return buffer.str();
}