#include "pch.h"
#include "CppUnitTest.h"
#include "../bst/BinarySearchTree.h"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace P_D_Tree
{
	TEST_CLASS(BinarySearchTreeTests)
	{
	public:

		TEST_METHOD(TestAddAndSize)
		{
			P_D_Tree::BinarySearchTree<int> bst;
			Assert::IsTrue(bst.IsEmpty());

			bst.Add(5);
			Assert::AreEqual(static_cast<size_t>(1), bst.GetSize());
			Assert::IsFalse(bst.IsEmpty());

			bst.Add(3);
			bst.Add(7);
			Assert::AreEqual(static_cast<size_t>(3), bst.GetSize());
		}

		TEST_METHOD(TestRemove)
		{
			P_D_Tree::BinarySearchTree<int> bst{ 5, 3, 7 };
			Assert::AreEqual(static_cast<size_t>(3), bst.GetSize());

			Assert::IsTrue(bst.Remove(3));
			Assert::AreEqual(static_cast<size_t>(2), bst.GetSize());
			Assert::IsFalse(bst.HasValue(3));

			//Assert::IsFalse(bst.Remove(4));
		}

		TEST_METHOD(TestInOrderPrint)
		{
			P_D_Tree::BinarySearchTree<int> bst{ 5, 3, 7, 1, 4 };
			Assert::AreEqual(std::string("{ 1 3 4 5 7 }"), bst.InOrderPrint());
		}

		TEST_METHOD(TestIsEmpty)
		{
			P_D_Tree::BinarySearchTree<int> emptyBst;
			P_D_Tree::BinarySearchTree<int> nonEmptyBst{ 1, 2, 3 };

			Assert::IsTrue(emptyBst.IsEmpty());
			Assert::IsFalse(nonEmptyBst.IsEmpty());
		}

		TEST_METHOD(TestClear)
		{
			P_D_Tree::BinarySearchTree<int> bst{ 1, 2 };
			Assert::IsFalse(bst.IsEmpty());

			bst.Remove(1);
			bst.Remove(2);
			Assert::IsTrue(bst.IsEmpty());
			Assert::AreEqual(static_cast<size_t>(0), bst.GetSize());
		}
		
		TEST_METHOD(TestDefaultConstructor)
		{
			P_D_Tree::BinarySearchTree<int> bst;
			Assert::IsTrue(bst.IsEmpty());
			Assert::AreEqual(static_cast<size_t>(0), bst.GetSize());
		}
		
		TEST_METHOD(TestInitializerListConstructor)
		{
			P_D_Tree::BinarySearchTree<int> bst{ 5, 3, 7, 1, 4 };
			Assert::AreEqual(std::string("{ 1 3 4 5 7 }"), bst.InOrderPrint());
		}
		
		TEST_METHOD(TestDestructor)
		{
			{
				P_D_Tree::BinarySearchTree<int> bst{ 5, 3, 7, 1, 4 };
			}
		}
	};
}