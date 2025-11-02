/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>
#include <string>

struct NumericInterval {
   int min;
   bool min_inclusive = true;

   int max;
   bool max_inclusive = true;
};

int ReadNumberInRange(const NumericInterval& interval, const std::string& msg) {

   bool is_input_valid;

   int value;

   do {
      std::cout << msg;
      std::cin >> value;

      bool over_min = (value > interval.min) || (interval.min_inclusive && value >= interval.min);
      bool under_max = (value < interval.max) || (interval.max_inclusive && value <= interval.max);

      is_input_valid = over_min && under_max;

      if (!is_input_valid) {
         std::cout << "Number is out of range.\n";
      }
   } while (!is_input_valid);

   return value;
}

int ReadGreaterThan(int threshold, const std::string& msg, const std::string& err_msg) {

   int value;
   bool is_input_invalid;

   do {
      std::cout << msg;
      std::cin >> value;

      is_input_invalid = value <= threshold;

      if (is_input_invalid) {
         std::cout << err_msg << "\n";
      }
   } while (is_input_invalid);

   return value;
}

NumericInterval ReadInterval() {
   constexpr bool IS_INTERVAL_INCLUSIVE = true;

   int min, max;

   std::cout << "Introduce the interval min: ";
   std::cin >> min;

   max = ReadGreaterThan(min, "Introduce the interval max: ", "Max value must be greater than min.");

   /*
   Es posible cambiar esta función para recibir una expresión de intervalo y parsearla correctamente
   con diferentes tipos de intervalos, por ahora solo lee intervalos cerrados.
   */

   // Ops esta inicialización es de C++20, la cambio por la de C++11
   // return NumericInterval{
   //     .min = min,
   //     .min_inclusive = IS_INTERVAL_INCLUSIVE,
   //     .max = max,
   //     .max_inclusive = IS_INTERVAL_INCLUSIVE,
   // };

   return NumericInterval{min, IS_INTERVAL_INCLUSIVE, max, IS_INTERVAL_INCLUSIVE};
}

std::string IntervalToString(const NumericInterval& interval) {
   std::string str;

   str += interval.min_inclusive ? '[' : ')';
   str += std::to_string(interval.min);
   str += ", ";
   str += std::to_string(interval.max);
   str += interval.max_inclusive ? ']' : ')';

   return str;
}

constexpr int NUMBER_OF_ITERATIONS = 3;

int main() {
   NumericInterval interval = ReadInterval();

   std::cout << "Reading " << NUMBER_OF_ITERATIONS << " numbers in the range and printing the sum\n";

   int sum = 0;

   std::string message = "Introduce a number in interval " + IntervalToString(interval) + ": ";

   for (int i = 0; i < NUMBER_OF_ITERATIONS; ++i) {
      int value = ReadNumberInRange(interval, message);
      sum += value;
   }

   std::cout << "The total sum is " << sum << "\n";

   return 0;
}