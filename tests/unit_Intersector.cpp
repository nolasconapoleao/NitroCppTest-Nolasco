#include <main_test.h>

#include "utilities/Intersector.h"

std::string three_of_the_same{R"(
{
    "rects": [
        {"x": 100, "y": 100, "w": 250, "h": 80 },
        {"x": 100, "y": 100, "w": 250, "h": 80 },
        {"x": 100, "y": 100, "w": 250, "h": 80 }
    ]
})"};

std::string requirement_sheet{R"({
      "rects": [
          {"x": 100, "y": 100, "w": 250, "h": 80 },
          {"x": 120, "y": 200, "w": 250, "h": 150 },
          {"x": 140, "y": 160, "w": 250, "h": 100 },
          {"x": 160, "y": 140, "w": 350, "h": 190 }
      ]
  })"};


TEST_CASE("Three equal rectangles", "[Intersector]") {
  Intersector intersector{};
  intersector.parseFromString(three_of_the_same);
  const auto intersections{intersector.calculate_intersections()};

  REQUIRE(intersections.size() == 4);
  REQUIRE(intersections[0].indexes.size() == 2);
  REQUIRE(intersections[1].indexes.size() == 2);
  REQUIRE(intersections[2].indexes.size() == 2);
  REQUIRE(intersections[3].indexes.size() == 3);
}

TEST_CASE("Requirement sheet", "[Intersector]") {
  Intersector intersector{};
  intersector.parseFromString(requirement_sheet);
  const auto intersections{intersector.calculate_intersections()};

  REQUIRE(intersections.size() == 7);
  REQUIRE(intersections[0].indexes.size() == 2);
  REQUIRE(intersections[1].indexes.size() == 2);
  REQUIRE(intersections[2].indexes.size() == 2);
  REQUIRE(intersections[3].indexes.size() == 2);
  REQUIRE(intersections[4].indexes.size() == 2);
  REQUIRE(intersections[5].indexes.size() == 3);
  REQUIRE(intersections[6].indexes.size() == 3);
}
