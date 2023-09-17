#include "binaryTree.h"

#include <gtest/gtest.h>

class BinaryTreeTest : public ::testing::Test {
   protected:
    struct {
        std::vector<float> probabilities{0.375, 0.375, 0.125, 0.125};
        std::vector<std::vector<int>> R{{0, 1, 1, 2, 2}, {0, 0, 2, 2, 2}, {0, 0, 0, 3, 3}, {0, 0, 0, 0, 4}, {0, 0, 0, 0, 0}};
    } testData;

    void SetUp() override{};
    void TearDown() override{};
};

TEST_F(BinaryTreeTest, createOptimalBinaryTree_ok) {
    BinaryTree<float> tree;
    tree.buildTree(testData.R, testData.probabilities);

    EXPECT_EQ(tree.getRoot()->item, 0.375);
    EXPECT_EQ(tree.getRoot()->left->item, 0.375);
    EXPECT_EQ(tree.getRoot()->right->item, 0.125);
    EXPECT_EQ(tree.getRoot()->right->right->item, 0.125);

    EXPECT_EQ(tree.getRoot()->left->left, nullptr);
    EXPECT_EQ(tree.getRoot()->left->right, nullptr);
    EXPECT_EQ(tree.getRoot()->right->left, nullptr);
    EXPECT_EQ(tree.getRoot()->right->right->right, nullptr);
    EXPECT_EQ(tree.getRoot()->right->right->left, nullptr);

    EXPECT_EQ(2, tree.getDepth());
}
