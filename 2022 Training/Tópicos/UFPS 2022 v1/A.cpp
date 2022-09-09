#include <iostream>
using namespace std;
#define MAX_N 10010
int N; // Number of the places want to visit
           // Next distan array will give Minimum distance through all the position
int distan[MAX_N][MAX_N];
int completed_visit = (1 << N) - 1;
int DP[4 * MAX_N][MAX_N];
int TSP(int mark, int position)
{
    if (mark == completed_visit)
    { // Initially checking whether all
      // the places are visited or not
        return distan[position][0];
    }
    if (DP[mark][position] != -1)
    {
        return DP[mark][position];
    }

    int answer = INT32_MAX;

    for (int city = 0; city < N; city++)
    {
        if ((mark & (1 << city)) == 0)
        {
            int newAnswer = distan[position][city] + TSP(mark | (1 << city), city);
            answer = min(answer, newAnswer);
        }
    }
    return DP[mark][position] = answer;
}
int main()
{
    int m, x;
    cin >> N >> m >> x;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        distan[a][b] = c;
    }

    for (int i = 0; i < (1 << N); i++)
    {
        for (int j = 0; j < N; j++)
        {
            DP[i][j] = -1;
        }
    }
    cout << "Minimum Distance Travelled by you is " << TSP(1, 0);
    return 0;
}