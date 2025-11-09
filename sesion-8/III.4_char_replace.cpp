/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>

bool IsIgnoreCharacter(char chr) {
   return chr == '\n' || chr == '\t' || chr == '\r';
}

void ReadCharArray(char str[], int capacity, int& lenght, char terminator) {

   lenght = 0;
   bool found_terminator = false;

   std::cout << "Introduce a string\n";
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

   constexpr char NULL_TERMINATOR = '\0';
   str[lenght] = NULL_TERMINATOR;
}

int CountChars(char str[], int size, char chr) {
   int count = 0;

   for (int i = 0; i < size; i++) {
      if (str[i] == chr) {
         count++;
      }
   }

   return count;
}

int main() {

   constexpr int BUFFER_CAPACITY = 100;
   constexpr char TERMINATOR = '#';

   char src_str[BUFFER_CAPACITY];
   int src_str_size = 0;

   char rplcmt_str[BUFFER_CAPACITY];
   int rplcmt_str_size = 0;

   ReadCharArray(src_str, BUFFER_CAPACITY, src_str_size, TERMINATOR);
   ReadCharArray(rplcmt_str, BUFFER_CAPACITY, rplcmt_str_size, TERMINATOR);

   char remove_chr;
   std::cin >> remove_chr;

   int matched_chars = CountChars(src_str, src_str_size, remove_chr);

   int dest_str_size = src_str_size + matched_chars * (rplcmt_str_size - 1);
   char dest_str[dest_str_size];

   // For each char in the original string
   for (int i = 0, j = 0; i < src_str_size; i++) {
      char chr = src_str[i];

      if (chr == remove_chr) {
         // Place the replacement string
         for (int k = 0; k < rplcmt_str_size; k++, j++) {
            dest_str[j] = rplcmt_str[k];
         }
      } else {
         // Add the current char
         dest_str[j] = chr;
         j++;
      }
   }

   std::cout << "The final string is: " << dest_str << "\n";

   return 0;
}