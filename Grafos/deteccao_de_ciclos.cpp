bool dfs(int u)
{
    if (visited[u])
        return false;

    visited[u] = true;

    for (auto v : adj[u])
    {
        if (visited[v] and v != u)
            return true;

        if (dfs(v))
            return true;
    }

    return false;
}