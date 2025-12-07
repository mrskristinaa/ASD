#include <gtest/gtest.h>
#include "queue.h"
TEST(QueueTest, ConstructorWithSize) {
    Queue<int> q(5);
    EXPECT_TRUE(q.is_empty());
    EXPECT_EQ(q.size(), 0);
}
TEST(QueueTest, DefaultConstructor) {
    Queue<int> q;
    EXPECT_TRUE(q.is_empty());
    q.enqueue(1);
    EXPECT_FALSE(q.is_empty());
}
TEST(QueueTest, CopyConstructor) {
    Queue<int> q1(3);
    q1.enqueue(1);
    q1.enqueue(2);
    Queue<int> q2(q1); 
    EXPECT_EQ(q2.size(), 2);
    EXPECT_EQ(q2.front(), 1);
}
TEST(QueueTest, AssignmentOperator) {
    Queue<int> q1(3);
    q1.enqueue(10);
    q1.enqueue(20);
    Queue<int> q2(2);
    q2 = q1; 
    EXPECT_EQ(q2.size(), 2);
    EXPECT_EQ(q2.front(), 10);
}
TEST(QueueTest, EnqueueMethod) {
    Queue<int> q(3);
    q.enqueue(42);
    EXPECT_EQ(q.size(), 1);
    EXPECT_EQ(q.front(), 42);
}
TEST(QueueTest, DequeueMethod) {
    Queue<int> q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.dequeue();
    EXPECT_EQ(q.size(), 1);
    EXPECT_EQ(q.front(), 2);
}
TEST(QueueTest, FrontMethod) {
    Queue<int> q(3);
    q.enqueue(100);
    EXPECT_EQ(q.front(), 100);
}
TEST(QueueTest, BackMethod) {
    Queue<int> q(3);
    q.enqueue(1);
    q.enqueue(2);
    EXPECT_EQ(q.back(), 2);
}
TEST(QueueTest, IsEmptyMethod) {
    Queue<int> q(3);
    EXPECT_TRUE(q.is_empty());
    q.enqueue(1);
    EXPECT_FALSE(q.is_empty());
}
TEST(QueueTest, IsFullMethod) {
    Queue<int> q(2);
    EXPECT_FALSE(q.is_full());
    q.enqueue(1);
    q.enqueue(2);
    EXPECT_TRUE(q.is_full());
}
TEST(QueueTest, SizeMethod) {
    Queue<int> q(3);
    EXPECT_EQ(q.size(), 0);
    q.enqueue(1);
    EXPECT_EQ(q.size(), 1);
}
TEST(QueueTest, ClearMethod) {
    Queue<int> q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.clear();
    EXPECT_TRUE(q.is_empty());
    EXPECT_EQ(q.size(), 0);
}
TEST(QueueTest, ExceptionEmptyDequeue) {
    Queue<int> q(3);
    EXPECT_THROW(q.dequeue(), std::logic_error);
}
TEST(QueueTest, ExceptionEmptyFront) {
    Queue<int> q(3);
    EXPECT_THROW(q.front(), std::logic_error);
}
TEST(QueueTest, ExceptionEmptyBack) {
    Queue<int> q(3);
    EXPECT_THROW(q.back(), std::logic_error);
}
TEST(QueueTest, ExceptionFullEnqueue) {
    Queue<int> q(2);
    q.enqueue(1);
    q.enqueue(2);
    EXPECT_THROW(q.enqueue(3), std::logic_error);
}
TEST(QueueTest, ExceptionInvalidSize) {
    EXPECT_THROW(Queue<int> q(0), std::invalid_argument);
    EXPECT_THROW(Queue<int> q(-5), std::invalid_argument);
}
TEST(QueueTest, CircularBehavior) {
    Queue<int> q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue(); 
    q.enqueue(4); 
    EXPECT_EQ(q.front(), 2);
    EXPECT_EQ(q.back(), 4);
}
TEST(QueueTest, DifferentTypes) {
    Queue<double> q1(3);
    q1.enqueue(3.14);
    EXPECT_DOUBLE_EQ(q1.front(), 3.14);
    Queue<std::string> q2(3);
    q2.enqueue("test");
    EXPECT_EQ(q2.front(), "test");
}
TEST(QueueTest, ReuseAfterClear) {
    Queue<int> q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.clear();
    q.enqueue(10); 
    EXPECT_EQ(q.front(), 10);
}