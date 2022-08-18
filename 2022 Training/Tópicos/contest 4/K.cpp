#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string aux;
        list<char> open;
        bool ans = true;

        cin >> aux;
        for (int i = 0; i < aux.size(); i++)
        {
            if (aux[i] == '(' || aux[i] == '[' || aux[i] == '{')
            {
                open.push_back(aux[i]);
            }
            else if (aux[i] == ')' || aux[i] == ']' || aux[i] == '}')
            {
                if (open.size()) {
                    if (open.back() == '(' && aux[i] == ')' ||
                        open.back() == '[' && aux[i] == ']' ||
                        open.back() == '{' && aux[i] == '}') {
                            open.pop_back();
                    } else {
                        ans = false;
                    }
                } else {
                    ans = false;
                }
            }
        }

        if (open.size()) {
            ans = false;
        }

        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
