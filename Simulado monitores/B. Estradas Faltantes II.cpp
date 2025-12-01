/*
Após descobrir quantas estradas ainda faltam para completar a malha viária de Arandu, o governador agora deseja preparar um relatório detalhado contendo todas as ligações ausentes.

Sua tarefa é listar todos os pares de cidades que não possuem estrada direta, sempre no formato a b com a < b.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX { 1510 };
bool A[MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        A[u][v] = true;
        A[v][u] = true; // Via bidirecional
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (!A[i][j]) {
                cout << i << ' ' << j << '\n';
            }
        }
    }

    return 0;
}

