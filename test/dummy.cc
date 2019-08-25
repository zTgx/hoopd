#include <gtest/gtest.h>
#include "../src/dummy.h"

TEST(PredicateAssertionTest, watermelon) {
    Dummy* dummy_ptr = new Dummy(3);

    ASSERT_STRCASEEQ(dummy_ptr->get(), 3);
}
