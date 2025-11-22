/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>

bool IsSorted(int v[], int size) {
   bool sorted = true;

   for (int i = 1; i < size && sorted; i++) {
      if (v[i - 1] > v[i]) {
         sorted = false;
      }
   }

   return sorted;
}

void SortReflex(int v[], int size) {
   while (!IsSorted(v, size)) {
      for (int i = 1; i < size; i++) {
         int i_prev = i - 1;
         if (v[i_prev] > v[i]) {
            // Swap values
            // Yo usaría directamente std swap, pero lo implemento a mano
            // std::swap(v[i], v[i_prev]);
            int vi_value = v[i];
            v[i] = v[i_prev];
            v[i_prev] = vi_value;
         }
      }
   }
}

int NumberFromDigits(int digits[], int size) {
   int num = 0;

   for (int i = 0; i < size; i++) {
      num *= 10;
      num += digits[i];
   }

   return num;
}

int main() {
   /*
   Explicación:

   Vector original: v = [2, 1, 4, 2, 8, 5], util = 6, k = 4

   Paso 1: Ordenar (ya que cuanto más pequeño el primer número mejor)
   v = [1, 2, 2, 4, 5, 8]

   Paso 2: Construir número con los k=4 primeros elementos
   (Siempre multiplicamos *10 como si movieramos todos los números,
   y sumamos la cifra final como si la pusieramos)

   n = 0
   i=0: n = 0 * 10 + 1 = 1
   i=1: n = 1 * 10 + 2 = 12
   i=2: n = 12 * 10 + 2 = 122
   i=3: n = 122 * 10 + 4 = 1224
   */

   int size;

   std::cout << "Enter array size: ";
   std::cin >> size;

   int digits[size];

   std::cout << "Enter " << size << " numbers:\n";

   for (int i = 0; i < size;) {
      int digit;
      std::cin >> digit;

      if (digit >= 0 && digit <= 9) {
         digits[i] = digit;
         i++;
      }
   }

   int digit_count;
   std::cout << "Enter digits: ";
   std::cin >> digit_count;

   constexpr int NUMBER_BASE = 10;

   int digits_count[NUMBER_BASE];

   // Initialize to 0
   for (int i = 0; i < size; i++) {
      digits_count[i] = 0;
   }

   // Count all the digits
   for (int i = 0; i < size; i++) {
      digits_count[i]++;
   }

   int number = 0;

   // Create the number
   for (int i = 0; i < digit_count; i++) {
      number *= NUMBER_BASE;

      bool digit_found = false;

      for (int j = 0; j < NUMBER_BASE && !digit_found; j++) {
         if (digits_count[j] > 0) {
            number += j;
            digit_found = true;
            digits_count[j]--;
         }
      }
   }

   std::cout << "The minimum number you can achieve is " << number << "\n";
}