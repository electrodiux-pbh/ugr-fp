/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>

int CollatzOrbit(int number) {

   int orbit = 0;

   while (number != 1) {

      if (number % 2 == 0) {
         number /= 2;
      } else {
         number = number * 3 + 1;
      }

      orbit++;
   }

   return orbit;
}

void MaxOrbitInRange(int min, int max, int& max_orbit, int& number) {

   for (int i = min; i <= max; ++i) {
      int orbit = CollatzOrbit(i);

      if (orbit > max_orbit) {
         max_orbit = orbit;
         number = i;
      }
   }
}

int ReadGreaterEqualThan(int threshold, const std::string& msg, const std::string& err_msg) {

   int value;
   bool is_input_invalid;

   do {
      std::cout << msg;
      std::cin >> value;

      is_input_invalid = value < threshold;

      if (is_input_invalid) {
         std::cout << err_msg << "\n";
      }
   } while (is_input_invalid);

   return value;
}

void ReadMinMax(int& min, int& max) {
   min = ReadGreaterEqualThan(0, "Introduce the interval min: ", "Min value must be positive.");
   max = ReadGreaterEqualThan(min, "Introduce the interval max: ", "Max value must be greater than min.");
}

int main() {

   int min, max;
   ReadMinMax(min, max);

   int number, max_orbit;
   MaxOrbitInRange(min, max, max_orbit, number);

   std::cout << "The number with biggest orbit in range ";
   std::cout << "[" << min << ", " << max << "]";
   std::cout << " is " << number << " with an orbit of " << max_orbit << "\n";

   return 0;
}