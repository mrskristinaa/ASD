#include <gtest/gtest.h>
#include "List.h" 

TEST(ListTest, DefaultConstructor) {
    List<int> list;
    EXPECT_TRUE(list.is_empty());
}

TEST(ListTest, PushFront) {
    List<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    EXPECT_FALSE(list.is_empty());
}

TEST(ListTest, PushBack) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_FALSE(list.is_empty());
}

TEST(ListTest, PopFront) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_front();

}

TEST(ListTest, PopBack) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
}

TEST(ListTest, PopFrontSingleElement) {
    List<int> list;
    list.push_back(1);
    list.pop_front();
    EXPECT_TRUE(list.is_empty());
}

TEST(ListTest, PopBackSingleElement) {
    List<int> list;
    list.push_back(1);
    list.pop_back();
    EXPECT_TRUE(list.is_empty());
}

TEST(ListTest, InsertAtPosition) {
    List<int> list;
    list.push_back(1);
    list.push_back(3);
    list.insert(1, 2);
}

TEST(ListTest, InsertAtBeginning) {
    List<int> list;
    list.push_back(2);
    list.push_back(3);
    list.insert(0, 1);
}

TEST(ListTest, InsertAtEnd) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.insert(2, 3);
}

TEST(ListTest, InsertAtInvalidPosition) {
    List<int> list;
    list.push_back(1);
    EXPECT_THROW(list.insert(5, 2), const char*);
}

TEST(ListTest, EraseByPosition) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.erase(1);
}

TEST(ListTest, EraseFirstElement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.erase(0);
}

TEST(ListTest, EraseLastElement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.erase(2);
}

TEST(ListTest, EraseInvalidPosition) {
    List<int> list;
    list.push_back(1);
    EXPECT_THROW(list.erase(5), const char*);
}

TEST(ListTest, EraseEmptyList) {
    List<int> list;
    EXPECT_THROW(list.erase(0), const char*);
}

TEST(ListTest, FindExistingElement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    Node<int>* found = list.find(2);
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->value, 2);
}

TEST(ListTest, FindNonExistingElement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    Node<int>* found = list.find(5);
    EXPECT_EQ(found, nullptr);
}

TEST(ListTest, FindInEmptyList) {
    List<int> list;
    Node<int>* found = list.find(1);
    EXPECT_EQ(found, nullptr);
}

TEST(ListTest, ClearList) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.clear();
    EXPECT_TRUE(list.is_empty());
}

TEST(ListTest, ClearEmptyList) {
    List<int> list;
    list.clear();
    EXPECT_TRUE(list.is_empty());
}

TEST(ListTest, CopyConstructor) {
    List<int> original;
    original.push_back(1);
    original.push_back(2);
    original.push_back(3);
    List<int> copy(original);
    original.pop_front();
}

TEST(ListTest, CopyConstructorEmptyList) {
    List<int> original;
    List<int> copy(original);
    EXPECT_TRUE(copy.is_empty());
}

TEST(ListTest, Destructor) {
    {
        List<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
    }
}

TEST(ListTest, MultipleDataTypes) {
    List<std::string> stringList;
    stringList.push_back("hello");
    stringList.push_back("world");
    List<double> doubleList;
    doubleList.push_back(3.14);
    doubleList.push_back(2.71);
    EXPECT_FALSE(stringList.is_empty());
    EXPECT_FALSE(doubleList.is_empty());
}

TEST(ListTest, InsertAfterNode) {
    List<int> list;
    list.push_back(1);
    list.push_back(3);
    Node<int>* first = list.find(1);
    ASSERT_NE(first, nullptr);
    list.insert(first, 2);
}

TEST(ListTest, EraseByNode) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    Node<int>* nodeToDelete = list.find(2);
    ASSERT_NE(nodeToDelete, nullptr);
    list.erase(nodeToDelete);
}

TEST(ListTest, ComplexOperationsSequence) {
    List<int> list;
    list.push_front(2);
    list.push_back(3);
    list.push_front(1);
    list.insert(1, 4);
    list.pop_back();
    list.pop_front();
    list.erase(0);
    EXPECT_FALSE(list.is_empty());
}