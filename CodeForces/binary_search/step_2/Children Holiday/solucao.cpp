#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<int> t, z, y, fillBalloons;

bool good(int time)
{
    vector<int> Ballons(n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        int currentTime = 0, currentBallons = 0;
        while (currentTime <= time)
        {
            currentTime += t[i] * z[i];
            if (currentTime <= time)
            {
                currentBallons += z[i];
            }
            else
                break;
            currentTime += y[i];
        }
        s += currentBallons;

        Ballons[i] = currentBallons;
        
        if (s >= m)
        {
            for (int i = 0; i < n; i++)
            {
                fillBalloons[i] = Ballons[i];
            }
        }
    }

    return s >= m;
}

int main()
{
    cin >> m >> n;
    t.resize(n);
    z.resize(n);
    y.resize(n);
    fillBalloons.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> z[i] >> y[i];
    }

    int l = 0;
    int r = 100000000;

    for (int i = 0; i < 100; i++)
    {
        int m = (l + r) / 2;
        if (good(m))
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }

    cout << r << endl;
    for (int i = 0; i < n; i++)
    {
        cout << fillBalloons[i] << " ";
    }
    cout << endl;

    return 0;
}
