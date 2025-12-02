#include <gtest/gtest.h>
#include "../lib_list/list.h"
TEST(ListTest, CreateEmpty) {
    List<int> list;
    EXPECT_TRUE(list.is_empty());
    EXPECT_EQ(list.size(), 0);
}
TEST(ListTest, CopyConstructor) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);

    List<int> list2(list1);
    EXPECT_EQ(list2.size(), 2);
}
TEST(ListTest, Assignment) {
    List<int> list1;
    list1.push_back(10);
    list1.push_back(20);

    List<int> list2;
    list2 = list1;
    EXPECT_EQ(list2.size(), 2);
}

TEST(ListTest, DestructorWorks) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
}
TEST(ListTest, PushElements) {
    List<int> list;
    list.push_front(2);
    list.push_back(3);
    list.push_front(1);
    EXPECT_EQ(list.size(), 3);
}
TEST(ListTest, PopElements) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_front();
    list.pop_back();
    EXPECT_EQ(list.size(), 1);
}
TEST(ListTest, InsertErase) {
    List<int> list;
    list.push_back(1);
    list.push_back(3);
    list.insert(1, 2); 
    list.erase(0);     
    EXPECT_EQ(list.size(), 2);
}
TEST(ListTest, Clear) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    EXPECT_TRUE(list.is_empty());
}
TEST(ListTest, Find) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    Node<int>* found = list.find(20);
    EXPECT_NE(found, nullptr);
}
TEST(ListTest, Exceptions) {
    List<int> list;
    EXPECT_THROW(list.pop_front(), std::logic_error);
    list.push_back(1);
    EXPECT_THROW(list.erase(5), std::logic_error);
}
TEST(ListTest, Iterators) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    int sum = 0;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        sum += *it;
    }
    EXPECT_EQ(sum, 6);
}
TEST(ListTest, DifferentTypes) {
    List<std::string> list;
    list.push_back("hello");
    list.push_back("world");
    EXPECT_EQ(list.size(), 2);
}
TEST(ListTest, IteratorRead) {
    List<int> list;
    for (int i = 0; i < 5; i++) {
        list.push_back(i * 2);
    }
    std::vector<int> result;
    for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
        result.push_back(*it);  
    }
    EXPECT_EQ(result.size(), 5u);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 4);
    EXPECT_EQ(result[3], 6);
    EXPECT_EQ(result[4], 8);
}

TEST(ListTest, IteratorWrite) {
    List<int> list;
    for (int i = 0; i < 5; i++) {
        list.push_back(0); 
    }
    int value = 1;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        *it = value * 10;
        value++;
    }
    value = 1;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        EXPECT_EQ(*it, value * 10);
        value++;
    }
}

TEST(ListTest, IteratorEmptyList) {
    List<int> list;
    List<int>::Iterator it1 = list.begin();
    EXPECT_EQ(it1, list.end());
    EXPECT_TRUE(list.begin() == list.end());
    int count = 0;
    for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
        count++;
    }
    EXPECT_EQ(count, 0);
    count = 0;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        count++;
    }
    EXPECT_EQ(count, 0);
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





