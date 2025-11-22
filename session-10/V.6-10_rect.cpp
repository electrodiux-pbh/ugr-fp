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

      if (IsValid(a, b)) {
         m_a = a;
         m_b = b;
      }
   }

   double Slope() const {
      return m_b == 0.0 ? INFINITY : -m_a / m_b;
   }

   double Ordinate(double x) const {
      return m_b == 0.0 ? INFINITY : (-m_c - x * m_a) / m_b;
   }

   double Abscissa(double y) const {
      return m_a == 0.0 ? INFINITY : (-m_c - y * m_b) / m_a;
   }

   double AngleRadWithXAxis() const {
      constexpr double PI = 3.14159265;
      double slope = Slope();
      return slope == INFINITY ? PI / 2.0 : std::atan(slope);
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

   void SetCoefficients(double a, double b, double c) {
      if (IsValid(a, b)) {
         m_a = a;
         m_b = b;
      }
      m_c = c;
   }

   void SetA(double a) {
      if (IsValid(a, m_b)) {
         m_a = a;
      }
   }

   void SetB(double b) {
      if (IsValid(m_a, b)) {
         m_b = b;
      }
   }

   void SetC(double c) {
      m_c = c;
   }

 private:
   bool IsValid(double a, double b) {
      return a != 0.0 || b != 0.0;
   }
};

Rect ReadRect() {
   double a, b, c;

   std::cout << "Introduce a rect quoeficients (A, B, C): ";

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