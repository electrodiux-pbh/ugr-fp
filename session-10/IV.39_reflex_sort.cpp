/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>

int ReflexNumber(int num, int base = 10) {
   int reflex = 0;

   while (num != 0) {
      reflex *= base;
      reflex += num % base;
      num /= base;
   }

   return reflex;
}

void Swap(int& a, int& b) {
   int temp = b;
   b = a;
   a = temp;
}

void SortReflex(int array[], int size) {
   int reflex_array[size];

   // I only calculate the reflex number once
   for (int i = 0; i < size; i++) {
      reflex_array[i] = ReflexNumber(array[i]);
   }

   for (int i = 1; i < size; i++) {
      for (int j = i; j > 0 && reflex_array[j] < reflex_array[j - 1]; j--) {
         Swap(array[j], array[j - 1]);
         Swap(reflex_array[j], reflex_array[j - 1]);
      }
   }
}

void PrintArray(const int array[], int size) {
   std::cout << "[";
   for (int i = 0; i < size; i++) {
      std::cout << array[i];
      if (i < size - 1) {
         std::cout << ", ";
      }
   }
   std::cout << "]";
}

int main() {
   // Test case
   int v[] = {900, 23, 90, -25, 105, 14};
   int size = sizeof(v) / sizeof(int);

   std::cout << "Pre sort: ";
   PrintArray(v, size);
   std::cout << "\n";

   SortReflex(v, size);

   std::cout << "After sort: ";
   PrintArray(v, size);
   std::cout << "\n";
}