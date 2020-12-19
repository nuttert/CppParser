#include <gtest/gtest.h>
#include <iostream>
#include <cstdlib>
#include <future>
#include "utils.hpp"
#include "ConfigParser.hpp"

TEST(Utils, test_1)
{
    std::string str = "a b c ";
    deleteCharacters(str, { ' ' });
    ASSERT_EQ(str, "abc");
    str = "a = b c";
    deleteCharacters(str, { '=', ' ', 'c' });
    ASSERT_EQ(str, "ab");
}

TEST(ConfigParser, test_1)
{
    ConfigParser parser("../configs/test.config");
    ASSERT_EQ(parser["message"].getValue(), "hello_world_");
    ASSERT_EQ(parser["message_2"].getValue(), "hello2_world2_world3");
}
TEST(ConfigParser, test_2)
{
    ConfigParser parser("../configs/test3.config");
    ASSERT_EQ(parser["message"].getValue(), "");
}