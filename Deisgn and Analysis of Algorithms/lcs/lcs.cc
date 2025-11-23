#include <iostream>
#include <vector>
#include <string>
#include <string_view>

using namespace std;

int lcs(string_view X, string_view Y)
{
   vector<vector<int>> L(X.length() + 1, vector<int>(Y.length() + 1, 0));

   for (int i = 0; i <= X.length(); i++)
   {
      for (int j = 0; j <= Y.length(); j++)
      {
         if (i == 0 || j == 0)
            L[i][j] = 0;
         else if (X[i - 1] == Y[j - 1])
            L[i][j] = L[i - 1][j - 1] + 1;
         else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);
      }
   }

   return L[X.length()][Y.length()];
}

int main()
{
   string X = "AGGTAB", Y = "GXTXAYB";
   cout << "Length of LCS is " << lcs(X, Y);

   return 0;
}
