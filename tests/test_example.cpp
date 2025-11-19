#include <gtest/gtest.h>

#include "yml/Yml.h"

TEST(SampleTest, Addition) {
    EXPECT_EQ(1 + 1, 2);
}

TEST(SampleTest, FalseTest) {
    EXPECT_FALSE(false);
}

TEST(Basic, StringGet) {
    yml::Yml yml("../../tests/yml/1.yml");
    EXPECT_EQ(yml["hello"].as<std::string>(), "world");
}
