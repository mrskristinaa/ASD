#include <gtest/gtest.h>
#include "list.h" 

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

//TEST(ListTest, can_read) {
//    List<int>list;
//    for (int i = 0; i < 10; i++) {
//        list.push_back(i + 1);
//    }
//    int expected_val = 1;
//    for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
//        *it = expected_val;
//        expected_val++;
//    }
//    expected_val = 1;
//    for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
//        EXPECT_EQ(*it, expected_val);
//        expected_val++;
//    }
//}
//TEST(ListTest, can_write) {
//    List<int>list;
//    int expected_val = 1;
//    for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
//        EXPECT_EQ(*it, expected_val);
//        expected_val++;
//    }
//}
//TEST(ListTest, is_empty) {
//    List<int>list;
//    for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
//        *it = 0;
//    }
//}

TEST(IteratorTest, ReadWithPostIncrement) {
    List<int> list;
    for (int i = 0; i < 5; i++) {
        list.push_back(i * 3 + 1); 
    }
    std::vector<int> result;
    for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
        result.push_back(*it);
    }
    std::vector<int> expected = { 1, 4, 7, 10, 13 };
    EXPECT_EQ(result, expected);
}

TEST(IteratorTest, WriteWithPreIncrement) {
    List<int> list;
    for (int i = 0; i < 5; i++) {
        list.push_back(0);
    }
    int new_value = 5;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        *it = new_value;
        new_value *= 2;
    }
    std::vector<int> result;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        result.push_back(*it);
    }
    std::vector<int> expected = { 5, 10, 20, 40, 80 };
    EXPECT_EQ(result, expected);
}

TEST(IteratorTest, EmptyListWithBothIncrementTypes) {
    List<int> list;
    List<int>::Iterator begin = list.begin();
    List<int>::Iterator end = list.end();
    EXPECT_TRUE(begin == end);
    EXPECT_FALSE(begin != end);
    int iteration_count_post = 0;
    for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
        iteration_count_post++;
    }
    EXPECT_EQ(iteration_count_post, 0);
    int iteration_count_pre = 0;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        iteration_count_pre++;
    }
    EXPECT_EQ(iteration_count_pre, 0);
}

#include <gtest/gtest.h>
#include "stack.h"

TEST(StackListWithDeleteTest, ConstructorDestructor) {
    StackList<int>* stack = new StackList<int>();
    stack->push(1);
    stack->push(2);
    stack->push(3);
    EXPECT_EQ(stack->size(), 3);
    delete stack;  
}

TEST(StackListWithDeleteTest, CopyConstructor) {
    StackList<int> original;
    original.push(1);
    original.push(2);

    StackList<int> copy(original); 
    EXPECT_EQ(copy.size(), 2);
    EXPECT_EQ(copy.top(), 2);
}

TEST(StackListWithDeleteTest, AssignmentOperator) {
    StackList<int> stack1;
    stack1.push(10);
    stack1.push(20);

    StackList<int> stack2;
    stack2 = stack1; 

    EXPECT_EQ(stack2.size(), 2);
    EXPECT_EQ(stack2.top(), 20);
}

TEST(StackListWithDeleteTest, MemoryManagement) {
    {
        StackList<int> stack;
        for (int i = 0; i < 100; i++) {
            stack.push(i);
        }

    }
}

