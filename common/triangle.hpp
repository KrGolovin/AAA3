#ifndef A1_TRIANGLE_HPP
#define A1_TRIANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"
namespace golovin {
  class Triangle : public Shape {
  public:
    Triangle(const point_t &a, const point_t &b, const point_t &c);

    double getArea() const override;

    void move(const point_t &) override;

    void move(double dX, double dY) override;

    void scale(double) override;

    rectangle_t getFrameRect() const override;

    point_t getPos() const override;

  private:
    point_t a_;
    point_t b_;
    point_t c_;
  };
}

#endif //A1_TRIANGLE_HPP
