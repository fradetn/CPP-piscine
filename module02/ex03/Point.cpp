#include "includes/Point.hpp"

    
Point::Point(void): x(0), y(0) {
}
Point::Point(float const x, float const y): x(x), y(y) {
}
Point::Point(Point const &src) {
    *this = src;
}
Point::~Point(void) {

}

Point &Point::operator=(Point const &rhs) {
    const_cast<Fixed&>(this->x) = rhs.getX();
    const_cast<Fixed&>(this->y) = rhs.getY();
    return (*this);
}

Fixed Point::getX() const {
    return (this->x);
}
Fixed Point::getY() const {
    return (this->y);
}
