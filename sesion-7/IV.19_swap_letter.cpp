/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>

bool IsUpperCase(char chr) {
   return chr >= 'A' && chr <= 'Z';
}

bool IsLowerCase(char chr) {
   return chr >= 'a' && chr <= 'z';
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

char ToUpperCase(char chr) {
   constexpr char TO_UPPER = 'A' - 'a';

   // Yo lo haría con una ternaria
   // return IsLowerCase(chr) ? chr + TO_UPPER : chr;

   char lower_chr = chr;

   if (IsLowerCase(chr)) {
      lower_chr = lower_chr + TO_UPPER;
   }

   return lower_chr;
}

char SwapCapitalization(char chr) {
   char swapped_chr = chr;

   if (IsUpperCase(chr)) {
      swapped_chr = ToLowerCase(chr);
   } else if (IsLowerCase(chr)) {
      swapped_chr = ToUpperCase(chr);
   }

   return swapped_chr;
}

int main() {
   char chr;

   std::cout << "Introduce a character: ";
   std::cin >> chr;

   char modified_chr = SwapCapitalization(chr);

   std::cout << "Character with swapped capitalization is " << modified_chr << "\n";
}