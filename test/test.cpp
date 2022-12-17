#include <catch2/catch_test_macros.hpp>

int example() {
  return 32;
}

TEST_CASE("Title of the test", "[scope of the example]") {
  REQUIRE(example() == 32);  // passes
  REQUIRE(example() == 2);   // fails
}
