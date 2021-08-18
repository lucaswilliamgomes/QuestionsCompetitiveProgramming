// Tentativa depois da prova
// errada 
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{

    vector<pair<int, int>> data;
    int respondidos[110];
    int amigos[110];
    int tempo = 0;

    int n, x;
    char t;

    for (int i = 0; i < 110; i++)
    {
        respondidos[i] = -1;
        amigos[i] = -1;
    }

    cin >> n;
    while (n--)
    {
        cin >> t >> x;
        if (t == 'R')
        {
            if (amigos[x] == -1)
            {
                data.emplace_back(x, tempo);
                amigos[x] = 1;
            }
            else
            {
                for (pair<int, int> it : data)
                {
                    if (it.first == x)
                    {
                        it.second = tempo;
                        respondidos[x] = -1;
                    }
                }
            }
            tempo++;
        }
        else if (t == 'E')
        {
            for (pair<int, int> it : data)
            {
                if (it.first == x)
                {
                    it.second = tempo - it.second;
                    //cout << tempo - it.second << endl;
                    //cout << "tempo amigo " << amigo << " " << it.second << endl;
                    respondidos[x] = 1;
                }
                break;
            }
            tempo++;
        }
        else if (t == 'T')
        {
            tempo += x;
        }
    }

    for (pair<int, int> it : data)
    {
        if (respondidos[it.first] == 1)
        {
            cout << it.first << " " << it.second << endl;
        }
        else
        {
            cout << it.first << " " << -1 << endl;
        }
    }

    return 0;
}
