#include <optional>
#include <ostream>

#pragma once

struct Rectangle {
  [[nodiscard]] std::optional<Rectangle> intersect(const Rectangle &other) const;

  int x;
  int y;
  int width;
  int height;
};

std::ostream &operator<<(std::ostream &oss, const Rectangle &rectangle);
bool operator==(const Rectangle &lhs, const Rectangle &rhs);