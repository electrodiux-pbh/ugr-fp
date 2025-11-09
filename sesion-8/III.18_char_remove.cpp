/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>

bool IsIgnoreCharacter(char chr) {
   return chr == '\n' || chr == '\t' || chr == '\r';
}

void ReadCharArray(char str[], int capacity, int& lenght, char terminator) {
   constexpr char NULL_TERMINATOR = '\0';

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

int main() {
   constexpr char TERMINATOR = '#';
   constexpr int MAX_STRING_SIZE = 1000;

   char str[MAX_STRING_SIZE];
   int str_len;
   std::cout << "Introduce the message: ";
   ReadCharArray(str, MAX_STRING_SIZE, str_len, TERMINATOR);

   char to_erase;
   std::cout << "Introduce the char to erase: ";
   std::cin >> to_erase;

   for (int i = 0; i < str_len; i++) {
      if (str[i] == to_erase) {
         // Less equal to also move the null character
         for (int j = i + 1; j <= str_len; j++) {
            str[j - 1] = str[j];
         }
         // Move the index with the shift
         i--;
         // Modify the str_len to the shifted value
         str_len--;
      }
   }

   if (str_len != 0) {
      std::cout << str << "\n";
   } else {
      std::cout << "The string is empty\n";
   }

   return 0;
}