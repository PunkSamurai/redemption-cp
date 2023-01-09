#include <bits/stdc++.h>
#define mod 10000007;
using namespace std;

long long binExpMod(long long a, long long b) 
{
	long long answer = 1;
	while(b>0)
    {
	    if(b%2==1)
	        answer = (answer*a)%mod;
	    a = (a*a)%mod;
	    b = b/2;
	    
	}
	return answer;
}

int main()
{
    long long int n, k;
    while(true)
    {
        cin >> n >> k;
        if(n==0 && k==0)
            return 0;
        else
        {
            long long int s1, s2, s3, s4;
            s1 = (2 * binExpMod(n-1,n-1) ) % mod;
            s2 = (2 * binExpMod(n-1,k) ) % mod;
            s3 = binExpMod(n,k);
            s4 = binExpMod(n,n);
            long long int res = (s1 + s2 +s3 + s4) % mod;
            cout << res << "\n";
        }
    }
}