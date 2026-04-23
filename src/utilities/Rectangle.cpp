
#include "Rectangle.h"

#include <array>
#include <cmath>
#include <iostream>

std::array<Point2d, 4> Rectangle::get_vertices() const {
  std::array<Point2d, 4> vertices{};
  vertices[0] = Point2d{x, y};
  vertices[1] = Point2d{x + width, y};
  vertices[2] = Point2d{x, y + height};
  vertices[3] = Point2d{x + width, y + height};
  return vertices;
}

bool Rectangle::contains(const Point2d p) const {
  return (p.x >= x && p.x <= x + width) && p.y >= y && p.y <= y + height;
}

std::optional<Rectangle> Rectangle::intersect(const Rectangle &other) const {
  // TODO: Optimize for identical rectangles
  for (const auto &vertex : other.get_vertices()) {
    // One vertex contained is enough for intersection
    if (contains(vertex)) {
      const auto xIntersection{std::max(x, other.x)};
      const auto yIntersection{std::max(y, other.y)};
      const auto widthIntersection{std::min(x + width, other.x + other.width)};
      const auto heightIntersection{std::min(y + height, other.y + other.height)};
      // FIXME: Check that area is not 0
      if (widthIntersection != 0 && heightIntersection != 0) {
        return Rectangle{xIntersection, yIntersection, widthIntersection - xIntersection,
                         heightIntersection - yIntersection};
      }
    }
  }

  // FIXME: Repeated code, this reverts rectangles
  for (const auto &vertex : get_vertices()) {
    // One vertex contained is enough for intersection
    if (other.contains(vertex)) {
      const auto xIntersection{std::max(x, other.x)};
      const auto yIntersection{std::max(y, other.y)};
      const auto widthIntersection{std::min(x + width, other.x + other.width)};
      const auto heightIntersection{std::min(y + height, other.y + other.height)};

      if (widthIntersection != 0 && heightIntersection != 0) {
        return Rectangle{xIntersection, yIntersection, widthIntersection - xIntersection,
                         heightIntersection - yIntersection};
      }
    }
  }

  // Couldn't find intersection
  return {};
}

std::ostream &operator<<(std::ostream &oss, const Rectangle &rectangle) {
  oss << "(" << rectangle.x << "," << rectangle.y << "), w=" << rectangle.width << ", h=" << rectangle.height;
  return oss;
}
