#include <gtest/gtest.h>
#include "../src/hoopd.h"

TEST(PredicateAssertionTest, watermelon) {
    hoopd::Hoopd *hp = new hoopd::Hoopd();
    // EXPECT_EQ(hp, 3);
    ASSERT_FALSE(hp == nullptr);
}
