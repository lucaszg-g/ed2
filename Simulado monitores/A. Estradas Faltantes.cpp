/* 
O estado de Arandu possui N cidades, numeradas de 1 a N. O governador deseja modernizar a infraestrutura e sonha com uma rede rodoviária totalmente completa, onde toda cidade esteja diretamente ligada a qualquer outra cidade.

No entanto, ele percebeu que apenas algumas estradas já existem. Para planejar corretamente os próximos investimentos, ele precisa saber quantas ligações diretas ainda estão faltando.

Dadas as cidades e as estradas já construídas, e sabendo que são estradas de mão dupla (bidirecionais), determine quantas possíveis conexões entre pares de cidades ainda não existem.
*/

#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<ii> adj[N + 1];

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, 1);
        adj[v].emplace_back(u, 1);
    }

    int total_connections = N * (N - 1) / 2;
    int existing_connections = M;
    int missing_connections = total_connections - existing_connections;

    cout << missing_connections << '\n';
    

    

    return 0;
}