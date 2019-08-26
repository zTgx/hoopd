#include <gtest/gtest.h>
#include "../src/dummy.h"

TEST(PredicateAssertionTest, watermelon) {
    Dummy* dummy_ptr = new Dummy(3);
    int v = dummy_ptr->get();
    EXPECT_EQ(v, 3);
}
