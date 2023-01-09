#include <iostream>
using namespace std;

int binExp(int a, int b) 
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
    cout << binExp(2, 5);
}