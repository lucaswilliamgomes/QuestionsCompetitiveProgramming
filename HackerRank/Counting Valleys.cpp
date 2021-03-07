#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) {
    int ans = 0, h = 0; 
    for (int i = 0; i < steps; i++){
        if (path[i] == 'U') h++;
        if (path[i] == 'D') h--;
        if (i > 0 and h == 0 and path[i] == 'U') ans++;
    }
    return ans;
}

int main()
{
    int steps;
    string path;
    cin >> steps;
    cin >> path;

    int result = countingValleys(steps, path);

    cout << result << "\n";

    return 0;
}
