#include <bits/stdc++.h>

using namespace std;

void SieveOfEratosthenes(int n, int* prime)
{
    for(int p=2; p<=n; p++)
        if(prime[p]>0)
            for (int i=p*2; i<=n; i += p)
                prime[i]--;
}

int main(void)
{
    int n, c=0;
    cin >> n;
    int prime[n+1];
    prime[0] = 0;
    prime[1] = 0;
    for(int p=2; p<=n; p++)
        prime[p] = 1;
    SieveOfEratosthenes(n, prime);
    for(int i=0; i<=n; i++)
        if(prime[i] == -1)
            c++;
    cout << c;

}