/**
 * @author Pablo Bermejo Hernandez
 */

#include <chrono>
#include <cmath>
#include <iostream>

class Chronometer {
 private:
   typedef std::chrono::time_point<std::chrono::steady_clock> timestamp_t;
   typedef std::chrono::duration<long long, std::nano> time_interval_t;

   timestamp_t inicio;
   timestamp_t final;

 public:
   void Reset() {
      inicio = std::chrono::steady_clock::now();
   }

   long long ElapsedNanoseconds() {
      final = std::chrono::steady_clock::now();
      time_interval_t diferencia = final - inicio;

      return diferencia.count();
   }

   long long ElapsedMilliseconds() {
      constexpr long long NANOS_PER_MILLISECOND = 1e6;
      return ElapsedNanoseconds() / NANOS_PER_MILLISECOND;
   }
};

// Code from session-6 II.31_pi_madhava.cpp
// (https://github.com/electrodiux-pbh/ugr-fp/blob/main/sesion-6/II.31_pi_madhava.cpp)

constexpr int ITER_MIN = 1;
constexpr int ITER_MAX = 100 * 1000;

constexpr double PI_CALCULATION_MULTIPLIER = 6.0;

int main() {
   Chronometer chrono;

   int iterations = 0;
   bool is_input_valid = false;

   do {
      std::cout << "Introduzca el número de iteraciones de la suma:\n";
      std::cin >> iterations;

      is_input_valid = iterations >= ITER_MIN && iterations <= ITER_MAX;

      if (!is_input_valid) {
         std::cout << "El número de iteraciones ha de estar en el rango ";
         std::cout << "[" << ITER_MIN << ", " << ITER_MAX << "]";
         std::cout << ", intentelo de nuevo.";
      }
   } while (!is_input_valid);

   double series_sum = 0;

   chrono.Reset();

   const double BASE = 1.0 / std::sqrt(3.0);

   for (int i = 0; i < iterations; ++i) {
      double pow_value = 1;

      int exp = 2 * i + 1;

      for (int j = 0; j < exp; ++j) {
         pow_value *= BASE;
      }

      double factor = (1.0 * pow_value) / (2.0 * i + 1.0);

      if (i % 2 == 0) {
         series_sum += factor;
      } else {
         series_sum -= factor;
      }
   }

   double pi = series_sum * PI_CALCULATION_MULTIPLIER;

   long long compute_time_ms = chrono.ElapsedMilliseconds();

   std::cout.precision(15);
   std::cout << "El valor aproximado de pi es " << pi << "\n";

   std::cout << "The total computational time was " << compute_time_ms << "ms\n";

   return 0;
}