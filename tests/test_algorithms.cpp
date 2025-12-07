#include <gtest/gtest.h>
#include "algorithms.h"
#include "stack.h"
TEST(AlgorithmsTest, 1) {
    EXPECT_TRUE(check_algorithms("()"));
    EXPECT_TRUE(check_algorithms("{}"));
    EXPECT_TRUE(check_algorithms("[]"));
}

TEST(AlgorithmsTest, 2) {
    EXPECT_TRUE(check_algorithms("({[]})"));
    EXPECT_TRUE(check_algorithms("{[()]}"));
    EXPECT_TRUE(check_algorithms("({})[]"));
}

TEST(AlgorithmsTest, 3) {
    EXPECT_FALSE(check_algorithms("("));
    EXPECT_FALSE(check_algorithms(")"));
    EXPECT_FALSE(check_algorithms("{[}"));
    EXPECT_FALSE(check_algorithms("({[}])"));
}
TEST(AlgorithmsTest, 4) {
    EXPECT_FALSE(check_algorithms("([)]"));
    EXPECT_FALSE(check_algorithms("{(})"));
}
TEST(AlgorithmsTest, 5) {
    EXPECT_TRUE(check_algorithms("()[]{}"));
    EXPECT_TRUE(check_algorithms("({[]})[]{}"));
}

TEST(AlgorithmsTest, 6) {
    EXPECT_FALSE(check_algorithms("())"));
    EXPECT_FALSE(check_algorithms("{[}]"));
    EXPECT_FALSE(check_algorithms("((("));
}