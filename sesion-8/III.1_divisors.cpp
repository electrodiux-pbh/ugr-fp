/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>

int ReadGreaterThan(int threshold, const std::string& msg, const std::string& err_msg) {
   int value;
   bool is_input_valid;

   do {
      std::cout << msg;
      std::cin >> value;

      is_input_valid = value > threshold;

      if (!is_input_valid) {
         std::cout << err_msg << "\n";
      }
   } while (!is_input_valid);

   return value;
}

int main() {

   int number = ReadGreaterThan(0, "Introduce a number greater than 0: ", "The value is incorrect, try again!");

   constexpr int DIVISOR_CAPACITY = 1000;
   int divisor_array[DIVISOR_CAPACITY];

   int divisor = 2;
   int last_divisor = number / 2;
   int index = 0;

   while (divisor <= last_divisor && index < DIVISOR_CAPACITY) {
      if (number % divisor == 0) {
         divisor_array[index] = divisor;
         index++;
      }

      divisor++;
   }

   std::cout << "The divisors of " << number << " are:\n";
   for (int i = 0; i < index; i++) {
      std::cout << divisor_array[i] << " ";
   }
   std::cout << "\n";

   return 0;
}