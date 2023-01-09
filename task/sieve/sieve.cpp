#include <bits/stdc++.h>
using namespace std;

 
void SieveOfEratosthenes(int n, int* prime)
{
    
 
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p])
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = 0;
        }
    }
}

int main()
{
    int n = 20;
    int prime[21];
    prime[0] = 0;
    prime[1] = 0;
    for (int p=2; p<=n; p++)
        prime[p] = 1;
    cout << "Following are the prime numbers smaller than or equal to " << n << endl;
    SieveOfEratosthenes(n, prime);
    for (int p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";
    return 0;
}