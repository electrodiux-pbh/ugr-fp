/**
 * @author Pablo Bermejo Hernandez
 */

class CharSequence {
 private:
   static constexpr int CAPACITY = 100;

   char m_chars[CAPACITY];
   int m_lenght;

 public:
   CharSequence(); // To initialize m_chars and m_lenght

   // To insert a character at the end
   void InsertBack(char chr);

   // Insert a char sequence at the end
   void InsertBack(const CharSequence& seq);

   // To remove last char
   void Pop();

   // To get the lenght of the char sequence
   int Lenght() const;

   // To mirror all characters "Hello World" -> "dlroW olleH"
   void Mirror();

   // Find the index of the first char if it appears, return an unvalid value like -1 otherwise
   int FirstCharIndex(char chr) const;

   // Erase the character in the sequence "Hello World" without 'l' -> "Heo Word"
   void EraseCharacter(char chr_to_remove);

   // Shift the characters in the sequence right by n
   void ShiftRight(int n);

   // Shift the characters in the sequence left by n
   void ShiftLeft(int n);

   // Check if a sequence is contained inside another
   bool IsContained(const CharSequence& seq) const;

   bool Equals(const CharSequence& seq) const;

   bool EqualsIgnoreCase(const CharSequence& seq) const;

   void ToLowerCase() const;

   void ToUpperCase() const;
};