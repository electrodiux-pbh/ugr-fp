/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>

bool IsPalindrome(char str[], int size) {
   int half_size = size / 2;

   bool is_palindrome = true;

   for (int i = 0; i < half_size && is_palindrome; i++) {
      if (str[i] != str[size - i - 1]) {
         is_palindrome = false;
         // Instead of the is_palindrome condition I would use a break statement
         // In this scenario
      }
   }

   return is_palindrome;
}

void Swap(char& x0, char& x1) {
   char x1_value = x1;
   x1 = x0;
   x0 = x1_value;
}

void Invert(char str[], int size) {
   int half_size = size / 2;

   bool is_palindrome = true;

   for (int i = 0; i < half_size && is_palindrome; i++) {
      Swap(str[i], str[size - i - 1]);
   }
}

bool IsIgnoreCharacter(char chr) {
   return chr == '\n' || chr == '\t' || chr == '\r';
}

void ReadCharArray(char str[], int capacity, int& size, char terminator, bool null_terminated = true) {

   if (null_terminated) {
      // Reserve space for the null-character
      terminator -= 1;
   }

   size = 0;
   bool found_terminator = false;

   do {
      char chr = std::cin.get();

      if (!IsIgnoreCharacter(chr)) {
         found_terminator = chr == terminator;

         if (!found_terminator) {
            str[size] = chr;
            size++;
         }
      }
   } while (size < (capacity - 1) && !found_terminator);

   constexpr char NULL_TERMINATOR = '\0';

   if (null_terminated) {
      str[size] = NULL_TERMINATOR;
   }
}

int main() {
   constexpr int BUFFER_CAPACITY = 100;
   constexpr char TERMINATOR = '#';

   char str[BUFFER_CAPACITY];
   int str_size = 0;

   ReadCharArray(str, BUFFER_CAPACITY, str_size, TERMINATOR);

   bool is_palindrome = IsPalindrome(str, str_size);

   if (!is_palindrome) {
      Invert(str, str_size);
   }

   if (IsPalindrome(str, str_size)) {
      std::cout << "The string \"" << str << "\" is a palindrome.\n";
   } else {
      std::cout << "The string is not a palindrome.\n";
      std::cout << "The inverted string is: " << str << "\n";
   }
}