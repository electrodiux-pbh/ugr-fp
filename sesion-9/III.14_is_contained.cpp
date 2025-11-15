/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>

constexpr char NULL_TERMINATOR = '\0';

bool IsIgnoreCharacter(char chr) {
   return chr == '\n' || chr == '\t' || chr == '\r';
}

void ReadCharArray(char str[], int capacity, int& lenght, char terminator) {

   // Reserve space for the null-character
   capacity -= 1;

   lenght = 0;
   bool found_terminator = false;

   do {
      char chr = std::cin.get();

      if (!IsIgnoreCharacter(chr)) {
         found_terminator = chr == terminator;

         if (!found_terminator) {
            str[lenght] = chr;
            lenght++;
         }
      }
   } while (lenght < (capacity - 1) && !found_terminator);

   // Set the null terminator at the end of the string
   str[lenght] = NULL_TERMINATOR;
}

bool IsContained(char src[], int src_len, char vec[], int vec_len) {

   int lookup_index = 0;
   bool is_contained = false;

   for (int i = 0; i < src_len && !is_contained; i++) {
      if (src[i] == vec[lookup_index]) {
         is_contained = lookup_index >= vec_len - 1;
         lookup_index++;
      }
   }

   return is_contained;
}

int main() {
   constexpr int MAX_BUFFER_CAPACITY = 1000;
   constexpr char TERMINATOR = '#';

   char main_array[MAX_BUFFER_CAPACITY];
   int main_arr_len;

   char secondary_array[MAX_BUFFER_CAPACITY];
   int secondary_arr_len;

   ReadCharArray(main_array, MAX_BUFFER_CAPACITY, main_arr_len, TERMINATOR);
   ReadCharArray(secondary_array, MAX_BUFFER_CAPACITY, secondary_arr_len, TERMINATOR);

   if (IsContained(main_array, main_arr_len, secondary_array, secondary_arr_len)) {
      std::cout << "It is contained!\n";
   } else {
      std::cout << "It is not contained :(\n";
   }

   return 0;
}