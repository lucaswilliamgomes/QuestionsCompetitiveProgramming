#include <bits/stdc++.h>

using namespace std;

struct Code
{
    string code;
    int cont;

    Code(string code = 0, int cont = 0) : code(code), cont(cont) {}

    bool operator<(const Code &a)
    {
        return a.cont > cont;
    }
};


int main(int argc, char const *argv[])
{

    int t, n;
    cin >> t;

    while (t--) {
        map<string, int> contas;
        vector<Code> ar;
        cin >> n;

        for (int i = 0; i < n; i++) {

            string a, b,c,d,e,f;

            cin >> a >> b >> c >> d >> e >> f;

            string aux = a + " " + b + " " + c + " " + d + " " + e + " " + f;

            contas[aux]++;
        }

        for (auto it: contas) {
            Code code;
            code.code = it.first;
            code.cont = it.second;
            cout << it.first << " " << it.second << endl;
            ar.push_back(code);
        }

        cout << ar.size() << endl;

        sort(ar.begin(), ar.end());

        for (auto it: ar) {
            cout << it.code << " " << it.cont << endl;
        }
        
    }
   

    return 0;
}
