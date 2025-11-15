/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>

constexpr int MAX_STRING_SIZE = 1024;
constexpr char NULL_TERMINATOR = '\0';

int CountCharacterOccurrences(char str[], int beggin, int str_len, char chr) {
   int count = 0;

   for (int i = beggin; i < str_len; i++) {
      if (str[i] == chr) {
         count++;
      }
   }

   return count;
}

void StatisticalMode(char str[], int str_len, int& mode_count, char& mode_chr) {
   constexpr int BUFFER_CAPACITY = 1000;

   char processed_list[BUFFER_CAPACITY];
   int processed_size = 0;

   for (int i = 0; i < BUFFER_CAPACITY; i++) {
      processed_list[i] = 0;
   }

   mode_count = 0;

   for (int i = 0; i < str_len; i++) {
      char chr = str[i];

      bool was_processed = false;

      // Search chr in processed
      for (int i = 0; i < processed_size && !was_processed; i++) {
         was_processed = processed_list[i] == chr;
      }

      if (!was_processed) {
         int occurrences = CountCharacterOccurrences(str, i, str_len, str[i]);

         // Add to the processed list
         if (processed_size < BUFFER_CAPACITY) {
            processed_list[processed_size] = chr;
            processed_size++;
         }

         if (occurrences > mode_count) {
            mode_count = occurrences;
            mode_chr = str[i];
         }
      }
   }
}

bool IsIgnoreCharacter(char chr) {
   return chr == '\n' || chr == '\t' || chr == '\r';
}

void ReadCharArray(char str[], int capacity, int& lenght, char terminator) {

   // Reserve space for the null-character
   capacity -= 1;

   lenght = 0;
   bool found_terminator = false;

   std::cout << "Introduce a message using '" << terminator << "' as terminator.";
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

int main() {
   constexpr char TERMINATOR = '#';

   char str[MAX_STRING_SIZE];
   int str_len;
   ReadCharArray(str, MAX_STRING_SIZE, str_len, TERMINATOR);

   int count;
   char chr;
   StatisticalMode(str, str_len, count, chr);

   std::cout << "The statistical mode of " << "\"" << str << "\"";
   std::cout << " is '" << chr << "' a total of " << count << " times.\n";

   return 0;
}