#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll fat[100010];
	
ll fatorial (ll num){
	if (num == 0) return 1;
	else return (num * fatorial(num-1));
}	

int main (){
	ll num;
	cin >> num;
	cout << fatorial (num) << endl;	
	return 0;
}
