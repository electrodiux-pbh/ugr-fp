/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>

constexpr char NULL_TERMINATOR = '\0';

void ReadCharArray(char str[], int capacity, int& lenght, char terminator) {

   // Reserve space for the null-character
   capacity -= 1;

   lenght = 0;
   bool found_terminator = false;

   do {
      char chr = std::cin.get();

      found_terminator = chr == terminator;

      if (!found_terminator) {
         str[lenght] = chr;
         lenght++;
      }

   } while (lenght < (capacity - 1) && !found_terminator);

   // Set the null terminator at the end of the string
   str[lenght] = NULL_TERMINATOR;
}

void RemoveCharacterFromBuffer(char text[], int& text_len, char chr) {
   int new_len = text_len;
   int write_index = 0;

   for (int i = 0; i < text_len; i++) {
      text[write_index] = text[i];

      if (text[i] != chr) {
         write_index++;
      } else {
         new_len--;
      }
   }

   text_len = new_len;
   text[new_len] = NULL_TERMINATOR;
}

int main() {
   constexpr int MAX_BUFFER_CAPACITY = 20000000;
   constexpr char TERMINATOR = '#';

   char* text = new char[MAX_BUFFER_CAPACITY];
   int text_len;

   ReadCharArray(text, MAX_BUFFER_CAPACITY, text_len, TERMINATOR);

   char chr_to_remove = std::cin.get();

   RemoveCharacterFromBuffer(text, text_len, chr_to_remove);

   std::cout << text;

   return 0;
}