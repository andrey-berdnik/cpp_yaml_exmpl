#include "../src/yaml_parse.cpp"

#include <gtest/gtest.h>

TEST(yaml_parce_test, BasicAssertions) {
  std::vector<set_prog_start> parced = parse_yaml("../tests/example.yml");

  EXPECT_EQ(parced[0].name, "test_name");
}