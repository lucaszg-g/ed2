#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int bfs(int sx, int sy, vector<string>& grid) {
    int M = grid.size(), N = grid[0].size();
    vector<vector<int>> dist(M, vector<int>(N, -1)); 
    queue<ii> q;

    dist[sx][sy] = 0;
    q.push({sx, sy});

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front(); 
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (grid[nx][ny] != '.' || dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});

            // Checa saída: borda e não é o início
            if ((nx != sx || ny != sy) &&
                (nx == 0 || nx == M-1 || ny == 0 || ny == N-1)) {
                return dist[nx][ny];
            }
        }
    }

    return -1; // sem saída
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<string> grid(M);
    for (int i = 0; i < M; i++) {
        cin >> grid[i];
    }

    int sx, sy;
    cin >> sx >> sy;  // posição inicial

    int result = bfs(sx, sy, grid);
    cout << result << "\n";

    return 0;
}
