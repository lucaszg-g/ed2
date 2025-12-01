#include <bits/stdc++.h>
using namespace std;

int connected_components(int N)
{
    visited.reset();

    int count = 0;

    for (int u = 1; u <= N; ++u)
    {
        if (not visited[u])
        {
            cout << "Component " << ++count << ":";
            dfs(u);
            cout << '\n';
        }
    }

    return count;
}

void dfs(int u)
{
    if (visited[u])
        return;

    visited[u] = true;

    cout << ' ' << u;

    for (auto v : adj[u])
        dfs(v);
}