#include <bits/stdc++.h>
using namespace std;

int find_not_prime(int n);

int solve(int n) {
    for (int m = 1; m <= 10e3; m++) {
        if (find_not_prime(n*m+1)) return m;
    }
    return -1;
}

int find_not_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return i;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << solve(n) << "\n";
}