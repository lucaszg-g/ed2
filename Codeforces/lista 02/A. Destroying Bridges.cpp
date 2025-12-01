#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k) {
    return (k >= n-1 ? 1 : n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
}