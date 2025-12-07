#include <gtest/gtest.h>
#include "dsu.h"
TEST(DSUBasicTest, Initialization) {
    DSU dsu(5);
    EXPECT_EQ(dsu.find(0), 0);
    EXPECT_EQ(dsu.find(1), 1);
    EXPECT_EQ(dsu.find(2), 2);
    EXPECT_EQ(dsu.find(3), 3);
    EXPECT_EQ(dsu.find(4), 4);
}

TEST(DSUBasicTest, SimpleUnion) {
    DSU dsu(3);
    dsu.unite(0, 1);
    int root0 = dsu.find(0);
    int root1 = dsu.find(1);
    int root2 = dsu.find(2);
    EXPECT_EQ(root0, root1);
    EXPECT_NE(root0, root2);
}

TEST(DSUBasicTest, MultipleUnions) {
    DSU dsu(5);
    dsu.unite(0, 1);
    dsu.unite(2, 3);
    EXPECT_EQ(dsu.find(0), dsu.find(1));
    EXPECT_EQ(dsu.find(2), dsu.find(3));
    EXPECT_NE(dsu.find(0), dsu.find(2));
    EXPECT_NE(dsu.find(1), dsu.find(4));
}

TEST(DSUBasicTest, TransitiveConnection) {
    DSU dsu(4);
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(2, 3);
    EXPECT_EQ(dsu.find(0), dsu.find(3));
    EXPECT_EQ(dsu.find(1), dsu.find(3));
}

TEST(DSUBasicTest, RankBehavior) {
    DSU dsu(4);
    dsu.unite(0, 1);
    dsu.unite(2, 3);
    int root1 = dsu.find(0);
    int root2 = dsu.find(2);
    dsu.unite(0, 2);
    EXPECT_EQ(dsu.find(0), dsu.find(1));
    EXPECT_EQ(dsu.find(0), dsu.find(2));
    EXPECT_EQ(dsu.find(0), dsu.find(3));
}

TEST(DSUBasicTest, SelfUnion) {
    DSU dsu(3);
    dsu.unite(1, 1); 
    EXPECT_EQ(dsu.find(1), 1); 
}

TEST(DSUBasicTest, ChainUnion) {
    DSU dsu(6);
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(2, 3);
    dsu.unite(3, 4);
    EXPECT_EQ(dsu.find(0), dsu.find(4));
    EXPECT_NE(dsu.find(0), dsu.find(5));
}

TEST(DSUMemoryTest, LargeDSU) {
    const int SIZE = 1000;
    DSU dsu(SIZE);
    for (int i = 2; i < SIZE; i += 2) {
        dsu.unite(0, i);
    }
    for (int i = 3; i < SIZE; i += 2) {
        dsu.unite(1, i);
    }
    EXPECT_EQ(dsu.find(0), dsu.find(2));
    EXPECT_EQ(dsu.find(0), dsu.find(4));
    EXPECT_EQ(dsu.find(1), dsu.find(3));
    EXPECT_EQ(dsu.find(1), dsu.find(5));
    EXPECT_NE(dsu.find(0), dsu.find(1));
}