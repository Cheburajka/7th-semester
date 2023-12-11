#include "pch.h"
#include "CppUnitTest.h"
#include "../bst/Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(NodeTest)
{
public:
	TEST_METHOD(TestDefaultConstructor)
	{
		P_D_Tree::Node<int> defaultNode;
		Assert::IsTrue(defaultNode.IsRoot());
		Assert::IsTrue(defaultNode.IsLeaf());
	}

	TEST_METHOD(TestParameterizedConstructor)
	{
		int value = 42;
		P_D_Tree::Node<int> paramNode(value);
		Assert::IsTrue(paramNode.IsRoot());
		Assert::IsTrue(paramNode.IsLeaf());
		Assert::AreEqual(paramNode.data, value);
	}

	TEST_METHOD(TestMoveConstructor)
	{
		int value = 42;
		P_D_Tree::Node<int> paramNode(value);
		P_D_Tree::Node<int> movedNode(std::move(paramNode));
		Assert::IsTrue(movedNode.IsRoot());
		Assert::IsTrue(movedNode.IsLeaf());
		Assert::AreEqual(movedNode.data, value);
	}

	TEST_METHOD(TestMoveAssignmentOperator)
	{
		int value = 42;
		P_D_Tree::Node<int> paramNode(value);
		P_D_Tree::Node<int> anotherNode;
		anotherNode = std::move(paramNode);
		Assert::IsTrue(anotherNode.IsRoot());
		Assert::IsTrue(anotherNode.IsLeaf());
		Assert::AreEqual(anotherNode.data, value);
	}

	TEST_METHOD(TestDestructor)
	{
		P_D_Tree::Node<int>* destructNode = new P_D_Tree::Node<int>();

		delete destructNode;
		destructNode = nullptr;
	}

	TEST_METHOD(TestIsRootAndIsLeaf)
	{
		P_D_Tree::Node<int> rootNode;
		P_D_Tree::Node<int> childNode;
		P_D_Tree::Node<int> leafNode;

		Assert::IsTrue(rootNode.IsRoot());
		Assert::IsTrue(rootNode.IsLeaf());

		rootNode.left = &childNode;
		rootNode.right = &leafNode;
		childNode.parent = &rootNode;
		leafNode.parent = &rootNode;

		Assert::IsTrue(rootNode.IsRoot());
		Assert::IsFalse(rootNode.IsLeaf());
		Assert::IsTrue(childNode.IsLeaf());
		Assert::IsTrue(leafNode.IsLeaf());
	}

	TEST_METHOD(TestComparisonOperators)
	{
		P_D_Tree::Node<int> equalNode1(42);
		P_D_Tree::Node<int> equalNode2(42);
		P_D_Tree::Node<int> lessNode(21);
		P_D_Tree::Node<int> greaterNode(63);

		Assert::IsTrue(equalNode1 == equalNode2);
		Assert::IsTrue(equalNode1 != lessNode);
		Assert::IsTrue(lessNode < greaterNode);
		Assert::IsTrue(greaterNode > lessNode);
	}
};
