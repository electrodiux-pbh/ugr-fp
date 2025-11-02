/**
 * @author Pablo Bermejo Hernandez
 */

#include <cmath>
#include <iostream>

double PorcentualVariation(int a, int b) {
   return std::abs((b - a) / static_cast<double>(a));
}

double Elasticity(int price1, int sales1, int price2, int sales2) {
   return PorcentualVariation(sales1, sales2) / PorcentualVariation(price1, price2);
}

int main() {
   int price1, price2;
   int sales1, sales2;

   bool should_exit = false;

   while (!should_exit) {

      std::cout << "Introduce price 1: ";
      std::cin >> price1;
      should_exit = price1 < 0;

      if (!should_exit) {
         std::cout << "Introduce price 2: ";
         std::cin >> price2;

         std::cout << "Introduce sales 1: ";
         std::cin >> sales1;

         std::cout << "Introduce sales 2: ";
         std::cin >> sales2;

         double epd = Elasticity(price1, sales1, price2, sales2);

         std::cout << "The EPD is " << epd << "\n";
      }
   }
}