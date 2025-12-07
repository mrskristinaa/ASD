#include <gtest/gtest.h>
#include "queue.h"
#include <stdexcept>
TEST(QueueTest, ConstructorWithSize) {
    Queue<int> q(5);
    EXPECT_TRUE(q.is_empty());
    EXPECT_FALSE(q.is_full());
}
TEST(QueueTest, InvalidConstructor) {
    EXPECT_THROW(Queue<int> q(0), std::invalid_argument);
    EXPECT_THROW(Queue<int> q(-5), std::invalid_argument);
}
TEST(QueueTest, PushAndHead) {
    Queue<int> q(3);
    q.push(10);
    EXPECT_EQ(q.head(), 10);
    q.push(20);
    EXPECT_EQ(q.head(), 10); 
}
TEST(QueueTest, Pop) {
    Queue<int> q(3);
    q.push(10);
    q.push(20);
    q.push(30);
    EXPECT_EQ(q.head(), 10);
    q.pop();
    EXPECT_EQ(q.head(), 20);
    q.pop();
    EXPECT_EQ(q.head(), 30);
}
TEST(QueueTest, PopEmpty) {
    Queue<int> q(3);
    EXPECT_THROW(q.pop(), std::logic_error);
}
TEST(QueueTest, HeadEmpty) {
    Queue<int> q(3);
    EXPECT_THROW(q.head(), std::logic_error);
}
TEST(QueueTest, Overflow) {
    Queue<int> q(2);
    q.push(1);
    q.push(2);
    EXPECT_THROW(q.push(3), std::logic_error);
}
TEST(QueueTest, IsEmpty) {
    Queue<int> q(3);
    EXPECT_TRUE(q.is_empty());
    q.push(1);
    EXPECT_FALSE(q.is_empty());
    q.pop();
    EXPECT_TRUE(q.is_empty());
}
TEST(QueueTest, IsFull) {
    Queue<int> q(2);
    EXPECT_FALSE(q.is_full());
    q.push(1);
    EXPECT_FALSE(q.is_full());
    q.push(2);
    EXPECT_TRUE(q.is_full());
}
TEST(QueueTest, Clear) {
    Queue<int> q(3);
    q.push(1);
    q.push(2);
    q.clear();
    EXPECT_TRUE(q.is_empty());
}
TEST(QueueTest, FirstInFirstOut) {
    Queue<int> q(3);
    q.push(1);
    q.push(2);
    q.push(3);
    EXPECT_EQ(q.head(), 1);  
    q.pop();
    EXPECT_EQ(q.head(), 2);  
    q.pop();
    EXPECT_EQ(q.head(), 3);  
}
TEST(QueueTest, CircularBuffer) {
    Queue<int> q(3);
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop(); 
    q.pop();
    q.push(4); 
    q.push(5); 
    EXPECT_EQ(q.head(), 3);
    q.pop();
    EXPECT_EQ(q.head(), 4);
    q.pop();
    EXPECT_EQ(q.head(), 5);
}
TEST(QueueTest, DifferentTypes) {
    Queue<std::string> q(2);
    q.push("hello");
    q.push("world");
    EXPECT_EQ(q.head(), "hello");
}