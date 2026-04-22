
#include "Rectangle.h"

Rectangle::Rectangle(int _x, int _y, int _width, int _height) :
    id{instance_count++},
    x{_x},
    y{_y},
    width{_width},
    height{_height} {
}

int Rectangle::instance_count {1};

std::ostream& operator<<(std::ostream& oss, const Rectangle& rectangle) {
    std::cout << rectangle.id << ": Rectangle at (" << rectangle.x << "," << rectangle.y << "), w=" << rectangle.width << ", h=" << rectangle.height << ".\n";
    return oss;
}
