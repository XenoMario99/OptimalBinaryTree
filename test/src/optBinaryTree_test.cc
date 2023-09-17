#include <gtest/gtest.h>

#include "optSearch.h"

class OptBinaryTreeTest : public ::testing::Test {
   protected:
    struct {
        std::vector<float> probabilities{0.375, 0.375, 0.125, 0.125};
    } testData;

    void SetUp() override{};
    void TearDown() override{};
};

TEST_F(OptBinaryTreeTest, makeOptimal_ok) {
    std::vector<std::vector<int>> rRef{{0, 1, 1, 2, 2}, {0, 0, 2, 2, 2}, {0, 0, 0, 3, 3}, {0, 0, 0, 0, 4}, {0, 0, 0, 0, 0}};

    std::vector<std::vector<int>> R{optSearch::makeOptimal(testData.probabilities)};

    for (int i = 0; i < R.size(); i++) {
        for (int j = 0; j < R.size(); j++) {
            EXPECT_EQ(rRef.at(i).at(j), R.at(i).at(j));
        }
    }
}