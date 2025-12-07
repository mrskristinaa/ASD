#include <gtest/gtest.h>
#include "tvector.h"
TEST(TVectorTest, IteratorEmpty) {
    TVector<int> vec;
    EXPECT_TRUE(vec.begin() == vec.end());
    EXPECT_EQ(vec.size(), 0);
    int count = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        count++;
    }
    EXPECT_EQ(count, 0);
}
TEST(TVectorTest, IteratorWrite) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    int value = 10;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        *it = value;
        value += 10;
    }
    value = 10;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        EXPECT_EQ(*it, value);
        value += 10;
    }
}
TEST(TVectorTest, IteratorReadAndBidirectional) {
    TVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    int sum = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        sum += *it;
    }
    EXPECT_EQ(sum, 60);
    auto it = vec.end();
    --it;
    EXPECT_EQ(*it, 30);
    --it;
    EXPECT_EQ(*it, 20);
    --it;
    EXPECT_EQ(*it, 10);
    auto it2 = vec.begin();
    ++it2;
    EXPECT_EQ(*it2, 20);
    --it2;
    EXPECT_EQ(*it2, 10);
}