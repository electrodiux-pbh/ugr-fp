/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>
#include <string>

struct TimeStamp {
   int hours, minutes, seconds;
};

constexpr int SECONDS_PER_MINUTE = 60;
constexpr int MINUTES_PER_HOUR = 60;
constexpr int SECONDS_PER_HOUR = SECONDS_PER_MINUTE * MINUTES_PER_HOUR;

TimeStamp ReadTimeStamp(const std::string& stamp_name) {
   TimeStamp time_stamp;

   std::cout << "Introduce " << stamp_name << " time-stamp \"hours minutes seconds\"\n";

   std::cin >> time_stamp.hours;
   std::cin >> time_stamp.minutes;
   std::cin >> time_stamp.seconds;

   return time_stamp;
}

int ToSeconds(const TimeStamp& t) {
   return t.seconds + t.minutes * SECONDS_PER_MINUTE + t.hours * SECONDS_PER_HOUR;
}

// Lo mejor sería definir el operador < en TimeStamp y usar ese operador
bool GreaterThan(const TimeStamp& t1, const TimeStamp& t2) {
   return ToSeconds(t1) > ToSeconds(t2);
}

int main() {

   TimeStamp time_1 = ReadTimeStamp("first");
   TimeStamp time_2 = ReadTimeStamp("second");

   if (GreaterThan(time_1, time_2)) {
      std::cout << "First time-stamp is greater than the second.";
   } else {
      std::cout << "First time-stamp is lower or equal than the second.";
   }
}