#include <main_test.h>

#include "test_utilities.h"
#include "utilities/Rectangle.h"

TEST_CASE("Points coordinates respected", "[Point2d]") {
  const Point2d p{1, 0};
  REQUIRE(p.x == 1);
  REQUIRE(p.y == 0);
}

TEST_CASE("Rectangle coordinates respected", "[Rectangle]") {
  Rectangle r{30, 50, 100, 200};
  REQUIRE(r.x == 30);
  REQUIRE(r.y == 50);
  REQUIRE(r.width == 100);
  REQUIRE(r.height == 200);
}

TEST_CASE("Get rectangle borders", "[Rectangle]") {
  Rectangle r{30, 50, 100, 200};
  // FIXME: Make order irrelevant
  const auto &vertices = r.get_vertices();
  REQUIRE(vertices[0] == Point2d{30, 50});   // x,       y
  REQUIRE(vertices[1] == Point2d{130, 50});  // x+width, y
  REQUIRE(vertices[2] == Point2d{30, 250});  // x,       y+height
  REQUIRE(vertices[3] == Point2d{130, 250}); // x+width, y+height
}

TEST_CASE("Rectangle Point collision", "[Rectangle]") {
  Rectangle r{30, 50, 100, 200};
  // On border
  REQUIRE(r.contains(Point2d{30, 50}));
  REQUIRE(r.contains(Point2d{130, 250}));
  REQUIRE(r.contains(Point2d{130, 200}));
  // Inside
  REQUIRE(r.contains(Point2d{100, 200}));
  REQUIRE(r.contains(Point2d{50, 100}));
  // Outside
  REQUIRE(!r.contains(Point2d{100, 300}));
  REQUIRE(!r.contains(Point2d{200, 200}));
  REQUIRE(!r.contains(Point2d{200, 300}));
}

// FIXME: Still broken
TEST_CASE("Rectangle Rectangle collision", "[Rectangle]") {
  const Rectangle base{0, 100, 200, 300};

  // Self intersection returns itself
  auto intersection = base.intersect(base);
  REQUIRE(intersection.has_value());
  REQUIRE(intersection == base);

  // Shared border means 0 area intersection
  Rectangle r1{200, 100, 200, 300};
  REQUIRE(!base.intersect(r1).has_value());
  REQUIRE(!r1.intersect(base).has_value());

  // 0 Vertex inside base
  Rectangle r2{0, 200, 200, 300};
  REQUIRE(!base.intersect(r2).has_value());
  REQUIRE(!r2.intersect(base).has_value());

  // 1 Vertex inside base
  Rectangle r3{0, 200, 200, 300};
  Rectangle ir3{150, 150, 50, 50};
  intersection = base.intersect(r3);
  REQUIRE(intersection.has_value());
  REQUIRE(intersection.value() == ir3);

  intersection = r3.intersect(base);
  REQUIRE(intersection.has_value());
  REQUIRE(intersection.value() == ir3);

  // 2 Vertex inside base
  Rectangle r4{0, 200, 200, 300};
  Rectangle ir4{150, 150, 50, 50};
  intersection = r4.intersect(base);
  REQUIRE(intersection.has_value());
  REQUIRE(intersection.value() == ir4);

  intersection = r4.intersect(base);
  REQUIRE(intersection.has_value());
  REQUIRE(intersection.value() == ir4);

  // 4 Vertex inside base
  Rectangle r5{0, 200, 200, 300};
  Rectangle ir5{150, 150, 50, 50};
  intersection = base.intersect(r5);
  REQUIRE(intersection.has_value());
  REQUIRE(intersection.value() == ir5);

  intersection = r5.intersect(base);
  REQUIRE(intersection.has_value());
  REQUIRE(intersection.value() == ir5);
}
