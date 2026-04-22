#include <iostream>

#pragma once

class Rectangle {
public:
  Rectangle(int _x, int _y, int _width, int _height);

  // TODO: Should these be private
  // private:
  static int instance_count;
  int id;

  int x;
  int y;
  int width;
  int height;
};

std::ostream &operator<<(std::ostream &oss, const Rectangle &rectangle);
