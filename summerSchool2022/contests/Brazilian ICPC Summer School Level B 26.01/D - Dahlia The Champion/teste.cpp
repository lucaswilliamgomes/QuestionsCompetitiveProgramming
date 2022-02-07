#include <bits/stdc++.h>
using namespace std;

ll mdc(ll a, ll b)
{
	return (b == 0 ? a : mdc(b, a%b));
}

ll mmc(ll a, ll b)
{
	return (a*b) / mdc(a, b);
}


int n, s,b,l;


int main()
{
    cin >> n >> s >> b >> l;

    

    return 0;
}