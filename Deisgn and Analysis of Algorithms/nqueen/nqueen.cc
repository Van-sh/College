#include <iostream>
#include <vector>

using namespace std;

void printSolution(const vector<vector<int>> &board)
{
   for (int i = 0; i < board.size(); i++)
   {
      for (int j = 0; j < board.size(); j++)
      {
         cout << board[i][j] << " ";
      }
      cout << endl;
   }
}

bool isSafe(vector<vector<int>> &board, int row, int col)
{
   for (int i = 0; i < col; i++)
      if (board[row][i])
         return false;

   for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
      if (board[i][j])
         return false;

   for (int i = row, j = col; i < board.size() && j >= 0; i++, j--)
      if (board[i][j])
         return false;

   return true;
}

bool solveNQUtil(vector<vector<int>> &board, int col)
{
   if (col >= board.size())
      return true;

   for (int i = 0; i < board.size(); i++)
   {
      if (isSafe(board, i, col))
      {
         board[i][col] = 1;
         if (solveNQUtil(board, col + 1))
            return true;
         board[i][col] = 0;
      }
   }

   return false;
}

bool solveNQ(const int n)
{
   vector<vector<int>> board(n, vector<int>(n, 0));

   if (!solveNQUtil(board, 0))
   {
      cout << "Solution does not exist";
      return false;
   }

   printSolution(board);
   return true;
}

int main()
{
   int n = 4;
   solveNQ(n);
   return 0;
}
