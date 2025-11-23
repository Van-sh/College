#include <vector>
#include <iostream>

std::vector<std::vector<int>> add(const std::vector<std::vector<int>> &A, const std::vector<std::vector<int>> &B)
{
   int n = A.size();
   std::vector<std::vector<int>> C(n, std::vector<int>(n));
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         C[i][j] = A[i][j] + B[i][j];
      }
   }
   return C;
}

std::vector<std::vector<int>> sub(const std::vector<std::vector<int>> &A, const std::vector<std::vector<int>> &B)
{
   int n = A.size();
   std::vector<std::vector<int>> C(n, std::vector<int>(n));
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         C[i][j] = A[i][j] - B[i][j];
      }
   }
   return C;
}

std::vector<std::vector<int>> strassen(const std::vector<std::vector<int>> &A, const std::vector<std::vector<int>> &B)
{

   if (A.size() == 1)
   {
      return {{A[0][0] * B[0][0]}};
   }

   int k = A.size() / 2;
   std::vector<std::vector<int>> A11(k, std::vector<int>(k));
   std::vector<std::vector<int>> A12(k, std::vector<int>(k));
   std::vector<std::vector<int>> A21(k, std::vector<int>(k));
   std::vector<std::vector<int>> A22(k, std::vector<int>(k));

   std::vector<std::vector<int>> B11(k, std::vector<int>(k));
   std::vector<std::vector<int>> B12(k, std::vector<int>(k));
   std::vector<std::vector<int>> B21(k, std::vector<int>(k));
   std::vector<std::vector<int>> B22(k, std::vector<int>(k));

   for (int i = 0; i < k; i++)
   {
      for (int j = 0; j < k; j++)
      {
         A11[i][j] = A[i][j];
         A12[i][j] = A[i][j + k];
         A21[i][j] = A[i + k][j];
         A22[i][j] = A[i + k][j + k];

         B11[i][j] = B[i][j];
         B12[i][j] = B[i][j + k];
         B21[i][j] = B[i + k][j];
         B22[i][j] = B[i + k][j + k];
      }
   }

   std::vector<std::vector<int>> M1 = strassen(add(A11, A22), add(B11, B22));
   std::vector<std::vector<int>> M2 = strassen(add(A21, A22), B11);
   std::vector<std::vector<int>> M3 = strassen(A11, sub(B12, B22));
   std::vector<std::vector<int>> M4 = strassen(A22, sub(B21, B11));
   std::vector<std::vector<int>> M5 = strassen(add(A11, A12), B22);
   std::vector<std::vector<int>> M6 = strassen(sub(A21, A11), add(B11, B12));
   std::vector<std::vector<int>> M7 = strassen(sub(A12, A22), add(B21, B22));

   std::vector<std::vector<int>> C11 = add(sub(add(M1, M4), M5), M7);
   std::vector<std::vector<int>> C12 = add(M3, M5);
   std::vector<std::vector<int>> C21 = add(M2, M4);
   std::vector<std::vector<int>> C22 = add(sub(add(M1, M3), M2), M6);

   std::vector<std::vector<int>> C(A.size(), std::vector<int>(A.size()));
   for (int i = 0; i < k; i++)
   {
      for (int j = 0; j < k; j++)
      {
         C[i][j] = C11[i][j];
         C[i][j + k] = C12[i][j];
         C[i + k][j] = C21[i][j];
         C[i + k][j + k] = C22[i][j];
      }
   }

   return C;
}

void printMatrix(const std::vector<std::vector<int>> &matrix)
{
   for (const auto &row : matrix)
   {
      for (int val : row)
      {
         std::cout << val << "\t";
      }
      std::cout << "\n";
   }
}

int main()
{
   int n;
   std::cout << "Enter matrix size (power of 2): ";
   std::cin >> n;

   std::vector<std::vector<int>> A(n, std::vector<int>(n));
   std::vector<std::vector<int>> B(n, std::vector<int>(n));

   std::cout << "Enter elements of Matrix A:" << "\n";
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         std::cin >> A[i][j];
      }
   }

   std::cout << "Enter elements of Matrix B:" << "\n";
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         std::cin >> B[i][j];
      }
   }

   std::vector<std::vector<int>> C = strassen(A, B);

   std::cout << "Resultant Matrix:" << "\n";
   printMatrix(C);
}
