#include <bits/stdc++.h>
using namespace std;

long long binExp(long long a, long long b) 
{
	int answer = 1;
	while(b>0)
    {
	    if(b%2==1)
	        answer = answer*a;
	    a = a*a;
	    b = b/2;
	    
	}
	return answer;
}

int main()
{
    long long n, m;
    cin >> n >> m;
    cout << (n>26?m:m%binExp(2,n));
}