#include <bits/stdc++.h>
using namespace std;

int neighbors(long long x, long long y, long long n, long long m) {
    int cnt = 4;
    if (x == 1 || x == n) cnt--;
    if (y == 1 || y == m) cnt--;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, m, x1, y1, x2, y2;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;

        int ans = min(neighbors(x1, y1, n, m), neighbors(x2, y2, n, m));
        cout << ans << "\n";
    }
}
