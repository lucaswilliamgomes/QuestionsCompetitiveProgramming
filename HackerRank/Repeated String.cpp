#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long cont = 0, repeat, ans, dif;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'a') cont++;
    }
    
    repeat = floor (n / s.size());
    
    dif = n - (s.size() * repeat);

    ans = repeat * cont;

    for (int i = 0; i < dif; i++){
        if (s[i] == 'a') ans++;
    }
    
    return ans;
}

int main()
{
    string word;
    long n;
    cin >> word >> n;

    long result = repeatedString(word, n);

    cout << result << "\n";

    return 0;
}

