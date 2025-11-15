/**
 * @author Pablo Bermejo Hernandez
 */

#include <cmath>
#include <iostream>

class Rect {
 private:
   double m_a, m_b, m_c;

 public:
   Rect() : m_a(1.0), m_b(1.0), m_c(0.0) {}

   Rect(double a, double b, double c) : Rect() {
      m_c = c;

      /*
      Nota:
      Se podría utilizar exceptiones, asserts u un estado inválido del objeto
      por simplicidad he decidido que se inicialize con los valores del
      constructor por defecto, si a y b son correctos se sobreescriben
      si no se ignoran.
      */

      // Prevent a == 0 && b == 0 at the same time
      if (a != 0.0 || b != 0.0) {
         m_a = a;
         m_b = b;
      }
   }

   double Slope() const {
      return -m_a / m_b;
   }

   double Ordinate(double x) const {
      return (-m_c - x * m_a) / m_b;
   }

   double Abscissa(double y) const {
      return (-m_c - y * m_b) / m_a;
   }

   double AngleRadWithXAxis() const {
      return std::atan(Slope());
   }

   void Reflex() {
      m_b = -m_b;
   }

   double GetA() const {
      return m_a;
   }

   double GetB() const {
      return m_b;
   }

   double GetC() const {
      return m_c;
   }
};

Rect ReadRect() {
   double a, b, c;

   std::cin >> a;
   std::cin >> b;
   std::cin >> c;

   return Rect(a, b, c);
}

void PrintPoint(double x, double y) {
   std::cout << "The point is (" << x << ", " << y << ")\n";
}

int main() {
   Rect rect1 = ReadRect();
   Rect rect2 = ReadRect();

   std::cout << "C rect1 is " << rect1.GetC() << "\n";
   std::cout << "C rect2 is " << rect2.GetC() << "\n";

   std::cout << "Slope rect1 is " << rect1.Slope() << "\n";
   std::cout << "Slope rect2 is " << rect2.Slope() << "\n";

   std::cout << "Angle rect1 is " << rect1.AngleRadWithXAxis() << "\n";
   std::cout << "Angle rect2 is " << rect2.AngleRadWithXAxis() << "\n";

   double abscissa, ordinate;

   std::cout << "Enter an abscissa point: ";
   std::cin >> abscissa;
   PrintPoint(abscissa, rect1.Ordinate(abscissa));

   std::cout << "Enter an ordinate point: ";
   std::cin >> ordinate;
   PrintPoint(rect1.Abscissa(ordinate), ordinate);

   rect1.Reflex();
   std::cout << "The slope of rect1 after reflex is " << rect1.Slope() << "\n";
}