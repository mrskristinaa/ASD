#include <gtest/gtest.h>
#include "dsu.h"
TEST(DSUTest, InitialState) {
    DSU dsu(5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(dsu.find(i), i);
    }
}
TEST(DSUTest, SimpleUnion) {
    DSU dsu(3);
    dsu.unite(0, 1);
    EXPECT_EQ(dsu.find(0), dsu.find(1));
    EXPECT_NE(dsu.find(0), dsu.find(2));
}
TEST(DSUTest, TransitiveUnion) {
    DSU dsu(4);
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    EXPECT_EQ(dsu.find(0), dsu.find(2));
    EXPECT_NE(dsu.find(0), dsu.find(3));
}
TEST(DSUTest, MultipleUnions) {
    DSU dsu(6);
    dsu.unite(0, 1);
    dsu.unite(2, 3);
    dsu.unite(4, 5);
    EXPECT_EQ(dsu.find(0), dsu.find(1));
    EXPECT_EQ(dsu.find(2), dsu.find(3));
    EXPECT_EQ(dsu.find(4), dsu.find(5));
    EXPECT_NE(dsu.find(0), dsu.find(2));
    EXPECT_NE(dsu.find(0), dsu.find(4));
    EXPECT_NE(dsu.find(2), dsu.find(4));
}
TEST(DSUTest, UnionAllElements) {
    DSU dsu(5);
    for (int i = 0; i < 4; i++) {
        dsu.unite(i, i + 1);
    }
    for (int i = 1; i < 5; i++) {
        EXPECT_EQ(dsu.find(0), dsu.find(i));
    }
}
TEST(DSUTest, SelfUnion) {
    DSU dsu(3);
    dsu.unite(0, 0);
    EXPECT_EQ(dsu.find(0), 0);
}