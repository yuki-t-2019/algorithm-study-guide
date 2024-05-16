#include "dfs.h"
#include <gtest/gtest.h>

TEST(DFSTest, ReturnsTrueForValidSubset) {
    std::vector<int> elements = {1, 2, 3, 4, 5};
    int target_sum = 9;
    EXPECT_TRUE(Dfs(0, 0, elements, target_sum));
}

TEST(DFSTest, ReturnsFalseForInvalidSubset) {
    std::vector<int> elements = {1, 2, 3, 4, 5};
    int target_sum = 20;
    EXPECT_FALSE(Dfs(0, 0, elements, target_sum));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
