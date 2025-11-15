/**
 * @author Pablo Bermejo Hernandez
 */

#include <iostream>

int ReadInRange(int min, int max) {
   int value;

   do {
      std::cin >> value;
   } while (value < min || value > max);

   return value;
}

// This is a solution using a vector (exercise 29)

// int main() {

//    constexpr int MAX_MATRIX_ROWS = 10;
//    constexpr int MAX_MATRIX_COLS = 10;

//    int mtrx[MAX_MATRIX_ROWS][MAX_MATRIX_COLS];

//    // Read matrix

//    int mtrx_rows;
//    int mtrx_cols;

//    std::cout << "Introduce matrix dimesions: ";

//    mtrx_rows = ReadInRange(1, MAX_MATRIX_ROWS);
//    mtrx_cols = ReadInRange(1, MAX_MATRIX_COLS);

//    std::cout << "Matrix dimensions: " << mtrx_rows << "x" << mtrx_cols << ".\n";

//    for (int r = 0; r < mtrx_rows; r++) {
//       for (int c = 0; c < mtrx_cols; c++) {
//          std::cin >> mtrx[r][c];
//       }
//    }

//    // Initialize row_minimums to the first element of each row
//    // and the row_minimums_cols to 0
//    int row_minimums[MAX_MATRIX_ROWS];
//    int row_minimums_cols[MAX_MATRIX_ROWS];

//    for (int r = 0; r < mtrx_rows; r++) {
//       row_minimums[r] = mtrx[r][0];
//       row_minimums_cols[r] = 0;
//    }

//    // For each row
//    for (int r = 0; r < mtrx_rows; r++) {

//       // Get the minimum
//       for (int c = 1; c < mtrx_cols; c++) {
//          int mtrx_value = mtrx[r][c];

//          if (mtrx_value < row_minimums[r]) {
//             row_minimums[r] = mtrx_value;
//             row_minimums_cols[r] = c;
//          }
//       }
//    }

//    // Initialize to the first element
//    int maximum = row_minimums[0];
//    int maximum_row = 0;
//    int maximum_col = row_minimums_cols[0];

//    // Search the maximum
//    for (int i = 1; i < mtrx_rows; i++) {
//       int value = row_minimums[i];

//       if (value > maximum) {
//          maximum = value;
//          maximum_row = i;
//          maximum_col = row_minimums_cols[i];
//       }
//    }

//    std::cout << "The maximum of the minimums of each row is ";
//    std::cout << maximum << " at position (" << maximum_row << ", " << maximum_col << ")\n";

//    return 0;
// }

// This is the efficient solution (without vector)

int main() {

   constexpr int MAX_MATRIX_ROWS = 10;
   constexpr int MAX_MATRIX_COLS = 10;

   int mtrx[MAX_MATRIX_ROWS][MAX_MATRIX_COLS];

   // Read matrix

   int mtrx_rows;
   int mtrx_cols;

   std::cout << "Introduce matrix dimesions: ";

   mtrx_rows = ReadInRange(1, MAX_MATRIX_ROWS);
   mtrx_cols = ReadInRange(1, MAX_MATRIX_COLS);

   std::cout << "Matrix dimensions: " << mtrx_rows << "x" << mtrx_cols << ".\n";

   for (int r = 0; r < mtrx_rows; r++) {
      for (int c = 0; c < mtrx_cols; c++) {
         std::cin >> mtrx[r][c];
      }
   }

   int maximum;
   int maximum_row;
   int maximum_col;

   // For each row
   for (int r = 0; r < mtrx_rows; r++) {
      int minimum = mtrx[r][0];
      int column = 0;

      // Search the minimum
      for (int c = 1; c < mtrx_cols; c++) {
         int mtrx_value = mtrx[r][c];

         if (mtrx_value < minimum) {
            minimum = mtrx_value;
            column = c;
         }
      }

      // If it is the first iteration (to initialize)
      // or if the minimum is greater than the maximum
      if (r == 0 || minimum > maximum) {
         // Overrite the maximum value
         maximum = minimum;
         maximum_row = r;
         maximum_col = column;
      }
   }

   std::cout << "The maximum of the minimums of each row is ";
   std::cout << maximum << " at position (" << maximum_row << ", " << maximum_col << ")\n";

   return 0;
}