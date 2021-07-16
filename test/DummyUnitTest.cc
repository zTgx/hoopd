#include <gtest/gtest.h>
#include "hoopd.h"

class DummyTest : public ::testing::Test {
public:
    int get() {
        return dummy_ptr->get();
    }
protected:
    virtual void SetUp()
    {
        dummy_ptr = new Dummy(3);
    }

    virtual void TearDown()
    {
        delete dummy_ptr;
    }

private:
    Dummy* dummy_ptr;
};

TEST_F(DummyTest, DummyTest)
{
    int x = get();
    int expected = 3;
    EXPECT_EQ(x, expected);
}
