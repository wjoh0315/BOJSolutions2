//https://www.acmicpc.net/problem/1934
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int max = a>b?a:b;
    int min = a<b?a:b;
    if (max % min == 0)
        return min;
    return gcd(min, max%min);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a, b;
    for (int i=0; i < n; i++)
    {
        cin >> a >> b;
        cout << lcm(a, b) << '\n';
    }
}