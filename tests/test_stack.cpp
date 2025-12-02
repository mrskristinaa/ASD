#include <gtest/gtest.h>
#include "stack.h"
#include <stdexcept>
TEST(StackTest, Constructor) {
    Stack<int> stack(10);
    EXPECT_TRUE(stack.is_empty());
    EXPECT_FALSE(stack.is_full());
}

TEST(StackTest, InvalidSize) {
    EXPECT_THROW(Stack<int> stack(0), std::invalid_argument);
    EXPECT_THROW(Stack<int> stack(-5), std::invalid_argument);
}

TEST(StackTest, Push) {
    Stack<int> stack(5);

    stack.push(1);
    EXPECT_FALSE(stack.is_empty());
    EXPECT_EQ(stack.top(), 1);

    stack.push(2);
    EXPECT_EQ(stack.top(), 2);

    stack.push(3);
    EXPECT_EQ(stack.top(), 3);
}

TEST(StackTest, Pop) {
    Stack<int> stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(stack.top(), 3);
    stack.pop();
    EXPECT_EQ(stack.top(), 2);
    stack.pop();
    EXPECT_EQ(stack.top(), 1);
    stack.pop();
    EXPECT_TRUE(stack.is_empty());
}

TEST(StackTest, PopEmptyStack) {
    Stack<int> stack(5);
    EXPECT_THROW(stack.pop(), std::logic_error);

    stack.push(1);
    stack.pop();
    EXPECT_THROW(stack.pop(), std::logic_error);
}

TEST(StackTest, TopEmptyStack) {
    Stack<int> stack(5);
    EXPECT_THROW(stack.top(), std::logic_error);
}

TEST(StackTest, Overflow) {
    Stack<int> stack(3);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    EXPECT_TRUE(stack.is_full());
    EXPECT_THROW(stack.push(4), std::logic_error);
}

TEST(StackTest, IsEmpty) {
    Stack<int> stack(5);
    EXPECT_TRUE(stack.is_empty());
    stack.push(1);
    EXPECT_FALSE(stack.is_empty());
    stack.pop();
    EXPECT_TRUE(stack.is_empty());
}

TEST(StackTest, IsFull) {
    Stack<int> stack(2);
    EXPECT_FALSE(stack.is_full());
    stack.push(1);
    EXPECT_FALSE(stack.is_full());
    stack.push(2);
    EXPECT_TRUE(stack.is_full());
    stack.pop();
    EXPECT_FALSE(stack.is_full());
}

TEST(StackTest, Clear) {
    Stack<int> stack(5);
    for (int i = 0; i < 4; i++) {
        stack.push(i + 1);
    }
    EXPECT_FALSE(stack.is_empty());
    stack.clear();
    EXPECT_TRUE(stack.is_empty());
    EXPECT_THROW(stack.top(), std::logic_error);
}

TEST(StackTest, SequenceOperations) {
    Stack<int> stack(10);
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(stack.top(), 2);
    stack.pop();
    EXPECT_EQ(stack.top(), 1);
    stack.push(3);
    EXPECT_EQ(stack.top(), 3);
}

TEST(StackTest, DifferentDataTypes) {
    Stack<double> doubleStack(5);
    doubleStack.push(3.14);
    doubleStack.push(2.71);
    EXPECT_DOUBLE_EQ(doubleStack.top(), 2.71);
    Stack<std::string> stringStack(5);
    stringStack.push("hello");
    stringStack.push("world");
    EXPECT_EQ(stringStack.top(), "world");
}

TEST(StackTest, LastInFirstOut) {
    Stack<int> stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    EXPECT_EQ(stack.top(), 3);
    stack.pop();
    EXPECT_EQ(stack.top(), 2);
    stack.pop();
    EXPECT_EQ(stack.top(), 1);
    stack.pop();
    EXPECT_TRUE(stack.is_empty());
}