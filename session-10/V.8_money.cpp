/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>
#include <string>

class Money {
 private:
   long long m_eur = 0;
   long long m_cent = 0;

 public:
   Money() : m_eur(0), m_cent(0) {}

   Money(long long eur, long long cent) {
      SetValue(eur, cent);
   }

   void IncreaseBalance(const Money& transaction_amount) {
      SetValue(m_eur + transaction_amount.m_eur, m_cent + transaction_amount.m_cent);
   }

   void DeductBalance(const Money& transaction_amount) {
      SetValue(m_eur - transaction_amount.m_eur, m_cent - transaction_amount.m_cent);
   }

   void SetValue(long long eur, long long cent) {
      m_cent = cent % 100;
      m_eur = eur + (cent / 100);
   }

   long long GetEuro() const {
      return m_eur;
   }

   long long GetCent() const {
      return m_cent;
   }

   std::string ToString() const {
      std::string str_value;
      str_value += std::to_string(GetEuro());
      str_value += '.';
      str_value += std::to_string(GetCent());
      str_value += "€";

      return str_value;
   }

   /*
   We could also define custom operators (not requested)
   */

   Money operator+(const Money& other) {
      return Money(m_eur + other.m_eur, m_cent + other.m_cent);
   }

   Money operator-(const Money& other) {
      return Money(m_eur - other.m_eur, m_cent - other.m_cent);
   }

   Money& operator+=(const Money& other) {
      IncreaseBalance(other);
      return *this;
   }

   Money& operator-=(const Money& other) {
      DeductBalance(other);
      return *this;
   }

   bool operator==(const Money& other) {
      return m_eur == other.m_eur && m_cent == other.m_cent;
   }

   bool operator!=(const Money& other) {
      return !(*this == other);
   }
};

Money ReadMoney() {
   long long eur, cent;
   std::cin >> eur >> cent;

   return Money(eur, cent);
}

int main() {
   Money money1 = ReadMoney();
   Money money2 = ReadMoney();

   // Without custom operators:
   Money total_money = money1;
   total_money.IncreaseBalance(money2);

   // With custom operators:
   // Money total_money = money1 + money2;

   std::cout << "The total balance is " << total_money.ToString() << "\n";
}