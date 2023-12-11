#include <iostream>
#include <sstream>

namespace P_D_Tree
{
	/**
	* @brief Structure node, for implematation of BST
	*/
	template <typename T>
	struct Node
	{
		/**
		* @brief value
		*/
		T data;
		/**
		* @brief pointer on parent node
		*/
		Node* parent;
		/**
		* @brief pointer on left node
		*/
		Node* left;
		/**
		* @brief pointer on right node
		*/
		Node* right;

		/**
		 * @brief
		*/
		Node();

		/**
		 * @brief Constructor with param
		 * @param value - value of inserted node
		*/
		Node(const T& value);

		/**
		 * @brief
		 * @param node
		*/
		Node(const Node& node) = delete;

		/**
		 * @brief
		 * @param node
		*/
		Node& operator =(const Node& node) = delete;

		/**
		 * @brief Move constructor
		 * @param node
		*/
		Node(Node&& node) noexcept = default;

		/**
		 * @brief Move operator
		 * @param node
		*/
		Node<T>& operator =(Node&& node) noexcept = default;

		/**
		 * @brief Destrucor.
		*/
		~Node();

		/**
		 * @brief Method for get info is current node root
		 * @return true/false root/not root
		*/
		bool IsRoot() const noexcept;
		/**
		 * @brief leaf check
		 * @return true/false is leaf or not
		*/
		bool IsLeaf() const noexcept;

		/**
		 * @brief Operator to comparison
		 * @param left - left node.
		 * @param right - right node, with that we compare
		 * @return result of comparison
		*/
		friend auto operator <=>(const Node& l, const Node& r)
		{
			if (std::less<T>()(l.data, r.data)) { return -1; }
			else if (std::greater<T>()(l.data, r.data)) { return 1; }

			return 0;
		}

		/**
		 * @brief Operator to comparison
		 * @param left - left node.
		 * @param right - right node, with that we compare
		 * @return result of comparison
		*/
		friend bool operator ==(const Node& l, const Node& r) { return operator<=>(l, r) == 0; }

		/**
		 * @brief Operator not equel
		 * @param left - left node.
		 * @param right - right node, with that we compare
		 * @return result of comparison
		*/
		friend bool operator !=(const Node& l, const Node& r) { return operator<=>(l, r) != 0; }

		/**
		 * @brief Operator for output node
		 * @param stream - input stream
		 * @param node, that we output
		 * @return output stream
		*/
		friend std::ostream& operator<<(std::ostream& stream, const Node& node)
		{
			std::ostringstream buffer{};
			buffer << node.data;
			stream << buffer.str();
			return stream;
		};
	};
}

template <typename T>
P_D_Tree::Node<T>::Node() : data{ 0 }, parent{ nullptr }, left{ nullptr }, right{ nullptr } {}

template <typename T>
P_D_Tree::Node<T>::Node(const T& value) : data{ value }, parent{ nullptr }, left{ nullptr }, right{ nullptr } {}

template <typename T>
P_D_Tree::Node<T>::~Node()
{
	if (!this->IsRoot())
	{
		if (this == this->parent->left) { this->parent->left = nullptr; }
		else { this->parent->right = nullptr; }

		this->parent = nullptr;
	}
	this->left = nullptr;
	this->right = nullptr;
}

template <typename T>
bool P_D_Tree::Node<T>::IsRoot() const noexcept { return this->parent == nullptr; }

template <typename T>
bool P_D_Tree::Node<T>::IsLeaf() const noexcept { return this->left == nullptr && this->right == nullptr; }