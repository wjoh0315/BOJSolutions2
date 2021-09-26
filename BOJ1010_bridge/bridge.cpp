//https://www.acmicpc.net/problem/1010
#include <iostream>
using namespace std;

int solve(int n, int k)
{
    if (n <= 1)
        return 1;

    int *dp = new int[(n + 1) * (n + 2) / 2 + 1] { 0, };
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    int cur = 3;
    for (int i=2; i < n + 1; i++)
    {
        for (int j=0; j < i + 1; j++)
        {
            if (cur + j - i != cur)
                dp[cur + j] = dp[cur + j - i];
            if (cur + j - i - 1 >= cur - i)
                dp[cur + j] += dp[cur + j - i - 1];
            dp[cur + j] = dp[cur + j];
            if (i == n && j == k)
                return dp[cur + j];
        }
        cur += i + 1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i=0; i < t; i++)
    {
        int w, e;
        cin >> w >> e;
        cout << solve(w>e?w:e, w<e?w:e) << '\n';
    }    
}