#include <iostream>
#include <stdexcept>
#include "/Users/macbookpro/CLionProjects/AAA3/common/rectangle.hpp"
#include "/Users/macbookpro/CLionProjects/AAA3/common/circle.hpp"
#include "/Users/macbookpro/CLionProjects/AAA3/common/triangle.hpp"
#include "/Users/macbookpro/CLionProjects/AAA3/common/composite-shape.hpp"

int main()
{
  const int COUNT_OF_FIGURES = 3;
//  golovin::Rectangle rectangle(golovin::point_t{2, 1.5}, 2, 5);
//  golovin::Circle circle(golovin::point_t{1, 1}, 1);
//  golovin::Triangle triangle(golovin::point_t{0, 0}, golovin::point_t{0, 1}, golovin::point_t{2, 0});
  golovin::CompositeShape figures;
  figures.pushBack(std::make_shared<golovin::Rectangle>(golovin::point_t{2, 1.5}, 2, 5));
  figures.pushBack(std::make_shared<golovin::Circle>(golovin::point_t{1, 1}, 1));
  figures.pushBack(std::make_shared<golovin::Triangle>(golovin::point_t{0, 0}, golovin::point_t{0, 1}, golovin::point_t{2, 0}));
  std::string names[] = {"Rectangle", "Circle", "Triangle"};

  for (int i = 0; i < COUNT_OF_FIGURES; i++)
  {
    std::cout << names[i] << ": \n";
    std::cout << "Area of " << names[i] << " is " << figures[i]->getArea() << "\n";
    figures[i]->scale(2);
    std::cout << "Area of " << names[i] << " after scalability 2x is " << figures[i]->getArea() << "\n";
    std::cout << "Frame Rectangle position of " << names[i] << " is (" << figures[i]->getFrameRect().pos.x << "; "
              << figures[i]->getFrameRect().pos.y << ")\n";
    std::cout << "Width frame Rectangle of " << names[i] << " is " << figures[i]->getFrameRect().width
              << " and height is " << figures[i]->getFrameRect().height << "\n";
    figures[i]->move({1, 2});
    std::cout << "Position " << names[i] << " after moving in {1, 2} is (" << figures[i]->getPos().x << "; "
              << figures[i]->getPos().y << ")\n";
    figures[i]->move(1, 2);
    std::cout << "Position " << names[i] << " after moving to offset (1, 2) is (" << figures[i]->getPos().x
              << "; " << figures[i]->getPos().y << ")\n\n";
  }
  std::string name = "CompositeShape";
  std::cout << name << ": \n";
  std::cout << "Area of " << name << " is " << figures.getArea() << "\n";
  figures.scale(2);
  std::cout << "Area of " << name << " after scalability 2x is " << figures.getArea() << "\n";
  std::cout << "Frame Rectangle position of " << name << " is (" << figures.getFrameRect().pos.x << "; "
            << figures.getFrameRect().pos.y << ")\n";
  std::cout << "Width frame Rectangle of " << name << " is " << figures.getFrameRect().width
            << " and height is " << figures.getFrameRect().height << "\n";
  figures.move({1, 2});
  std::cout << "Position " << name << " after moving in {1, 2} is (" << figures.getPos().x << "; "
            << figures.getPos().y << ")\n";
  figures.move(1, 2);
  std::cout << "Position " << name << " after moving to offset (1, 2) is (" << figures.getPos().x
            << "; " << figures.getPos().y << ")\n\n";

  figures.popBack();
  std::cout << ((figures.isEmpty()) ? "Is empty" : "Isn't empty") << '\n';
  figures.popBack();
  std::cout << ((figures.isEmpty()) ? "Is empty" : "Isn't empty") << '\n';
  figures.popBack();
  std::cout << ((figures.isEmpty()) ? "Is empty" : "Isn't empty") << '\n';
  return 0;
}
