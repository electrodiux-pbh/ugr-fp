/**
 * @author Pablo Bermejo Hernandez
 */

#include <ios>
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
            int vi_value = v[i];
            v[i] = v[i_prev];
            v[i_prev] = vi_value;
         }
      }
   }
}

constexpr int MAX_PERMUTATION_SIZE = 1000;

/**
 * This function checks if the function is a permutation of
 * I = { 0, 1, 2, ..., n - 1 } with n the size of the array
 */
bool IsPermutation1(int array[], int size) {
   SortReflex(array, size);

   bool is_permutation = true;

   for (int i = 0; i < size && is_permutation; i++) {
      if (array[i] != i) {
         is_permutation = false;
      }
   }

   return is_permutation;
}

/**
 * This function checks if the function is a permutation of
 * I = { 0, 1, 2, ..., n - 1 } with n the size of the array
 */
bool IsPermutation2(int array[], int size) {

   bool is_contained[MAX_PERMUTATION_SIZE];

   // Since we can not use dynamic arrays, has a size limit
   if (size > MAX_PERMUTATION_SIZE) {
      size = MAX_PERMUTATION_SIZE;
   }

   // Set everything to false
   for (int i = 0; i < size; i++) {
      is_contained[i] = false;
   }

   bool can_be_permutation = true;

   for (int i = 0; i < size && can_be_permutation; i++) {
      int number = array[i];

      if (number >= 0 && number < size && !is_contained[number]) {
         is_contained[number] = true;
      } else {
         // Cannot be a permutation (the number is out of bounds or is duplicated)
         can_be_permutation = false;
      }
   }

   if (can_be_permutation) {
      for (int i = 0; i < size && can_be_permutation; i++) {
         if (!is_contained[i]) {
            can_be_permutation = false;
         }
      }
   }

   return can_be_permutation;
}

void PrintPermutation(int perm[], int size) {
   std::cout << "{ ";

   for (int i = 0; i < size; i++) {
      std::cout << perm[i];
      if (i < size - 1) {
         std::cout << ", ";
      }
   }

   std::cout << " }";
}

int main() {

   int perm[MAX_PERMUTATION_SIZE];
   int size = 0;

   bool continue_input = true;

   std::cout << "Introduce the numbers of the permutation, to finalize insert -1:\n";

   do {
      int number;
      std::cin >> number;

      continue_input = number != -1 && size < MAX_PERMUTATION_SIZE - 1;

      if (continue_input) {
         perm[size] = number;
         size++;
      }
   } while (continue_input);

   std::cout << "Is ";
   PrintPermutation(perm, size);
   std::cout << " a permutation?:\n";

   bool is_perm_1 = IsPermutation1(perm, size);
   bool is_perm_2 = IsPermutation2(perm, size);

   std::cout << "- Algorithim 1: " << std::boolalpha << is_perm_1 << "\n";
   std::cout << "- Algorithim 2: " << std::boolalpha << is_perm_2 << "\n";

   return 0;
}