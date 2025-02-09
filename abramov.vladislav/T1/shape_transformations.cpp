#include "shape_transformations.hpp"
#include <limits>

namespace
{
  void getArray(std::istream &in, double *x, size_t k)
  {
    for (size_t i = 0; i < k; ++i)
    {
      in >> x[i];
    }
  }

  abramov::Rectangle *makeRectangle(std::istream &in)
  {
    constexpr size_t k = 4;
    double arr[k] = {};
    getArray(in, arr, k);
    return new abramov::Rectangle({arr[0], arr[1]}, {arr[2], arr[3]});
  }

  abramov::Square *makeSquare(std::istream &in)
  {
    constexpr size_t k = 3;
    double arr[k] = {};
    getArray(in, arr, k);
    return new abramov::Square({arr[0], arr[1]}, arr[2]);
  }

  abramov::ComplexQuad *makeComplexQuad(std::istream &in)
  {
    constexpr size_t k = 8;
    double x[k] = {};
    getArray(in, x, k);
    return new abramov::ComplexQuad({x[0], x[1]}, {x[2], x[3]}, {x[4], x[5]}, {x[6], x[7]});
  }

  abramov::Shape *makeShape(std::string s1, std::istream &in)
  {
    abramov::Shape *figure = nullptr;
    if (s1 == "RECTANGLE")
    {
      figure = makeRectangle(in);
    }
    else if (s1 == "SQUARE")
    {
      figure = makeSquare(in);
    }
    else if (s1 == "COMPLEXQUAD")
    {
      figure = makeComplexQuad(in);
    }
    else
    {
      throw std::invalid_argument("Figure is not supported\n");
    }
    return figure;
  }

  void printFrameRectCoords(const abramov::rectangle_t &r)
  {
    const double x1 = r.pos.x - r.width / 2;
    const double y1 = r.pos.y - r.height / 2;
    const double x2 = r.pos.x + r.width / 2;
    const double y2 = r.pos.y + r.height / 2;
    std::cout << x1 << " " << y1 << " ";
    std::cout << x2 << " " << y2;
  }
}

void abramov::getShapes(std::istream &in, Composite &shapes, point_t &p, double &k, bool &flag)
{
  while (in)
  {
    std::string s1;
    in >> s1;
    Shape *figure = nullptr;
    try
    {
      if (s1 == "SCALE")
      {
        in >> p.x >> p.y >> k;
      }
      else
      {
        try
        {
          figure = makeShape(s1, in);
          shapes.push_back(figure);
        }
        catch (const std::invalid_argument &)
        {
        }
        catch (const std::logic_error &)
        {
          flag = true;
        }
      }
    }
    catch (const std::bad_alloc &)
    {
      delete figure;
    }
  }
}

void abramov::printShapes(std::ostream &out, const Composite &shapes, size_t i)
{
  if (i == 0)
  {
    throw std::logic_error("There is no figures\n");
  }
  std::ios stream(NULL);
  stream.copyfmt(out);
  out << std::fixed << std::setprecision(1);
  double s = shapes.getArea();
  out << s << " ";
  for (size_t j = 0; j < i - 1; ++j)
  {
    printFrameRectCoords(shapes[j]->getFrameRect());
    out << " ";
  }
  printFrameRectCoords(shapes[i - 1]->getFrameRect());
  out << "\n";
  out.copyfmt(stream);
}

void abramov::scaleFigure(Shape *s, const point_t &p, double k)
{
  const point_t pos1 = s->getFrameRect().pos;
  s->move(p);
  const point_t pos2 = s->getFrameRect().pos;
  double dx = pos2.x - pos1.x;
  double dy = pos2.y - pos1.y;
  s->scaleSafe(k);
  dx *= -1 * k;
  dy *= -1 * k;
  s->move(dx, dy);
}

void abramov::scaleFigures(Composite &shapes, const point_t &p, double k, size_t i)
{
  if (k <= 0)
  {
    throw std::logic_error("There is incorrect coef\n");
  }
  for (size_t j = 0; j < i; ++j)
  {
    scaleFigureUnsafe(shapes[j], p, k);
  }
}

void abramov::scaleFigureUnsafe(Shape *s, const point_t &p, double k)
{
  const point_t pos1 = s->getFrameRect().pos;
  s->move(p);
  const point_t pos2 = s->getFrameRect().pos;
  double dx = pos2.x - pos1.x;
  double dy = pos2.y - pos1.y;
  s->scale(k);
  dx *= -1 * k;
  dy *= -1 * k;
  s->move(dx, dy);
}
