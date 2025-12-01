/*
O deus dos mares, Poseidon, está furioso. As K Ilhas Errantes (numeradas de 1 a K), rochas mágicas que vagam pelo Mar Egeu, estão causando naufrágios constantes. Para acalmar os mares, Zeus ordenou que as ilhas sejam fixadas permanentemente em uma grade divina de tamanho K x K.

Nesta grade, cada ilha deve ocupar exatamente uma célula. As células que não contêm ilhas representam o mar aberto e devem ser marcadas com o número 0.

No entanto, as ilhas possuem vontades antigas e só aceitam ser posicionadas se respeitarem certas hierarquias geográficas. Os Oráculos de Delfos consultaram os ventos e lhe entregaram dois pergaminhos sagrados:

O Pergaminho de Bóreas (Vento Norte): Contém profecias sobre qual ilha exige estar mais ao Norte (linhas superiores) que outra.

O Pergaminho de Zéfiro (Vento Oeste): Contém profecias sobre qual ilha exige estar mais ao Oeste (colunas à esquerda) que outra.

Sua missão, como o Arquiteto do Olimpo, é construir o mapa final. Se as profecias forem contraditórias (criarem um ciclo impossível), o caos reinará e você deve informar que a tarefa é impossível.

A Prioridade Divina: Como a disposição das ilhas pode ter múltiplas soluções válidas, Zeus decretou uma regra de ouro para manter a ordem: sempre que houver mais de uma ilha disponível para ser colocada em uma posição (ou seja, todas as ilhas que deveriam estar ao Norte ou a Oeste dela já foram posicionadas), você deve escolher a ilha com o menor número identificador (a mais antiga).

Entrada
A entrada é composta por diversas linhas:

A primeira linha contém um inteiro K (
2
≤
K
≤
400
), representando o número de ilhas e a dimensão da grade.

A segunda linha contém um inteiro L, representando a quantidade de restrições de latitude (linhas). As próximas L linhas contêm, cada uma, dois inteiros acima e abaixo, indicando que a ilha acima deve estar em uma linha superior à da ilha abaixo.

A linha seguinte contém um inteiro C, representando a quantidade de restrições de longitude (colunas). As próximas C linhas contêm, cada uma, dois inteiros esquerda e direita, indicando que a ilha esquerda deve estar em uma coluna à esquerda da ilha direita.

Saída
Se for possível construir o mapa, imprima K linhas. Cada linha deve conter K números inteiros separados por espaço, representando a grade. Use 0 para espaços vazios.

Se não for possível satisfazer todas as condições, imprima apenas a palavra “IMPOSSIVEL”.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> topo(int K, vector<vector<int>>& adj, vector<int>& indeg) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> order;

    for (int i = 1; i <= K; i++)
        if (indeg[i] == 0)
            pq.push(i);

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) pq.push(v);
        }
    }

    if ((int)order.size() != K) return {}; // ciclo
    return order;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    // ---------- Grafo das LINHAS ----------
    vector<vector<int>> adjL(K+1);
    vector<int> indegL(K+1, 0);

    int L;
    cin >> L;
    for (int i = 0; i < L; i++) {
        int a, b;
        cin >> a >> b;
        adjL[a].push_back(b);
        indegL[b]++;
    }

    // ---------- Grafo das COLUNAS ----------
    vector<vector<int>> adjC(K+1);
    vector<int> indegC(K+1, 0);

    int C;
    cin >> C;
    for (int i = 0; i < C; i++) {
        int a, b;
        cin >> a >> b;
        adjC[a].push_back(b);
        indegC[b]++;
    }

    // ---------- Topo sort com prioridade ----------
    vector<int> rowOrder = topo(K, adjL, indegL);
    vector<int> colOrder = topo(K, adjC, indegC);

    if (rowOrder.empty() || colOrder.empty()) {
        cout << "IMPOSSIVEL\n";
        return 0;
    }

    // ---------- Posição de cada ilha ----------
    vector<int> linha(K+1), coluna(K+1);

    for (int i = 0; i < K; i++) {
        linha[rowOrder[i]] = i;
        coluna[colOrder[i]] = i;
    }

    // ---------- Montar grade ----------
    vector<vector<int>> grid(K, vector<int>(K, 0));

    for (int i = 1; i <= K; i++)
        grid[linha[i]][coluna[i]] = i;

    // ---------- Imprimir ----------
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            cout << grid[i][j];
            if (j + 1 < K) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
