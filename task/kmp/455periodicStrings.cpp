#include <bits/stdc++.h>
using namespace std;

const int maxn = 81;

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
            cout<<"found " << pat << "\n";
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

int main(void)
{
    int t;
    cin >> t;
    for(int it=0; it<t; it++)
    {
        char str1[maxn], str2[maxn];
        cin >> str1;
        for(int i=0; i<strlen(str1); i++)
        {
            if(strlen(str1)%(i+1) != 0)
                continue;
            str2[i] = str1[i];
            str2[i+1] = '\0';
            vector<int> ind;
            KMPSearch(str2, str1, ind);
            if(strlen(str2)*ind.size() == strlen(str1))
            {
                cout << strlen(str2) << "\n";
                break;
            }
        }
    }
}