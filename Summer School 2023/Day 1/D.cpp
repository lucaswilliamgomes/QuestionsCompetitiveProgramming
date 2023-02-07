#include<bits/stdc++.h>
using namespace std;

template <class T>

vector<int> ZFunc(const vector<T> &v) {
  vector<int> z(v.size(), 0);
  int n = (int) v.size(), a = 0, b = 0;
  if (!z.empty()) z[0] = n;
  for (int i = 1; i < n; i++) {
    int end = i; if (i < b) end = min(i + z[i - a], b);
    while(end < n && v[end] == v[end - i]) ++end;
    z[i] = end - i; if(end > b) a = i, b = end;
  }
  return z;
}
 

int main()
{
    string text_;
    cin >> text_;
    int ans = 1;

    int tam = text_.size();

    vector<char> text;
    vector<int> divisors;

    for (int i = 2; i * i <= tam; i++) {
        if (tam % i == 0) {
            if (i * i == tam) {
                divisors.push_back(i);
                continue;
            } 
            divisors.push_back(i);
            divisors.push_back(tam / i);
        }
    }

    // for (int i = 0; i < divisors.size(); i++) {
    //     cout << divisors[i] << " ";

    // }

    // cout << endl;


    for (int i = 0; i < text_.size(); i++) {
        text.push_back(text_[i]);
    }

    vector<int> z = ZFunc(text);

    // for (int i = 0; i < z.size(); i++) {
    //     cout << z[i] << " ";
    // }

    // cout << endl;

    if (z[1] == tam-1) ans += tam;

    for (auto div: divisors) {
        bool flag = true;

        for (int i = div; i < z.size(); i+=div) {
            if (z[i] < div) flag = false;
        }

        if (flag) ans += tam;
    } 

    cout << ans << endl;

    return 0;
}