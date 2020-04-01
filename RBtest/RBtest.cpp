#include "pch.h"
#include "CppUnitTest.h"
#include"../AISDLAB1/map.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RedBlackTreeTest
{
	TEST_CLASS(RedBlackTreeTest)
	{
	public:

		TEST_METHOD(TestMethodInsertAndFind)
		{
			Map<int, int>* tree = new Map<int, int>();
			tree->insert(10, -1);
			tree->insert(5, -2);
			tree->insert(3, -3);
			tree->insert(11, -4);
			Assert::AreEqual(tree->find(5), -2);

		}
		TEST_METHOD(TestMethodFindExeption)
		{
			try {
				Map<int, int>* tree = new Map<int, int>();
				tree->insert(10, -1);
				tree->insert(5, -2);
				tree->insert(3, -3);
				tree->insert(11, -4);
				tree->find(29);
			}
			catch (std::out_of_range exc) {
				Assert::AreEqual("Key is missing", exc.what());
			}
		}
		TEST_METHOD(TestMethodClear)
		{
			try {
				Map<int, int>* tree = new Map<int, int>();
				tree->insert(10, -1);
				tree->insert(5, -2);
				tree->insert(3, -3);
				tree->insert(11, -4);
				tree->clear();
				tree->printTree();
			}
			catch (std::out_of_range exc) {
				Assert::AreEqual("Tree is empty!", exc.what());
			}
		}
		TEST_METHOD(TestMethodGetValues)
		{
			Map<int, int>* tree = new Map<int, int>();
			tree->insert(10, -1);
			tree->insert(5, -2);
			tree->insert(3, -3);
			tree->insert(11, -4);
			List<int>* list = tree->get_values();
			int sum = 0;
			for (int i = 0; i < list->get_size(); i++)
				sum += list->at(i);
			Assert::AreEqual(-10, sum);
		}
		TEST_METHOD(TestMethodGetKeys)
		{
			Map<int, int>* tree = new Map<int, int>();
			tree->insert(10, -1);
			tree->insert(5, -2);
			tree->insert(3, -3);
			tree->insert(11, -4);
			List<int>* list = tree->get_keys();
			int sum = 0;
			for (int i = 0; i < list->get_size(); i++)
				sum += list->at(i);
			Assert::AreEqual(29, sum);
		}
		TEST_METHOD(TestMethodDelete)
		{
			try {
				Map<int, int>* tree = new Map<int, int>();
				tree->insert(10, -1);
				tree->insert(5, -2);
				tree->insert(3, -3);
				tree->insert(11, -4);
				tree->Delete(10);
				tree->find(10);
			}
			catch (std::out_of_range exc) {
				Assert::AreEqual("Key is missing", exc.what());
			}
		}
	};
}
