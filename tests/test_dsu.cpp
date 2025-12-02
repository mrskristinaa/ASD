#include <gtest/gtest.h>
#include "dsu.h"
TEST(DSU_Simple, Create) {
    DSU dsu(5);
    EXPECT_EQ(dsu.find(0), 0);
    EXPECT_EQ(dsu.find(4), 4);
}
TEST(DSU_Simple, UnionTwo) {
    DSU dsu(5);
    dsu.unite(0, 1);
    EXPECT_EQ(dsu.find(0), dsu.find(1));
    EXPECT_NE(dsu.find(0), dsu.find(2));
}
TEST(DSU_Simple, ChainUnion) {
    DSU dsu(4);
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(2, 3);
    EXPECT_EQ(dsu.find(0), dsu.find(3));
    EXPECT_EQ(dsu.find(1), dsu.find(2));
}
TEST(DSU_Simple, SelfUnion) {
    DSU dsu(3);
    dsu.unite(1, 1);  
    EXPECT_EQ(dsu.find(1), 1);
}
TEST(DSU_Simple, MultipleSets) {
    DSU dsu(6);
    dsu.unite(0, 1);
    dsu.unite(2, 3);
    dsu.unite(4, 5);
    EXPECT_EQ(dsu.find(0), dsu.find(1));
    EXPECT_EQ(dsu.find(2), dsu.find(3));
    EXPECT_EQ(dsu.find(4), dsu.find(5));
    EXPECT_NE(dsu.find(0), dsu.find(2));
    EXPECT_NE(dsu.find(2), dsu.find(4));
}
TEST(DSU_Simple, LargeDSU) {
    DSU dsu(100);
    for (int i = 1; i < 100; i++) {
        dsu.unite(0, i);
    }
    for (int i = 0; i < 100; i++) {
        EXPECT_EQ(dsu.find(i), dsu.find(0));
    }
}