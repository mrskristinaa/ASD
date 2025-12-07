#include <gtest/gtest.h>
#include "doubly_linked_list.h"
TEST(DoublyLinkedListTest, IteratorEmpty) {
    DoublyLinkedList<int> list;
    EXPECT_TRUE(list.begin() == list.end());
    EXPECT_EQ(list.size(), 0);
    int count = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        count++;
    }
    EXPECT_EQ(count, 0);
    count = 0;
    for (auto it = list.end(); it != list.begin(); --it) {
        count++;
    }
    EXPECT_EQ(count, 0);
}
TEST(DoublyLinkedListTest, IteratorWrite) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    int value = 10;
    for (auto it = list.begin(); it != list.end(); ++it) {
        *it = value;
        value += 10;
    }
    value = 10;
    for (auto it = list.begin(); it != list.end(); ++it) {
        EXPECT_EQ(*it, value);
        value += 10;
    }
}
TEST(DoublyLinkedListTest, IteratorReadAndBidirectional) {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    auto it = list.begin();
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 20);
    ++it;
    EXPECT_EQ(*it, 30);
    auto it2 = list.begin();
    ++it2;
    --it2;
    EXPECT_EQ(*it2, 10);
    int sum = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        sum += *it;
    }
    EXPECT_EQ(sum, 60);
}