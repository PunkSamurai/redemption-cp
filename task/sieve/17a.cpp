#include <bits/stdc++.h>

using namespace std;

void SieveOfEratosthenes(int n, int* prime)
{
    for(int p=2; p*p<=n; p++)
        if(prime[p])
            for (int i=p*2; i<=n; i += p)
                prime[i] = 0;
}

int main(void)
{
    int n, k, c=0;
    cin >> n >> k;
    int prime[n+1];
    prime[0] = 0;
    prime[1] = 0;
    for(int p=2; p<=n; p++)
        prime[p] = 1;
    SieveOfEratosthenes(n, prime);
    vector<int> numbers;
    for(int p=2; p<=n; p++)
        if(prime[p])
            numbers.push_back(p);
    for(auto it = numbers.begin(); it <= numbers.end()-1; it++)
        if(binary_search(numbers.begin(), numbers.end(), *it + *(it+1) + 1))
            c++;

    if(c>=k)
        cout << "YES";
    else
        cout << "NO";

}