#include "pch.h"
#include "CppUnitTest.h"
#include "../Cipher.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            string test = "Hello World!";
            Tree tree;
            List2 list;
            List<bool> list2;
            list = tree.getSequence(test);
            tree.create_tree(tree.root, list, list2);
            List<List<bool>> code;
            code = tree.create_code(test);
            Assert::AreEqual(tree.get_code_size(code), 37);
            Assert::AreEqual(tree.decode(code), test);
        }

        TEST_METHOD(TestMethod2)
        {
            string test = "it is test string";
            Tree tree;
            List2 list;
            List<bool> list2;
            list = tree.getSequence(test);
            tree.create_tree(tree.root, list, list2);
            List<List<bool>> code;
            code = tree.create_code(test);
            Assert::AreEqual(tree.get_code_size(code), 49);
            Assert::AreEqual(tree.decode(code), test);
        }
        TEST_METHOD(TestMethod3)
        {
            string test = "I never asked for this";
            Tree tree;
            List2 list;
            List<bool> list2;
            list = tree.getSequence(test);
            tree.create_tree(tree.root, list, list2);
            List<List<bool>> code;
            code = tree.create_code(test);;
            Assert::AreEqual(tree.decode(code), test);
        }
        TEST_METHOD(TestMethod4)
        {
            string test = "Patience is fine, but it can curdle into apathy";
            Tree tree;
            List2 list;
            List<bool> list2;
            list = tree.getSequence(test);
            tree.create_tree(tree.root, list, list2);
            List<List<bool>> code;
            code = tree.create_code(test);
            Assert::AreEqual(tree.decode(code), test);
        }
        TEST_METHOD(TestMethod5)
        {
            string test = "As a student who played dota, I don't respect lolers";
            Tree tree;
            List2 list;
            List<bool> list2;
            list = tree.getSequence(test);
            tree.create_tree(tree.root, list, list2);
            List<List<bool>> code;
            code = tree.create_code(test);
            Assert::AreEqual(tree.decode(code), test);
        }
    };
}