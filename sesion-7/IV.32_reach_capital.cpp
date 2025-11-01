/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>

int PeriodsToTargetCapital(double interest, double initial_capital, double target_capital, double& final_capital) {
   int periods = 0;

   if (interest > 0) {
      const double interest_fraction = interest / 100.0;

      final_capital = initial_capital;

      while (final_capital < target_capital) {
         final_capital += final_capital * interest_fraction;
         periods++;
      }
   }

   return periods;
}

double ReadGreaterThan(double threshold, const std::string& msg) {

   double value;

   do {
      std::cout << msg;
      std::cin >> value;
   } while (value <= threshold);

   return value;
}

double ReadCapital() { return ReadGreaterThan(0, "Introduce the initial capital: "); }

double ReadInterest() { return ReadGreaterThan(0, "Introduce the interest rate (yearly): "); }

constexpr int FINAL_CAPITAL_MULTIPLIER = 2;

int main() {

   double capital = ReadCapital();
   double interest = ReadInterest();

   double final_capital;
   int years = PeriodsToTargetCapital(interest, capital, capital * FINAL_CAPITAL_MULTIPLIER, final_capital);

   std::cout << "Number of years: " << years << "\n";
   std::cout << "Final gained capital: " << final_capital << "\n";

   return 0;
}