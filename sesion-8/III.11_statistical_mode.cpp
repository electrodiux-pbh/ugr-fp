/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>

constexpr int MAX_STRING_SIZE = 1024;
constexpr char NULL_TERMINATOR = '\0';

void StatisticalMode(char str[], int& count, char& chr) {
   constexpr int BUFFER_CAPACITY = 256; // 1 byte is 256 combinations

   int frequency_list[BUFFER_CAPACITY];

   // Set the frequency to 0

   for (int i = 0; i < BUFFER_CAPACITY; i++) {
      frequency_list[i] = 0;
   }

   // Count the number of each character's apparience

   bool found_null_terminator = false;

   for (int i = 0; !found_null_terminator && i < MAX_STRING_SIZE; i++) {
      char chr = str[i];

      found_null_terminator = chr == NULL_TERMINATOR;

      if (!found_null_terminator && chr >= 0) {
         // Increment that place in the list
         frequency_list[chr]++;
      }
   }

   // Get the biggest number in the frequency_list

   count = 0;

   for (int i = 0; i < BUFFER_CAPACITY; i++) {
      int chr_count = frequency_list[i];

      if (chr_count > count) {
         count = chr_count;
         chr = static_cast<char>(i);
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

   std::cout << "Message\n";
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
   StatisticalMode(str, count, chr);

   std::cout << "The statistical mode of " << "\"" << str << "\"";
   std::cout << " is '" << chr << "' a total of " << count << " times.\n";

   return 0;
}