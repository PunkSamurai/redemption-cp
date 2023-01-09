#include <bits/stdc++.h>

using namespace std;

void compLPS(char* str, int l, int* lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < l) 
    {
        if (str[i] == str[len])   
        {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* pat, char* txt, vector<int>& ind)
{
    int l = strlen(pat);
    int n = strlen(txt);
    int lps[l];

    compLPS(pat, l, lps);
 
    int i = 0; 
    int j = 0; 
    while ((n - i) >= (l - j)) 
    {
        if (pat[j] == txt[i]) 
        {
            j++;
            i++;
        }
 
        if (j == l) 
        {
            ind.push_back(i-j);
            j = lps[j - 1];
        }
 
        else if (i < n && pat[j] != txt[i]) 
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}