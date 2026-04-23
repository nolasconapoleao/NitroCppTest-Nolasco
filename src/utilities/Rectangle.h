#include <optional>
#include <ostream>

#pragma once

struct Point2d {
  int x{};
  int y{};
};

struct Rectangle {
  [[nodiscard]] std::optional<Rectangle> intersect(const Rectangle &other) const;
  /// @brief Calculates 4 vertices that bound the rectangle
  /// @return Bounding vertices for rectangle
  std::array<Point2d, 4> get_vertices() const;
  /// @brief Returns true if point is inside rectangle (if on border, does not count).
  /// @param  point to check
  /// @return true if point is inside rectangle.
  bool contains(const Point2d) const;

  int x;
  int y;
  int width;
  int height;
};

std::ostream &operator<<(std::ostream &oss, const Rectangle &rectangle);
bool operator==(const Rectangle &lhs, const Rectangle &rhs);