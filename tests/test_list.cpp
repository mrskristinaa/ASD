#include <gtest/gtest.h>
#include "../lib_list/list.h"
TEST(ListTest, DefaultConstructorCreatesEmptyList) {
    List<int> list;
    EXPECT_TRUE(list.is_empty());
}
TEST(ListTest, PushFrontAddsElement) {
    List<int> list;
    list.push_front(42);
    EXPECT_FALSE(list.is_empty());
}
TEST(ListTest, PushBackAddsElement) {
    List<int> list;
    list.push_back(42);
    EXPECT_FALSE(list.is_empty());
}
TEST(ListTest, PushFrontMultipleElements) {
    List<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    Node<int>* first = list.find(1);
    Node<int>* second = list.find(2);
    Node<int>* third = list.find(3);
    EXPECT_NE(first, nullptr);
    EXPECT_NE(second, nullptr);
    EXPECT_NE(third, nullptr);
}

TEST(ListTest, PushBackMultipleElements) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    Node<int>* first = list.find(1);
    Node<int>* last = list.find(3);
    EXPECT_NE(first, nullptr);
    EXPECT_NE(last, nullptr);
}
TEST(ListTest, PopFrontRemovesFirstElement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_front();
    EXPECT_EQ(list.find(1), nullptr);
    EXPECT_NE(list.find(2), nullptr);
}
TEST(ListTest, PopBackRemovesLastElement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_back();
    EXPECT_NE(list.find(1), nullptr);
    EXPECT_EQ(list.find(2), nullptr);
}
TEST(ListTest, PopFrontOnSingleElement) {
    List<int> list;
    list.push_back(1);
    list.pop_front();
    EXPECT_TRUE(list.is_empty());
}
TEST(ListTest, PopBackOnSingleElement) {
    List<int> list;
    list.push_back(1);
    list.pop_back();
    EXPECT_TRUE(list.is_empty());
}
TEST(ListTest, InsertAtBeginning) {
    List<int> list;
    list.push_back(2);
    list.push_back(3);
    list.insert(0, 1);
    EXPECT_NE(list.find(1), nullptr);
    EXPECT_NE(list.find(2), nullptr);
    EXPECT_NE(list.find(3), nullptr);
}
TEST(ListTest, InsertAtEnd) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.insert(2, 3);
    EXPECT_NE(list.find(3), nullptr);
}
TEST(ListTest, InsertInMiddle) {
    List<int> list;
    list.push_back(1);
    list.push_back(3);
    list.insert(1, 2);
    EXPECT_NE(list.find(2), nullptr);
}
TEST(ListTest, EraseFirstElement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.erase(0);
    EXPECT_EQ(list.find(1), nullptr);
    EXPECT_NE(list.find(2), nullptr);
    EXPECT_NE(list.find(3), nullptr);
}
TEST(ListTest, EraseMiddleElement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.erase(1);
    EXPECT_NE(list.find(1), nullptr);
    EXPECT_EQ(list.find(2), nullptr);
    EXPECT_NE(list.find(3), nullptr);
}
TEST(ListTest, EraseLastElement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.erase(2);
    EXPECT_NE(list.find(1), nullptr);
    EXPECT_NE(list.find(2), nullptr);
    EXPECT_EQ(list.find(3), nullptr);
}
TEST(ListTest, PopFrontOnEmptyListThrows) {
    List<int> list;
    EXPECT_THROW(list.pop_front(), std::logic_error);
}
TEST(ListTest, PopBackOnEmptyListThrows) {
    List<int> list;
    EXPECT_THROW(list.pop_back(), std::logic_error);
}
TEST(ListTest, InsertAtInvalidPositionThrows) {
    List<int> list;
    list.push_back(1);
    EXPECT_THROW(list.insert(5, 2), std::logic_error);
    EXPECT_THROW(list.insert(-1, 2), std::logic_error);
}
TEST(ListTest, EraseAtInvalidPositionThrows) {
    List<int> list;
    list.push_back(1);
    EXPECT_THROW(list.erase(5), std::logic_error);
    EXPECT_THROW(list.erase(-1), std::logic_error);
}
TEST(ListTest, EraseOnEmptyListThrows) {
    List<int> list;
    EXPECT_THROW(list.erase(0), std::logic_error);
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
    Node<int>* found = list.find(3);
    EXPECT_EQ(found, nullptr);
}
TEST(ListTest, FindInEmptyList) {
    List<int> list;
    Node<int>* found = list.find(1);
    EXPECT_EQ(found, nullptr);
}
TEST(ListTest, ClearRemovesAllElements) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.clear();
    EXPECT_TRUE(list.is_empty());
    EXPECT_EQ(list.find(1), nullptr);
    EXPECT_EQ(list.find(2), nullptr);
    EXPECT_EQ(list.find(3), nullptr);
}
TEST(ListTest, ClearEmptyList) {
    List<int> list;
    list.clear();
    EXPECT_TRUE(list.is_empty());
}
TEST(ListTest, CopyConstructorCreatesIndependentCopy) {
    List<int> original;
    original.push_back(1);
    original.push_back(2);
    original.push_back(3);
    List<int> copy(original);
    EXPECT_NE(copy.find(1), nullptr);
    EXPECT_NE(copy.find(2), nullptr);
    EXPECT_NE(copy.find(3), nullptr);
    original.pop_front();
    EXPECT_NE(copy.find(1), nullptr);
}
TEST(ListTest, CopyConstructorWithEmptyList) {
    List<int> original;
    List<int> copy(original);
    EXPECT_TRUE(copy.is_empty());
}
TEST(ListTest, AssignmentOperatorCopiesElements) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    List<int> list2;
    list2 = list1;
    EXPECT_NE(list2.find(1), nullptr);
    EXPECT_NE(list2.find(2), nullptr);
}
TEST(ListTest, SelfAssignmentDoesNotBreakList) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list = list;
    EXPECT_NE(list.find(1), nullptr);
    EXPECT_NE(list.find(2), nullptr);
}
TEST(ListTest, IteratorTraversal) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    int sum = 0;
    int count = 0;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        sum += *it;
        count++;
    }
    EXPECT_EQ(count, 3);
    EXPECT_EQ(sum, 6);
}
TEST(ListTest, IteratorPostIncrement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    List<int>::Iterator it = list.begin();
    int first = *it;
    it++;
    int second = *it;
    EXPECT_EQ(first, 1);
    EXPECT_EQ(second, 2);
}
TEST(ListTest, IteratorPreIncrement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    List<int>::Iterator it = list.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
}
TEST(ListTest, IteratorEquality) {
    List<int> list;
    list.push_back(1);
    List<int>::Iterator it1 = list.begin();
    List<int>::Iterator it2 = list.begin();
    EXPECT_TRUE(it1 == it2);
    EXPECT_FALSE(it1 != it2);
    ++it1;
    EXPECT_FALSE(it1 == it2);
}
TEST(ListTest, IteratorOnEmptyList) {
    List<int> list;
    List<int>::Iterator begin = list.begin();
    List<int>::Iterator end = list.end();
    EXPECT_TRUE(begin == end);
    int count = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        count++;
    }
    EXPECT_EQ(count, 0);
}
TEST(ListTest, IteratorDereferenceEndThrows) {
    List<int> list;
    list.push_back(1);
    List<int>::Iterator it = list.end();
    EXPECT_THROW(*it, std::logic_error);
}
TEST(ListTest, IteratorIncrementEndThrows) {
    List<int> list;
    list.push_back(1);
    List<int>::Iterator it = list.end();
    EXPECT_THROW(++it, std::logic_error);
    EXPECT_THROW(it++, std::logic_error);
}
TEST(ListTest, ComplexOperationSequence) {
    List<int> list;
    list.push_back(10);
    list.push_front(5);
    list.push_back(15);
    list.insert(1, 7);
    list.pop_back();
    list.erase(1);
    list.pop_front();
    int count = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        count++;
    }
    EXPECT_EQ(count, 1);
}
TEST(ListTest, DifferentDataTypes) {
    List<std::string> stringList;
    stringList.push_back("hello");
    stringList.push_back("world");
    Node<std::string>* found = stringList.find("hello");
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->value, "hello");
    List<double> doubleList;
    doubleList.push_back(3.14);
    doubleList.push_back(2.71);
    Node<double>* foundDouble = doubleList.find(3.14);
    EXPECT_NE(foundDouble, nullptr);
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

//#include <gtest/gtest.h>
//#include "stack.h"
//
//TEST(StackListWithDeleteTest, ConstructorDestructor) {
//    StackList<int>* stack = new StackList<int>();
//    stack->push(1);
//    stack->push(2);
//    stack->push(3);
//    EXPECT_EQ(stack->size(), 3);
//    delete stack;  
//}
//
//TEST(StackListWithDeleteTest, CopyConstructor) {
//    StackList<int> original;
//    original.push(1);
//    original.push(2);
//
//    StackList<int> copy(original); 
//    EXPECT_EQ(copy.size(), 2);
//    EXPECT_EQ(copy.top(), 2);
//}
//
//TEST(StackListWithDeleteTest, AssignmentOperator) {
//    StackList<int> stack1;
//    stack1.push(10);
//    stack1.push(20);
//
//    StackList<int> stack2;
//    stack2 = stack1; 
//
//    EXPECT_EQ(stack2.size(), 2);
//    EXPECT_EQ(stack2.top(), 20);
//}
//
//TEST(StackListWithDeleteTest, MemoryManagement) {
//    {
//        StackList<int> stack;
//        for (int i = 0; i < 100; i++) {
//            stack.push(i);
//        }
//
//    }
//}
//