#include <iostream>
#include <vector>
#include <string>

using namespace std;

void naiveSearch(string_view txt, string_view pat)
{
   for (int i = 0; i <= txt.length() - pat.length(); i++)
   {
      int j;
      for (j = 0; j < pat.length(); j++)
         if (txt[i + j] != pat[j])
            break;

      if (j == pat.length())
         cout << "Pattern found at index " << i << endl;
   }
}

void rabinKarp(string_view txt, string_view pat, int q)
{
   const int d = 256;

   int p = 0, t = 0, h = 1;

   for (int i = 0; i < pat.length() - 1; i++)
      h = (h * d) % q;

   for (int i = 0; i < pat.length(); i++)
   {
      p = (d * p + pat[i]) % q;
      t = (d * t + txt[i]) % q;
   }

   for (int i = 0; i <= txt.length() - pat.length(); i++)
   {
      if (p == t)
      {
         int j;
         for (j = 0; j < pat.length(); j++)
            if (txt[i + j] != pat[j])
               break;

         if (j == pat.length())
            cout << "Pattern found at index " << i << endl;
      }

      if (i < txt.length() - pat.length())
      {
         t = (d * (t - txt[i] * h) + txt[i + pat.length()]) % q;
         if (t < 0)
            t += q;
      }
   }
}

void computeLPS(string_view pat, vector<int> &lps)
{
   int len = 0;
   lps[0] = 0;
   int i = 1;
   while (i < pat.size())
   {
      if (pat[i] == pat[len])
      {
         len++;
         lps[i] = len;
         i++;
      }
      else
      {
         if (len != 0)
            len = lps[len - 1];
         else
            lps[i++] = 0;
      }
   }
}

void KMPSearch(string_view txt, string_view pat)
{
   vector<int> lps(pat.length(), 0);
   computeLPS(pat, lps);

   int i = 0, j = 0;
   while (i < txt.length())
   {
      if (pat[j] == txt[i])
         i++, j++;

      if (j == pat.length())
      {
         cout << "Pattern found at index " << i - j << endl;
         j = lps[j - 1];
      }
      else if (i < txt.length() && pat[j] != txt[i])
      {
         if (j != 0)
            j = lps[j - 1];
         else
            i++;
      }
   }
}

int main()
{
   string txt = "AABAACAADAABAABA";
   string pat = "AABA";

   cout << "Naive Search:\n";
   naiveSearch(txt, pat);

   cout << "\nRabin-Karp:\n";
   rabinKarp(txt, pat, 101);

   cout << "\nKMP Algorithm:\n";
   KMPSearch(txt, pat);
   return 0;
}
