#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        string enemy, gregor;
        cin >> enemy >> gregor;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (gregor[i] == '1') {
                if (enemy[i] == '0') {
                    ans++;
                } else if (i > 0 && enemy[i-1] == '1') { // check left
                    ans++;
                    enemy[i-1] = '0';
                } else if (i < n-1 && enemy[i+1] == '1') { // check right
                    ans++;
                    enemy[i+1] = '0';
                }
            }
        }
        cout << ans << "\n";
    }
}