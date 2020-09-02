#include "composite-shape.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include "/Users/macbookpro/CLionProjects/AAA3/common/base-types.hpp"

golovin::CompositeShape::CompositeShape():
  size_(0),
  capacity_(1),
  array_(std::make_unique<shapePointer[]>(capacity_))
{}

golovin::CompositeShape::CompositeShape(const CompositeShape &src):
  size_(src.size_),
  capacity_(src.size_),
  array_(std::make_unique<shapePointer[]>(src.size_))
{
  for (size_t i = 0; i < src.size_; ++i)
  {
    array_[i] = src.array_[i];
  }
}

golovin::CompositeShape::CompositeShape(CompositeShape &&src):
  size_(src.size_),
  capacity_(src.capacity_),
  array_(std::move(src.array_))
{}

golovin::CompositeShape& golovin::CompositeShape::operator=(const CompositeShape &src)
{
  if (this != &src)
  {
    CompositeShape(src).swap(*this);
  }
  return *this;
}

golovin::CompositeShape& golovin::CompositeShape::operator=(CompositeShape &&src)
{
  if (this != &src)
  {
    size_ = src.size_;
    capacity_ = src.capacity_;
    array_ = std::move(src.array_);
    src.size_ = 0;
    src.capacity_ = 0;
  }
  return *this;
}

void golovin::CompositeShape::swap(CompositeShape &src)
{
  std::swap(size_, src.size_);
  std::swap(capacity_, src.capacity_);
  std::swap(array_, src.array_);
}

golovin::CompositeShape::shapePointer &golovin::CompositeShape::operator[](size_t index) const
{
  if (index < 0 || index >= size_)
  {
    throw std::out_of_range("Index is out of range");
  }
  return array_[index];
}

void golovin::CompositeShape::pushBack(const golovin::CompositeShape::shapePointer &newElement)
{
  if (newElement == nullptr)
  {
    throw std::invalid_argument("Empty pointer");
  }

  if (size_ == capacity_)
  {
    shapeArray tmp(std::make_unique<shapePointer[]>(COEFFICIENT * capacity_));
    for (size_t i = 0; i < size_; ++i)
    {
      tmp[i] = array_[i];
    }
    array_.swap(tmp);
    capacity_ *= COEFFICIENT;
  }
  array_[size_++] = newElement;
}

void golovin::CompositeShape::popBack()
{
  if (size_ == 0)
  {
    throw std::logic_error("Array is empty");
  }
  array_[size_--].reset();
}

double golovin::CompositeShape::getArea() const
{
  double sum = 0;
  for (size_t i = 0; i < size_; ++i)
  {
    sum += array_[i]->getArea();
  }
  return sum;
}

golovin::rectangle_t golovin::CompositeShape::getFrameRect() const
{
  if (size_ == 0)
  {
    throw std::logic_error("Array is empty");
  }
  rectangle_t rectangle = array_[0]->getFrameRect();
  double minX = rectangle.pos.x - rectangle.width / 2.0;
  double maxX = rectangle.pos.x + rectangle.width / 2.0;
  double minY = rectangle.pos.y - rectangle.height / 2.0;
  double maxY = rectangle.pos.y + rectangle.height / 2.0;
  for (size_t i = 1; i < size_; ++i)
  {
    rectangle_t curr = array_[i]->getFrameRect();
    minX = std::min(minX, curr.pos.x - curr.width / 2.0);
    maxX = std::max(maxX, curr.pos.x + curr.width / 2.0);
    minY = std::min(minY, curr.pos.y - curr.height / 2.0);
    maxY = std::max(maxY, curr.pos.y + curr.height / 2.0);
  }
  return {std::abs(maxX - minX), std::abs(maxY - minY),
    {(maxX + minX) / 2, (maxY + minY) / 2}};
}

void golovin::CompositeShape::scale(double coefficient)
{
  if(coefficient <= 0.0)
  {
    throw std::invalid_argument("Scaling coefficient is not positive");
  }
  for(size_t i = 0; i < size_; i++)
  {
    const point_t center = getFrameRect().pos;
    double dX = array_[i]->getFrameRect().pos.x - center.x;
    double dY = array_[i]->getFrameRect().pos.y - center.y;
    array_[i]->move(center.x + dX * coefficient, center.y + dY * coefficient);
    array_[i]->scale(coefficient);
  }
}

void golovin::CompositeShape::move(const golovin::point_t & destinationPoint)
{
  double dx = destinationPoint.x - getFrameRect().pos.x;
  double dy = destinationPoint.y - getFrameRect().pos.y;
  move(dx, dy);
}

void golovin::CompositeShape::move(double dX, double dY)
{
  for (size_t i = 0; i < size_; ++i)
  {
    array_[i]->move(dX, dY);
  }
}

bool golovin::CompositeShape::isEmpty() const
{
  return (size_ == 0);
}

golovin::point_t golovin::CompositeShape::getPos() const {
  return getFrameRect().pos;
}
