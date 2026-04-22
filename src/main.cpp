#include "Rectangle.h"

int main()
{
    Rectangle rect1 {100,100, 250, 80};
    Rectangle rect2 {120,200, 250, 150};
    Rectangle rect3 {140,160, 250, 100};
    Rectangle rect4 {160,140, 350, 190};

    std::cout << rect1;
    std::cout << rect2;
    std::cout << rect3;
    std::cout << rect4;
    return 0;
}
