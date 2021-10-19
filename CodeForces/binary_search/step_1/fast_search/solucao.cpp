#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

vector<int> arr;
int N, K;

int binary_search_r(int value, int l, int r)
{

    while (r > l + 1)
    {
        int m = (l + r) / 2;
        if (arr[m] <= value)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    return r;
}

int binary_search_l(int value, int l, int r)
{
    while (r > l + 1)
    {
        int m = (l + r) / 2;
        if (arr[m] < value) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

int main(int argc, char const *argv[])
{
    cin >> N;
    int aux;
    arr.push_back(-INT_MAX);
    for (int i = 0; i < N; i++)
    {
        cin >> aux;
        arr.push_back(aux);
    }
    arr.push_back(INT_MAX);

    sort(arr.begin(), arr.end());
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // cout << endl;

    cin >> K;

    int a, b;
    while (K--)
    {
        cin >> a >> b;
        //cout << binary_search_r(b, 0, N + 1) << " " << binary_search_l(a, 0, N + 1) << "  ";
        cout << binary_search_r(b, 0, N + 1) - binary_search_l(a, 0, N + 1) - 1 << " ";
    }
    cout << endl;

    return 0;
}
