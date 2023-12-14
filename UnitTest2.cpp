#include "pch.h"
#include "CppUnitTest.h"
#include "../4курс_BinarySearchTree/BinarySearchTree.h"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace P_D_Tree
{
	TEST_CLASS(BinarySearchTreeTests)
	{
	public:

		TEST_METHOD(Size_Int_Success)
		{
			P_D_Tree::BinarySearchTree<int> bst{ 5, 3, 7 };

			Assert::AreEqual(static_cast<size_t>(3), bst.GetSize());
		}

		TEST_METHOD(Size_String_Success)
		{
			P_D_Tree::BinarySearchTree<std::string> bst{ "5", "3", "7" };

			Assert::AreEqual(static_cast<size_t>(3), bst.GetSize());
		}

		TEST_METHOD(Add_Int_Success)
		{
			P_D_Tree::BinarySearchTree<int> bst;
			bst.Add(5);
			bst.Add(3);
			bst.Add(7);

			Assert::AreEqual(static_cast<size_t>(3), bst.GetSize());
		}

		TEST_METHOD(Add_String_Success)
		{
			P_D_Tree::BinarySearchTree<std::string> bst;
			bst.Add("5");
			bst.Add("3");
			bst.Add("7");

			Assert::AreEqual(static_cast<size_t>(3), bst.GetSize());
		}

		TEST_METHOD(Remove_Int_Success)
		{
			P_D_Tree::BinarySearchTree<int> bst{ 5, 3, 7 };
			Assert::AreEqual(static_cast<size_t>(3), bst.GetSize());

			Assert::IsTrue(bst.Remove(3));
			Assert::AreEqual(static_cast<size_t>(2), bst.GetSize());
			Assert::IsFalse(bst.HasValue(3));
		}

		TEST_METHOD(Remove_Int_ExpectException)
		{	
			P_D_Tree::BinarySearchTree<int> bst{ 5, 3, 7 };
			auto func = [&] { bst.Remove(4); };
			Assert::ExpectException<std::logic_error>(func);
		}

		TEST_METHOD(Remove_String_Success)
		{
			P_D_Tree::BinarySearchTree<std::string> bst{ "5", "3", "7" };
			Assert::AreEqual(static_cast<size_t>(3), bst.GetSize());
			Assert::IsTrue(bst.Remove("3"));

			Assert::AreEqual(static_cast<size_t>(2), bst.GetSize());
			Assert::IsFalse(bst.HasValue("3"));
		}

		TEST_METHOD(Remove_String_ExpectException)
		{
			P_D_Tree::BinarySearchTree<std::string> bst{ "5", "3", "7" };
			auto func = [&] { bst.Remove("4"); };
			Assert::ExpectException<std::logic_error>(func);
		}

		TEST_METHOD(OrderPrint_Int_Success)
		{
			P_D_Tree::BinarySearchTree<int> bst{ 5, 3, 7, 1, 4 };
			Assert::AreEqual(std::string("{ 1 3 4 5 7 }"), bst.InOrderPrint());
		}

		TEST_METHOD(OrderPrint_String_Success)
		{
			P_D_Tree::BinarySearchTree<std::string> bst{ "5", "3", "7", "1", "4" };
			Assert::AreEqual(std::string("{ 1 3 4 5 7 }"), bst.InOrderPrint());
		}

		TEST_METHOD(IsEmpty_Int_Success)
		{
			P_D_Tree::BinarySearchTree<int> emptyBst;

			Assert::IsTrue(emptyBst.IsEmpty());
		}

		TEST_METHOD(IsEmpty_String_Success)
		{
			P_D_Tree::BinarySearchTree<std::string> emptyBst;

			Assert::IsTrue(emptyBst.IsEmpty());
		}

		TEST_METHOD(IsNotEmpty_Int_Success)
		{
			P_D_Tree::BinarySearchTree<int> nonEmptyBst{ 1, 2, 3 };

			Assert::IsFalse(nonEmptyBst.IsEmpty());
		}

		TEST_METHOD(IsNotEmpty_String_Success)
		{
			P_D_Tree::BinarySearchTree<std::string> nonEmptyBst{ "1", "2", "3" };

			Assert::IsFalse(nonEmptyBst.IsEmpty());
		}

		TEST_METHOD(DefaultConstructor_Int_Success)
		{
			P_D_Tree::BinarySearchTree<int> bst;
			Assert::IsTrue(bst.IsEmpty());
			Assert::AreEqual(static_cast<size_t>(0), bst.GetSize());
		}

		TEST_METHOD(DefaultConstructor_String_Success)
		{
			P_D_Tree::BinarySearchTree<std::string> bst;
			Assert::IsTrue(bst.IsEmpty());
			Assert::AreEqual(static_cast<size_t>(0), bst.GetSize());
		}

		TEST_METHOD(InitializerListConstructor_Int_Success)
		{
			P_D_Tree::BinarySearchTree<int> bst{ 5, 3, 7, 1, 4 };
			Assert::AreEqual(std::string("{ 1 3 4 5 7 }"), bst.InOrderPrint());
		}

		TEST_METHOD(InitializerListConstructor_String_Success)
		{
			P_D_Tree::BinarySearchTree<std::string> bst{ "5", "3", "7", "1", "4" };
			Assert::AreEqual(std::string("{ 1 3 4 5 7 }"), bst.InOrderPrint());
		}

		TEST_METHOD(HasValue_Int_Success)
		{
			P_D_Tree::BinarySearchTree<int> bst{ 5, 3, 7, 1, 4 };
			Assert::IsTrue(bst.HasValue(3));
			Assert::IsFalse(bst.HasValue(10));
		}

		TEST_METHOD(HasValue_String_Success)
		{
			P_D_Tree::BinarySearchTree<std::string> bst{ "5", "3", "7", "1", "4" };
			Assert::IsTrue(bst.HasValue("3"));
			Assert::IsFalse(bst.HasValue("10"));
		}
	};
}