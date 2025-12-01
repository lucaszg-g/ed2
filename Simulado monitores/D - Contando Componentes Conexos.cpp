/*
Cientistas estão estudando a conectividade de redes representadas por grafos. Dado um grafo simples e não direcionado com N vértices numerados de 1 a N e M arestas numeradas de 1 a M, eles desejam saber quantos componentes conexos ele possui. A aresta i conecta os vértices 
u
i
 e 
v
i
.

Uma componente conexa é um subgrafo no qual todos os seus vértices são alcançáveis entre si.

Notas
Um grafo simples e não direcionado é um grafo onde as arestas não possuem direção e não existem laços ou arestas múltiplas.
Um grafo é simples se e somente se não possui auto-laços (arestas de um vértice para ele mesmo) nem arestas duplicadas.
Um subgrafo é formado por um subconjunto de vértices e/ou arestas do grafo original.
Um grafo é conexo se e somente se é possível viajar entre qualquer par de vértices usando as arestas disponíveis.
Uma componente conexa é um subgrafo conexo maximal, ou seja, que não está contido em nenhum subgrafo conexo maior.

*/

#include <bits/stdc++.h>
using namespace std;
const int MAX { 200010 };

bitset<MAX> visited;
vector<int> adj[MAX];

void dfs(int u)
{
    if (visited[u])
        return;

    visited[u] = true;

    for (auto v : adj[u])
        dfs(v);
}

int connected_components(int N)
{
    visited.reset();

    int count = 0;

    for (int u = 1; u <= N; ++u)
    {
        if (not visited[u])
        {
            dfs(u);
            count++;
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u); // Grafo não direcionado
    }

    int num_components = connected_components(N);
    cout << num_components << '\n';

    return 0;
}