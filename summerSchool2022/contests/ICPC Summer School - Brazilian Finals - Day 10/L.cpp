#include <bits/stdc++.h>

using namespace std;

char words[45][45];
int cont[45][45];
int L, C, N;

bool isAnagrama(string a, string b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b ? true : false;
}

vector<vector<int>> searchWord(string word)
{
    vector<vector<int>> resp(L + 1, vector<int>(C + 1, 0));
    string aux = "";
    int tam = word.size();
    for (int i = 1; i <= L; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            // ---
            if (j + tam <= C + 1)
            {
                for (int k = 0; k < tam; k++)
                {
                    aux += words[i][j + k];
                }
                //cout << word << " " << aux << endl;
                if (isAnagrama(word, aux))
                {
                    for (int k = 0; k < tam; k++)
                    {
                        resp[i][j + k] = 1;
                    }
                }
                aux = "";
            }
            // -
            //  -
            if (j + tam <= C + 1 && i + tam <= L + 1)
            {
                for (int k = 0; k < tam; k++)
                {
                    aux += words[i + k][j + k];
                }
                if (isAnagrama(word, aux))
                {
                    for (int k = 0; k < tam; k++)
                    {
                        resp[i + k][j + k] = 1;
                    }
                }
                aux = "";
            }
            // -
            // -
            if (i + tam <= L + 1)
            {
                for (int k = 0; k < tam; k++)
                {
                    aux += words[i + k][j];
                }
                if (isAnagrama(word, aux))
                {
                    for (int k = 0; k < tam; k++)
                    {
                        resp[i + k][j] = 1;
                    }
                }
                aux = "";
            }
            //  -
            // -
            if (j - tam >= 0 && i + tam <= L + 1)
            {
                for (int k = 0; k < tam; k++)
                {
                    aux += words[i + k][j - k];
                }
                //cout << aux << " " << word << endl;
                if (isAnagrama(word, aux))
                {
                    for (int k = 0; k < tam; k++)
                    {
                        resp[i + k][j - k] = 1;
                    }
                }
                aux = "";
            }
        }
    }

    return resp;
}

int main()
{
    cin >> L >> C;
    string aux;
    int ans = 0;
    for (int i = 1; i <= L; i++)
    {

        cin >> aux;
        for (int j = 1; j <= C; j++)
        {
            words[i][j] = aux[j - 1];
        }
    }

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> aux;
        auto x = searchWord(aux);

        //cout << "chegou aq" << endl;
        for (int j = 1; j <= L; j++)
        {
            for (int k = 1; k <= C; k++)
            {
                cont[j][k] += x[j][k];
                //cout << cont[j][k] << " ";
            }
            //cout << endl;
        }
    }

    for (int j = 1; j <= L; j++)
    {
        for (int k = 1; k <= C; k++)
        {
            if (cont[j][k] > 1)
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}