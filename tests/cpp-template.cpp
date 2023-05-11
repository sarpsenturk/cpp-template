#include "cpp-template.h"

#include <gtest/gtest.h>

namespace
{
    TEST(CppTemplate, BasicTest)
    {
        EXPECT_EQ(cpp_template::hello_world(), "Hello cpp_template");
    }
} // namespace
