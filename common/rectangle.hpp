#ifndef A1_RECTANGLE_HPP
#define A1_RECTANGLE_HPP

#include "/Users/macbookpro/CLionProjects/AAA3/common/shape.hpp"
#include "/Users/macbookpro/CLionProjects/AAA3/common/base-types.hpp"

namespace golovin
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &, double width, double height);

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void scale(double) override;

    void move(const point_t &) override;

    void move(double dX, double dY) override;

    point_t getPos() const override;

  private:
    point_t center_;
    double width_;
    double height_;
  };
}

#endif
