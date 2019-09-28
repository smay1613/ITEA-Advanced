#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "linkLevelNodes.cpp"

using ::testing::Return;
using ::testing::_;

TEST(linkLevelNodesTest1, linkLevelNodes) {
  node node7 {7, nullptr,nullptr,nullptr};
  node node6 {6, nullptr,nullptr,nullptr};
  node node5 {5, &node6 ,&node7 ,nullptr};
  node node4 {4, nullptr,nullptr,nullptr};
  node node3 {3, &node5 ,nullptr,nullptr};
  node node2 {2, &node3 , &node4,nullptr};
  node node1 {1, &node2 ,nullptr, nullptr};
  linkLevelNodes(&node1);
  EXPECT_EQ(node1.level, nullptr);
  EXPECT_EQ(node2.level, nullptr);
  EXPECT_EQ(node3.level, &node4);
  EXPECT_EQ(node4.level, nullptr);
  EXPECT_EQ(node5.level, nullptr);
  EXPECT_EQ(node6.level, &node7);
  EXPECT_EQ(node7.level, nullptr);
}

TEST(linkLevelNodesTest2, linkLevelNodes) {
  node node9 {9, nullptr,nullptr,nullptr};
  node node8 {8, nullptr,nullptr,nullptr};
  node node7 {7, nullptr,nullptr,nullptr};
  node node6 {6, nullptr,nullptr,nullptr};
  node node5 {5, &node8 ,&node9 ,nullptr};
  node node4 {4, &node6 ,&node7,nullptr};
  node node3 {3, &node5 ,nullptr,nullptr};
  node node2 {2, nullptr,&node4,nullptr};
  node node1 {1, &node2 ,&node3, nullptr};
  linkLevelNodes(&node1);
  EXPECT_EQ(node2.level, &node3);
  EXPECT_EQ(node4.level, &node5);
  EXPECT_EQ(node6.level, &node7);
  EXPECT_EQ(node7.level, &node8);
  EXPECT_EQ(node8.level, &node9);
  EXPECT_EQ(node2.level, &node3);
  EXPECT_EQ(node5.level, nullptr);
}

TEST(linkLevelNodesTest3, linkLevelNodes) {
  linkLevelNodes(nullptr);
}

TEST(linkLevelNodesTest4, linkLevelNodes) {
  node node5 {5, nullptr,nullptr,nullptr};
  node node4 {4, nullptr,&node5,nullptr};
  node node3 {3, nullptr,&node4,nullptr};
  node node2 {2, nullptr,&node3,nullptr};
  node node1 {1, nullptr,&node2,nullptr};
  linkLevelNodes(&node1);
  EXPECT_EQ(node1.level, nullptr);
  EXPECT_EQ(node2.level, nullptr);
  EXPECT_EQ(node3.level, nullptr);
  EXPECT_EQ(node4.level, nullptr);
  EXPECT_EQ(node5.level, nullptr);
}

TEST(linkLevelNodesTest5, linkLevelNodes) {
  node node6 {6, nullptr,nullptr,nullptr};
  node node5 {5, nullptr,nullptr,nullptr};
  node node4 {4, &node5,&node6,nullptr};
  node node3 {3, nullptr,&node4,nullptr};
  node node2 {2, nullptr,&node3,nullptr};
  node node1 {1, nullptr,&node2,nullptr};
  linkLevelNodes(&node1);
  EXPECT_EQ(node1.level, nullptr);
  EXPECT_EQ(node2.level, nullptr);
  EXPECT_EQ(node3.level, nullptr);
  EXPECT_EQ(node4.level, nullptr);
  EXPECT_EQ(node5.level, &node6);
  EXPECT_EQ(node6.level, nullptr);
}
