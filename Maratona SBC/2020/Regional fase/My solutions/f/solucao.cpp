#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 100010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;

string entrada;
int gl = 0, pl = 0, gr = 0, pr = 0;
char vez = 'l';

void result()
{
    if (gl >= 2 or gr >= 2)
    {
        if (gl >= 2)
        {
            cout << gl << " (winner) - " << gr << endl;
        }
        else
        {
            cout << gl << " - " << gr << " (winner)" << endl;
        }
        return;
    }

    if (vez == 'l')
    {
        cout << gl << " (" << pl << "*) - " << gr << " (" << pr << ")" << endl;
    }
    else
    {
        cout << gl << " (" << pl << ") - " << gr << " (" << pr << "*)" << endl;
    }
}

int main(int argc, char const *argv[])
{

    cin >> entrada;
    for (int i = 0; i < entrada.size(); i++)
    {
        if (entrada[i] != 'Q')
        {
            if (entrada[i] == 'S')
            {
                if (vez == 'l')
                {
                    pl++;
                }
                else
                {
                    pr++;
                }

                // Verifica a pontuação
                if (pl >= 5 or pr >= 5)
                {
                    if (pl - pr >= 2 or pl == 10)
                    {
                        gl++;
                        pl = 0;
                        pr = 0;
                        vez = 'l';
                    }
                    else if (pr - pl >= 2 or pr == 10)
                    {
                        gr++;
                        pr = 0;
                        pl = 0;
                        vez = 'r';
                    }
                }
            }
            else
            {
                if (vez == 'l')
                {
                    pr++;
                    vez = 'r';
                }
                else
                {
                    pl++;
                    vez = 'l';
                }

                // Verifica a pontuação
                if (pl >= 5 or pr >= 5)
                {
                    if (pl - pr >= 2 or pl == 10)
                    {
                        gl++;
                        pl = 0;
                        pr = 0;
                        vez = 'l';
                    }
                    else if (pr - pl >= 2 or pr == 10)
                    {
                        gr++;
                        pr = 0;
                        pl = 0;
                        vez = 'r';
                    }
                }
            }
        }
        else
        {
            result();
        }
    }

    return 0;
}