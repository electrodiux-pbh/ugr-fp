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

int main() {
   constexpr int MAX_MATRIX_1_ROWS = 10;
   constexpr int MAX_MATRIX_1_COLS = 10;
   constexpr int MAX_MATRIX_2_ROWS = 10;
   constexpr int MAX_MATRIX_2_COLS = MAX_MATRIX_1_ROWS;

   int mtrx1[MAX_MATRIX_1_ROWS][MAX_MATRIX_1_COLS];
   int mtrx2[MAX_MATRIX_2_ROWS][MAX_MATRIX_2_COLS];

   // Read first matrix

   int mtrx1_rows;
   int mtrx1_cols;

   mtrx1_rows = ReadInRange(1, MAX_MATRIX_1_ROWS);
   mtrx1_cols = ReadInRange(1, MAX_MATRIX_1_COLS);

   std::cout << "Matrix 1 dimensions: " << mtrx1_rows << "x" << mtrx1_cols << ".\n";

   for (int r = 0; r < mtrx1_rows; r++) {
      for (int c = 0; c < mtrx1_cols; c++) {
         std::cin >> mtrx1[r][c];
      }
   }

   // Read second matrix

   int mtrx2_rows = mtrx1_cols;
   int mtrx2_cols = ReadInRange(1, MAX_MATRIX_2_ROWS);

   std::cout << "Matrix 2 dimensions: " << mtrx2_rows << "x" << mtrx2_cols << ".\n";

   for (int r = 0; r < mtrx2_rows; r++) {
      for (int c = 0; c < mtrx2_cols; c++) {
         std::cin >> mtrx2[r][c];
      }
   }

   // Multiply the matricies

   int mtrx_mul_rows = mtrx1_rows;
   int mtrx_mul_cols = mtrx2_cols;
   int mtrx_mul[MAX_MATRIX_1_ROWS][MAX_MATRIX_2_COLS];

   // For each element in the mul matrix
   for (int c = 0; c < mtrx_mul_cols; c++) {
      for (int r = 0; r < mtrx_mul_rows; r++) {

         // Calculate the multiplication sum
         int sum = 0;

         for (int i = 0; i < mtrx1_cols; i++) {
            sum += mtrx1[r][i] * mtrx2[i][c];
         }

         mtrx_mul[r][c] = sum;
      }
   }

   // Print Matrix

   std::cout << "The multiplied matrix of dimensions ";
   std::cout << mtrx_mul_rows << "x" << mtrx_mul_cols;
   std::cout << " is: \n";

   for (int r = 0; r < mtrx_mul_rows; r++) {
      std::cout << "| ";

      for (int c = 0; c < mtrx_mul_cols; c++) {
         std::cout << mtrx_mul[r][c] << " ";
      }

      std::cout << "|\n";
   }
}