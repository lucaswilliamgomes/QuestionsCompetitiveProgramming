#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> palavras;
vector<int> ans;

bool valid(char letra, vector<string> words) {
    for(auto it: words) {
        if (letra == it[0]) return true;
    }
    return false;
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int m;
        cin >> m;
        palavras.resize(m);
        ans.resize(m);
        for (int i = 0; i < m; i++)
        {
            int k;
            string ex;
            cin >> k;
            palavras[i].resize(k);
            for (int j = 0; j < k; j++)
            {
                cin >> palavras[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            if (valid((char)(i + 'A'), palavras[]))
        }

    }

    return 0;
}

// {
//     Ac Bc,
//     Ab Bb Cb,
//     Aa Ba Ca Da,
//     Ad
// }

// {
//     a 1x 2x 3x 4x
//     b 1x 2x 3x
//     c 2x 3x
//     d 3x
// }
