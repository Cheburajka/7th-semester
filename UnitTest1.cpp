#include "pch.h"
#include "CppUnitTest.h"
#include "../4курс_BinarySearchTree/Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(NodeTest)
{
public:
	TEST_METHOD(DefaultConstructor_Int_Success)
	{
		P_D_Tree::Node<int> defaultNode;

		Assert::IsTrue(defaultNode.IsRoot());
		Assert::IsTrue(defaultNode.IsLeaf());
	}

	TEST_METHOD(DefaultConstructor_String_Success)
	{
		P_D_Tree::Node<std::string> defaultNode;

		Assert::IsTrue(defaultNode.IsRoot());
		Assert::IsTrue(defaultNode.IsLeaf());
	}

	TEST_METHOD(ParamConstructor_Int_Success)
	{
		int value = 42;
		P_D_Tree::Node<int> paramNode(value);

		Assert::IsTrue(paramNode.IsRoot());
		Assert::IsTrue(paramNode.IsLeaf());
		Assert::AreEqual(paramNode.data, value);
	}

	TEST_METHOD(ParamConstructor_String_Success)
	{
		std::string value = "42";
		P_D_Tree::Node<std::string> paramNode(value);

		Assert::IsTrue(paramNode.IsRoot());
		Assert::IsTrue(paramNode.IsLeaf());
		Assert::AreEqual(paramNode.data, value);
	}

	TEST_METHOD(MoveConstructor_Int_Success)
	{
		int value = 42;
		P_D_Tree::Node<int> paramNode(value);
		P_D_Tree::Node<int> movedNode(std::move(paramNode));

		Assert::IsTrue(movedNode.IsRoot());
		Assert::IsTrue(movedNode.IsLeaf());
		Assert::AreEqual(movedNode.data, value);
	}

	TEST_METHOD(MoveConstructor_String_Success)
	{
		std::string value = "42";
		P_D_Tree::Node<std::string> paramNode(value);
		P_D_Tree::Node<std::string> movedNode(std::move(paramNode));

		Assert::IsTrue(movedNode.IsRoot());
		Assert::IsTrue(movedNode.IsLeaf());
		Assert::AreEqual(movedNode.data, value);
	}

	TEST_METHOD(MoveAssignmentOperator_Int_Success)
	{
		int value = 42;
		P_D_Tree::Node<int> paramNode(value);
		P_D_Tree::Node<int> anotherNode;
		anotherNode = std::move(paramNode);
		Assert::IsTrue(anotherNode.IsRoot());
		Assert::IsTrue(anotherNode.IsLeaf());
		Assert::AreEqual(anotherNode.data, value);
	}

	TEST_METHOD(MoveAssignmentOperator_String_Success)
	{
		std::string value = "42";
		P_D_Tree::Node<std::string> paramNode(value);
		P_D_Tree::Node<std::string> anotherNode;
		anotherNode = std::move(paramNode);
		Assert::IsTrue(anotherNode.IsRoot());
		Assert::IsTrue(anotherNode.IsLeaf());
		Assert::AreEqual(anotherNode.data, value);
	}

	TEST_METHOD(IsRoot_Int_Success)
	{
		P_D_Tree::Node<int> rootNode;

		Assert::IsTrue(rootNode.IsRoot());
	}

	TEST_METHOD(IsRoot_String_Success)
	{
		P_D_Tree::Node<std::string> rootNode;

		Assert::IsTrue(rootNode.IsRoot());
	}

	TEST_METHOD(IsLeaf_Int_Success)
	{
		P_D_Tree::Node<int> rootNode;

		Assert::IsTrue(rootNode.IsLeaf());
	}

	TEST_METHOD(IsLeaf_String_Success)
	{
		P_D_Tree::Node<std::string> rootNode;

		Assert::IsTrue(rootNode.IsLeaf());
	}

	TEST_METHOD(ComparisonOperators_Int_Success)
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

	TEST_METHOD(ComparisonOperators_String_Success)
	{
		P_D_Tree::Node<std::string> equalNode1("42");
		P_D_Tree::Node<std::string> equalNode2("42");
		P_D_Tree::Node<std::string> lessNode("21");
		P_D_Tree::Node<std::string> greaterNode("63");

		Assert::IsTrue(equalNode1 == equalNode2);
		Assert::IsTrue(equalNode1 != lessNode);
		Assert::IsTrue(lessNode < greaterNode);
		Assert::IsTrue(greaterNode > lessNode);
	}
};