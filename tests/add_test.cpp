#include <gtest/gtest.h>

#include "add.h"

TEST(Add, SumsTwoNumbers) {
    EXPECT_EQ(add(2, 3), 5);
}
