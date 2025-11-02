/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>

bool IsUpperCase(char chr) {
   return chr >= 'A' && chr <= 'Z';
}

char ToLowerCase(char chr) {
   constexpr char TO_LOWER = 'a' - 'A';

   // Yo lo haría con una ternaria
   // return IsUpperCase(chr) ? chr + TO_LOWER : chr;

   char lower_chr = chr;

   if (IsUpperCase(chr)) {
      lower_chr = lower_chr + TO_LOWER;
   }

   return lower_chr;
}

int main() {
   char chr;

   std::cout << "Introduce a character: ";
   std::cin >> chr;

   char modified_chr = ToLowerCase(chr);

   std::cout << "Character in lowercase is " << modified_chr << "\n";
}