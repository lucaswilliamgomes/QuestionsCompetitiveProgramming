#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    string jogador;
    cin >> N;

    int l_points = 0, k_points = 0, l_sets = 0, k_sets = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> jogador;
        if (jogador == "Kira")
        {   
            k_points++;
            if (k_points >= 4 && k_points - l_points >= 2)
            {
                k_sets++;
                k_points = 0;
                l_points = 0;
            }
        }
        else
        {
            l_points++;
            if (l_points >= 4 && l_points - k_points >= 2)
            {
                l_sets++;
                k_points = 0;
                l_points = 0;
            }
        }
    }

    if (k_sets > l_sets) {
        cout <<  "Kira eh melhor que L!!!" << endl;
    } else {
        cout <<  "L eh melhor que Kira!!!" << endl;
    }

    return 0;
}
