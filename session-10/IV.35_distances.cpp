/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>

int main() {
   constexpr int MAX_MATRIX_SIZE = 50;

   double distance_matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
   int size;

   std::cout << "Insert the matrix size: ";
   std::cin >> size;

   if (size > MAX_MATRIX_SIZE) {
      std::cout << "The maximum size is 50\n";
      size = MAX_MATRIX_SIZE;
   }

   std::cout << "Fill the matrix:\n";

   // Fill the diagonal with 0
   for (int i = 0; i < size; i++) {
      distance_matrix[i][i] = 0.0;
   }

   // Fill the rest of the matrix
   for (int i = 0; i < size - 1; i++) {
      for (int j = i + 1; j < size; j++) {
         int distance;
         std::cin >> distance;

         distance_matrix[i][j] = distance;
         distance_matrix[j][i] = distance;
      }
   }

   // To find the city with most connections we can just find the column (or row because of simetry)
   // that has more non 0 values

   int max_conection_count = -1;
   int max_connected_city = 0;

   for (int i = 0; i < size; i++) {
      int connection_count = 0;

      for (int j = 0; j < size; j++) {
         if (distance_matrix[i][j] != 0) {
            connection_count++;
         }
      }

      if (connection_count > max_conection_count) {
         max_conection_count = connection_count;
         max_connected_city = i;
      }
   }

   std::cout << "The most connected city is " << max_connected_city << " with " << max_conection_count
             << " connections.\n";

   return 0;
}