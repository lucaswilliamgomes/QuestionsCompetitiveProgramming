#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

// ax + by = c
bool isPossible(int a, int b, int c)
{
    return (c%gcd(a,b) == 0);
}
 
//driver function
int main()
{
    // First example
    int a = 3, b = 6, c = 9;
    isPossible(a, b, c)? cout << "Possible\n" :
                        cout << "Not Possible\n";
 
    // Second example
    a = 3, b = 6, c = 8;
    isPossible(a, b, c)? cout << "Possible\n" :
                       cout << "Not Possible\n";
 
    // Third example
    a = 2, b = 5, c = 1;
    isPossible(a, b, c)? cout << "Possible\n" :
                       cout << "Not Possible\n";
 
    return 0;
}

